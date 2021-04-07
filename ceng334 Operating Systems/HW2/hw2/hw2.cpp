#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include "monitor.h"
#include <list>
#include <sstream>
#include <stdlib.h>
#include <pthread.h>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h> 
#include <sched.h>

using namespace std;


enum states {IDLE, UP, DOWN};

class Person 
{

    int id;
    int weight;
    int initial;
    int destination;
    int priority;
    bool isEnter;
    bool requestIsTaken;
    bool requestDone;

public:
    Person(int id, int weight, int initial, int destination, int priority) {
        this->id = id;
        this->weight = weight;
        this->initial = initial;
        this->destination = destination;
        this->priority = priority;
        this->requestIsTaken = false;
        this->isEnter = false;
        this->requestDone = false;
    }

    int getInitial(){
        return this->initial;
    }

    int getDestination(){
        return this->destination;
    }

    bool getRequestIsTaken(){
        //__synchronized__;
        return this->requestIsTaken;
    }
    //when request is on the destination queue.
    void setRequestIsTaken(){
        this->requestIsTaken = true;
    }

    int getID(){
        return this->id;
    }

    int getWeight(){
        return this->weight;
    }

    int getPrio(){
        return this->priority;
    }

    bool getIsEnter(){
        return this->isEnter;
    }

    void setIsEnter(){
        this->isEnter = true;
    }

    string printPrio(){
        if(this->priority == 1){
            return "hp";
        }
        else {
            return "lp";
        }
    }

    void printPerson(string s){
        cout << "Person (" << this->id << ", " << this->printPrio() << ", " << this->initial << " -> " << this->destination << ", " << this->weight << ")" << " " << s << '\n';
    }

};


class Elevator:public Monitor
{

    //int id ;
    Condition canRequest, enterCV, leaveCV;
    int floorCapacity;
    int weightCapacity;
    int personCapacity;
    int numberPeople;
    unsigned int travelTime;
    unsigned int idleTime;
    unsigned int inoutTime;
    //int *peopleAtElevator;
    vector <int> peopleAtElevator;
    states state;
    vector<int> destinationQueue;
    int whichFloor;
    int servedPeople;
    int currentPerson;
    int currentWeight;
    vector<int> enterQueue;

private:
    /* data */
public:
    Elevator(int floorCapacity, int numberPeople, int weightCapacity, int personCapacity, int travelTime, int idleTime, int inoutTime): canRequest(this), enterCV(this), leaveCV(this) {
        this->floorCapacity = floorCapacity;
        this->numberPeople = numberPeople;
        this->weightCapacity = weightCapacity;
        this->personCapacity = personCapacity;
        this->travelTime = travelTime;
        this->idleTime = idleTime;
        this->inoutTime = inoutTime;
        //this->peopleAtElevator = new int[personCapacity];
        this->state = IDLE; // UP, DOWN
        this->whichFloor = 0;
        this->servedPeople = 0;
        this->currentPerson = 0;
        this->currentWeight = 0;
    }

    int getNumberPeople(){
        return this->numberPeople;
    }

    int getServedPeople(){
        return this->servedPeople;
    }

    int getWhichFloor(){
        return this->whichFloor;
    }
    
    void upperFloor(){
        //__synchronized__;
        this->whichFloor += 1;
    }


    void lowerFloor(){
        //__synchronized__;
        this->whichFloor -= 1;
    }

    void setWeight(int w){
        this->currentWeight += w;
    }

    int getCurrentWeight(){
        return this->currentWeight;
    }

    void addPerson(){
        this->currentPerson += 1;
    }

    void leftPerson(){
        this->currentPerson -= 1; 
    }

    int getCurrentPerson(){
        return this->currentPerson;
    }

    unsigned int getIdle(){
        return this->idleTime;
    }

    unsigned int getTravel(){
        return this->travelTime;
    }

    unsigned int getInOut(){
        return this->inoutTime;
    }

    void setState(states s){
        this->state = s;
    }

    string getState(){
        if(this->state == IDLE){
            return "Idle";
        }
        else if(this->state == UP){
            return "Moving-up";
        }
        else{
            return "Moving-down";
        }
    }


    bool isEmptyDestination(){
        return this->destinationQueue.empty();
    }

    void setDestinationQueue(int n){
        this->destinationQueue.push_back(n);
        sort(this->destinationQueue.begin(), this->destinationQueue.end());
    }

    void popDestinationQueue(){
        this->destinationQueue.erase(destinationQueue.begin());
    }

    vector<int> getDestinationQueue(){
        return this->destinationQueue;
    }

    void setEnterQueue(int n){
        this->enterQueue.push_back(n);
        sort(this->enterQueue.begin(), this->enterQueue.end());
    }    

    void popEnterQueue(){
        this->enterQueue.erase(this->enterQueue.begin());
    }


    void canRequestNotify(){
        this->canRequest.notifyAll();
    }

    void canRequestWait(){
        this->canRequest.wait();
    }


    void canEnterNotify(){
        this->enterCV.notifyAll();
    }

    void canEnterWait(){
        this->enterCV.wait();
    }

    void canLeaveNotify(){
        this->leaveCV.notifyAll();
    }


    void printEle(){
        string deneme;
        vector<int> v = this->destinationQueue;
        //sort(v.begin(), v.end());

        if(this->destinationQueue[0] == this->whichFloor){
            for(int i = 0; i < v.size(); i++){
                
                if(i == 0){
                    
                }
                else if(i==1){
                    deneme += " " + to_string(v[i]) ;
                }
                else{
                    deneme += "," + to_string(v[i]);
                }

            }
        }
        else{

            for(int i = 0; i < v.size(); i++){
            
            if(i == 0){
                deneme += " " + to_string(v[i]) ;
            }
            else{
                deneme += "," + to_string(v[i]);
            }

            }

        }
        cout << "Elevator (" << this->getState() << ", " << this->currentWeight << ", " << this->currentPerson << ", " << this->whichFloor  << " ->" << deneme << ")" << '\n'; 
        return;

    }



    void personRequest(Person* person){
        __synchronized__;
        // eligible degilse bekle
        while(!this->isEligible(person)){
            // it is not already on destinationQueue.
            this->canRequestWait();
        }
        vector<int>::iterator it2 = find(this->destinationQueue.begin(),this->destinationQueue.end(), person->getInitial());
        // request atmis ve request destinationqueue'de varsa bekliyor.
        // request atmamis veya queue'de yoksa tekrar request atacak.
        while(person->getRequestIsTaken() && !(it2 == this->destinationQueue.end())){
            //cout << "olmazz" << endl;
            this->canRequest.wait();
            //cout << "selammm" << endl;
        }  
        // TODO: buralari degis.
        // canrequest olan seyi canEnter yap.
        // canEnter'dan notify gelince bu whiledan ciksin.
        // ve enter fonksiyonuna gecsin.
        // bunu da person thread de yapabilirsin. sanirim. enter fonksiyonunu cagirmayi.
        // 
        //girmisse requestten cik.



        //request daha once alindiysa alma
        vector<int>::iterator it3 = find(this->enterQueue.begin(),this->enterQueue.end(), person->getInitial());
        if(it3 == this->enterQueue.end()){
            this->setEnterQueue(person->getInitial());
        }


        person->printPerson("made a request");
        person->setRequestIsTaken();
        vector<int>::iterator it = find(this->destinationQueue.begin(),this->destinationQueue.end(), person->getInitial());
        if(it == this->destinationQueue.end()){
            this->setDestinationQueue(person->getInitial());
            //sort(this->destinationQueue.begin(), this->destinationQueue.end());
            if(this->destinationQueue[0] > this->whichFloor){
                this->setState(UP);
            }
            else if(this->destinationQueue[0] < this->whichFloor){
                this->setState(DOWN);
            }
        }
        this->printEle(); 


    }


    bool isEligible(Person* person){

        if(this->state == IDLE){
            return true;
        }
        else{
            if(this->state == UP){
                // elevator is going up and person is at behind
                if(this->whichFloor > person->getInitial()){
                    return false;
                }
                // person is in front of elevator.
                else{
                    // person wants to go down.
                    if(person->getDestination() < this->whichFloor){
                        return false;
                    }
                    else{
                        return true;
                    }
                }
            }
            // going down
            else{
                // elevator is going down and person is at behind
                if(this->whichFloor < person->getInitial()){
                    return false;
                }
                // person is in front of elevator.
                else{
                    // person wants to go up.
                    if(person->getDestination() > this->whichFloor){
                        return false;
                    }
                    else{
                        return true;
                    }
                }
            }
        }
    }


    bool capacityCheck(Person* person){
        //__synchronized__;
        if((this->currentPerson >= this->personCapacity) || (this->currentWeight + person->getWeight() > this->weightCapacity) ){
            return false;
        }
        else{
            return true;
        }
    }

    void personEnter(Person* person){
        
        __synchronized__;
        //      
        //cout << "person enter ici" << person->getID() << endl;
        // kata gelene kadar bekle.
        while(person->getInitial() != this->whichFloor){
            this->enterCV.wait();
            
        }
        if (capacityCheck(person)){
            this->setWeight(person->getWeight());
            this->addPerson();
            vector<int>::iterator it = find(this->destinationQueue.begin(),this->destinationQueue.end(), person->getDestination());
            if(it == this->destinationQueue.end()){
                this->setDestinationQueue(person->getDestination());
            }
            person->printPerson("entered the elevator");
            this->peopleAtElevator.push_back(person->getID());
            person->setIsEnter();

            this->popEnterQueue();
            if(this->destinationQueue[0] > this->whichFloor){
                this->setState(UP);
            }
            else if(this->destinationQueue[0] < this->whichFloor){
                this->setState(DOWN);
            }

            this->printEle();
            this->enterCV.notifyAll();
            this->leaveCV.notifyAll();
            
            //usleep(this->inoutTime);
           // 
        }
        else{
            //usleep(this->travelTime);
            return;
        }

        //usleep(this->getInOut());
        
    }

     void personLeave(Person* person){
        __synchronized__;
       // vector<int>::iterator it = find(this->peopleAtElevator.begin(),this->peopleAtElevator.end(), person->getID());
        
        // person is not on the elevator or it is not on destination.
        // it will wait
        // person is not on the elevator it should not come to here.
        // zaten burada o person yoksa enterda takilip kaliyor. onu hallet.
        while((person->getDestination() != this->whichFloor)){
            this->leaveCV.wait();
        }

        this->setWeight(-person->getWeight());
        this->leftPerson();
        person->printPerson("has left the elevator");
        this->peopleAtElevator.erase(remove(this->peopleAtElevator.begin(), this->peopleAtElevator.end(), person->getID()), this->peopleAtElevator.end());
        this->servedPeople += 1;

        if(isEmptyDestination()){
            this->state = IDLE;
        }
        this->printEle();

        this->leaveCV.notifyAll();
        this->enterCV.notifyAll();
       // usleep(this->inoutTime);
        //this->printEle();
        
    } 

};

struct personParam
{
    Person *person;
    Elevator *elevator;
};

// template / draft code.
void* elevatorController(void* p){
    int currentFloor=0;
    Elevator * elevator = (Elevator *) p;

    // while there is unserved people, continue
    while(elevator->getServedPeople() < elevator->getNumberPeople()){
        
        // if elevator destinationQueue is empty then it is on idle state.
        // It should wait idle time. eligible ones can request.
        // if person is not eligible, at least it waits for canRequest nofitication.
        while(elevator->isEmptyDestination()){
            elevator->canRequestNotify();
            elevator->setState(IDLE);
            elevator->canLeaveNotify();
            usleep(elevator->getIdle());
        }

        // person at floor y wants to go to floor z
        if(elevator->getDestinationQueue()[0] > elevator->getWhichFloor()){
           // cout << "yukari"  << endl;
            elevator->canRequestNotify();
            elevator->setState(UP);
            usleep(elevator->getTravel());
            elevator->upperFloor();  
           //elevator->printEle();   
            
               
        }
        else if(elevator->getDestinationQueue()[0] < elevator->getWhichFloor()){
            // cout << "asagi"  << endl;
            elevator->canRequestNotify();
            elevator->setState(DOWN);
            usleep(elevator->getTravel());
            elevator->lowerFloor();  
            //elevator->printEle();           
        }
        
        if(elevator->getDestinationQueue()[0] == elevator->getWhichFloor() ){
             elevator->popDestinationQueue();
            elevator->canLeaveNotify();
           // cout << "katta: " << elevator->getWhichFloor() << endl;
            elevator->canEnterNotify();
            
            usleep(elevator->getInOut());
           
           // elevator->printEle();
            
            // girebilir diye notify gonderiyor. 
            // bu sure icinde requestin orada bekliyor.
        }

        if(elevator->isEmptyDestination()){
            elevator->setState(IDLE);
            
        }
        elevator->printEle();
        //if(destinationQueue[0] in )
    }


// keki unutma. 19.03te koydun

// kekim yandi bari odevim dokulmesin.
}


void* personThread(void *p){
    personParam *param = (personParam *) p;
    Elevator *elevator = param->elevator;
    Person *person = param->person;

   
        //elevator->personRequest(person);
        // if person requests is not accepted yet continue send request.
        // iceri girememis yani.
    while(elevator->getServedPeople() < elevator->getNumberPeople()){

        // if its request has already taken and its on the queue it will wait inside function.
        // otherwise it will request directly.
 
        elevator->personRequest(person);
        
        

        elevator->personEnter(person);
        // enterda takili kaldi. enterin waitinde bekliyor.
        // ama tekrar request atmasi gerekiyor
        // usleep(elevator->getInOut());

        if(person->getIsEnter()){
            elevator->personLeave(person);
            break;
        }
            
        //break;
       

    }
        
}



int main(int argc,char* argv[]){
    
    string fileName = argv[1];

    //num_floors (ND), num_people(NP ), weight_capacity(WC), 
    // person_capacity(PC), TRAVEL_TIME(TT), IDLE_TIME(IT) and IN_OUT_TIME (IOT).
    int nd,np,wc,pc,tt,it,iot;
    // weight_person(WP ), initial_floor(IF ), destination_floor(DF ) and priority(P).
    int wp,ifl,df,p;

    vector<Person> people;
    personParam *personParams;

    pthread_t elevThread, *guysThread;

    fstream newfile;
    newfile.open(fileName,ios::in); 

    if(newfile.is_open()){  
        int lineCounter = 1;
        string line;
        while(getline(newfile, line)){ 
            
            istringstream iss(line);
            if (lineCounter == 1){
                iss >> nd >> np >> wc >> pc >> tt>> it >> iot;
            
            }
            else{
                iss >> wp >> ifl >> df >> p ;
                Person ppp(lineCounter-2, wp, ifl, df, p);
                people.push_back(ppp);
            }
            lineCounter++;
            
        }
        newfile.close(); 
    }

    Elevator elevator(nd, np, wc, pc, tt, it, iot);
    guysThread = new pthread_t[np];
    personParams = new personParam[np];


    pthread_attr_t tattr;
    sched_param param;
    
    for(int i = 0; i < np; i++){
        personParams[i].person = &people[i];
        personParams[i].elevator = &elevator;
        
        pthread_attr_init (&tattr);
        pthread_attr_getschedparam (&tattr, &param);
        if(people[i].getPrio()==1){
            param.sched_priority = 20;
        }
        else{
            param.sched_priority = 1;
        }
        
        pthread_attr_setschedparam (&tattr, &param);
        pthread_create(&guysThread[i], &tattr, personThread, (void *) (personParams + i));
    }

    pthread_create(&elevThread, NULL, elevatorController, (void *) &elevator);

    // TODO:

    for(int i = 0; i < np; i++){
        pthread_join(guysThread[i], NULL);
    }
    pthread_join(elevThread, NULL);
}
