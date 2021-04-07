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
#include<stdlib.h>
#include <pthread.h>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;
/*
person[i].cv->notify()
to enter the elevator.
elevator controllerın içinde bir elevator'ım var.
sadece elevator controllerda kosullari kontrol 
ediyorum. eger  uygunsa elevator'in icine aliyorum.

Destination queue person'ın nerede olduguna gore
ve nereye gitmek istedigine gore degisiyor.

elevator controllerda request gelene kadar wait
yapıyorum. elevator controller'de uygun istek
gelmedigi surece person waitliyor.

*/


enum states {IDLE, UP, DOWN};

class Person :public Monitor 
{

    int id;
    int weight;
    int initial;
    int destination;
    int priority;

    bool requestIsTaken;

public:
    Person(int id, int weight, int initial, int destination, int priority) {
        this->id = id;
        this->weight = weight;
        this->initial = initial;
        this->destination = destination;
        this->priority = priority;
        this->requestIsTaken = false;
    }

    int getInitial(){
        return this->initial;
    }

    int getDestination(){
        return this->destination;
    }

    bool getRequestIsTaken(){
        __synchronized__;
        return this->requestIsTaken;
    }
    //when request is on the destination queue.
    void setRequestIsTaken(){
        this->requestIsTaken = true;
    }

    int getID(){
        return this->id;
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
    int *peopleAtElevator;
    states state;
    vector<int> destinationQueue;
    int whichFloor;
    int servedPeople;
    int currentPerson;
    int currentWeight;

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
        this->peopleAtElevator = new int[personCapacity];
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
        __synchronized__;
        this->whichFloor += 1;
    }


    void lowerFloor(){
        __synchronized__;
        this->whichFloor -= 1;
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
    }

    vector<int> getDestinationQueue(){
        return this->destinationQueue;
    }

    void canRequestNotify(){
        this->canRequest.notify();
    }

    void canRequestWait(){
        this->canRequest.wait();
    }

    void pickUp(){

    }

    void leave(){

    }


    void printEle(){
        //__synchronized__;
        string deneme;
        vector<int> v = this->destinationQueue;
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            
            if(v.size() == 1){
                deneme += to_string(v[i]) ;
            }
            else if(i == 1){
                deneme += " " + to_string(v[i]);
            }
            else if(i == v.size()-1){
                deneme += to_string(v[i]);
            }
            else{
                string temp = to_string(v[i]) + ",";
                deneme += temp;
            }
        }
        cout << "Elevator (" << this->getState() << ", " << this->currentWeight << ", " << this->currentPerson << ", " << this->whichFloor  << " ->" << deneme << ")" << '\n' ;
        return;

    }

    // burada while ile wait yapabilirsin
    // eligible degilse beklesin

    void personRequest2(Person *person){
        __synchronized__;
        
        if(this->isEligible(person)){
            cout << "Person (" << person->getID() <<")";
            // it is not already on destinationQueue.
            vector<int>::iterator it = find(this->destinationQueue.begin(),this->destinationQueue.end(), person->getInitial());
            if(it == this->destinationQueue.end()){
                this->destinationQueue.push_back(person->getInitial());   
               // cout << "Person (" << person->getID() <<")";   
            }   
        }
    }


    void personRequest(Person* person){
        __synchronized__;
        // eligible degilse bekle
        while(!this->isEligible(person)){
            // it is not already on destinationQueue.
            this->canRequest.wait();
        }
/*         vector<int>::iterator it2 = find(this->destinationQueue.begin(),this->destinationQueue.end(), person->getInitial());
        // request atmis ve request destinationqueue'de varsa bekliyor.
        // request atmamis veya queue'de yoksa tekrar request atacak.
        while(person->getRequestIsTaken() && !(it2 == this->destinationQueue.end())){
            this->canRequest.wait();
        } */
        person->printPerson("made a request");
        this->printEle();
        person->setRequestIsTaken();
        vector<int>::iterator it = find(this->destinationQueue.begin(),this->destinationQueue.end(), person->getInitial());
        if(it == this->destinationQueue.end()){
            this->destinationQueue.push_back(person->getInitial());   
        }


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
            usleep(elevator->getIdle());
        }

        // person at floor y wants to go to floor z

        if(elevator->getDestinationQueue()[0] > elevator->getWhichFloor()){
            usleep(elevator->getTravel());
            elevator->canRequestNotify();
            elevator->upperFloor();     
        }
       // else if()

/*         if(destinationQueue[0] > x){
            elevator->canRequest.notify();
        }
        else if(destinationQueue[0] < x){
            elevator->canRequest.notify();
        }
        else{

        } */
        

        //if(destinationQueue[0] in )
    }


// keki unutma. 19.03te koydun

// kekim yandi bari odevim dokulmesin.
}


void* personThread(void *p){
    personParam *param = (personParam *) p;
    Elevator *elevator = param->elevator;
    Person *person = param->person;

    while(1){
        //elevator->personRequest(person);
        // if person requests is not accepted yet continue send request.
        // iceri girememis yani.

        elevator->personRequest(person);
   
    }


    
}


//If there is no destination in the queue it lets other threads to take control to make calls
//to the elevator, otherwise moves the elevator up/down one floor at a time with TRAVEL_TIME

// Then it checks if the current floor is an initial floor or destination floor for any of the person threads. 
// If that floor happens to be an initial floor for any person it deletes that floor from its destination queue

// and notifies the Person threads that want to enter. After notifying
// those threads it waits for IN_OUT_TIME to allow Person threads to leave/enter





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

    for(int i = 0; i < np; i++){
        personParams[i].person = &people[i];
        personParams[i].elevator = &elevator;

        pthread_create(&guysThread[i], NULL, personThread, (void *) (personParams + i));
    }

    pthread_create(&elevThread, NULL, elevatorController, (void *) &elevator);

    // TODO:

    for(int i = 0; i < np; i++){
        pthread_join(guysThread[i], NULL);
    }
    pthread_join(elevThread, NULL);
}




/*
int main2(){
    pthread_t *people;
    pthread_t *people2;
    
    cout <<" basladi" <<endl;

    

    people = new pthread_t[1];
    people2 = new pthread_t[1];
    vector<Person*> liste;
    Person *p = new Person(0);
    Person *p1  = new Person(1);
    liste.emplace_back(p);
    
    for (int i = 0; i < 1; i++){
        
        pthread_create(&people[i],NULL, personFunc, (void *) p);
        pthread_create(&people2[i],NULL, popFunc, (void *) p1);
    }

    pthread_join(people[0], NULL);
    pthread_join(people2[0], NULL);

}


*/