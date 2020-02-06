#include "Car.h"
#include "Utilizer.h"
/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

Car::Car(std::string driver_name){
    this->driver_name = driver_name;
    this->performance = Utilizer::generatePerformance();
    this->head = NULL;
    this->next = NULL; 
}

Car::Car(const Car& rhs){

    driver_name=rhs.getDriverName();
    performance=rhs.getPerformance();
    next = NULL;
    Laptime* currentForRhs = rhs.head;
    Laptime* currentForThis;
    if(currentForRhs){
        while(currentForRhs->getNext()){
            currentForThis = new Laptime(currentForRhs->getLaptime());
            currentForRhs = currentForRhs->getNext();
            head = currentForThis;
        }
        
    }
    else{
        head=nullptr;
    }



}

Car:: ~Car(){
    Laptime* p(head);
    Laptime* q(nullptr);
    while (p != nullptr) {
        q = p -> getNext();
        delete p;
        p = q;
    }
}

std::string Car::getDriverName() const{
    return driver_name;

}

double Car::getPerformance() const{
    return performance;
}

void Car::addCar(Car *next){

    Car* curr = this->next;

    if(curr==next){
        return;
    }
    else{
        while(curr){
            curr = curr->next;
        }
        curr = next;
    }  
}

bool Car::operator<(const Car& rhs) const{
    int total1 = 0;
    int total2 = 0;
    Laptime* curLaptime = head;
    Laptime* rhsLaptime = rhs.head;

    while(curLaptime->getNext()){
        total1 += curLaptime->getLaptime();
        curLaptime =curLaptime->getNext();
    }
    total1+= curLaptime->getLaptime();
    while(rhsLaptime->getNext()){
        total2 += rhsLaptime->getLaptime();
        rhsLaptime = rhsLaptime->getNext();
    }
    total2 += rhsLaptime->getLaptime();
    return total1<total2;

}

bool Car::operator>(const Car& rhs) const{
    int total1 = 0;
    int total2 = 0;
    Laptime* curLaptime = head;
    Laptime* rhsLaptime = rhs.head;

    while(curLaptime->getNext()){
        total1 += curLaptime->getLaptime();
        curLaptime = curLaptime->getNext();
    }
    total1+= curLaptime->getLaptime();

    while(rhsLaptime->getNext()){
        total2 += rhsLaptime->getLaptime();
        rhsLaptime = rhsLaptime->getNext();
    }
    total2 += rhsLaptime->getLaptime();
    return total1>total2;

}


Laptime Car::operator[](const int lap) const{
    Laptime* curr = head;
    int counter = 0;
    int flag = 0;
    if(!curr){
        Laptime* don = new Laptime(0);
        return *don;
    }
    if(curr && !(curr->getNext())){
        if((lap==0)){
            return *curr;
        }
        else{
            Laptime* don = new Laptime(0);
            return *don;
        }
    }
    while(curr->getNext()){
        if(counter==lap){
            flag = 1;
            return *curr;
        }
        curr = curr->getNext();
        counter++;
    }
    if(counter == lap){
        return *curr;
    }
    if(!flag){
        Laptime* don = new Laptime(0);
        return *don;
    }
}

void Car::Lap(const Laptime& average_laptime){
    int lastlap = Utilizer::generateLaptimeVariance(getPerformance())+average_laptime.getLaptime();
    Laptime* last = new Laptime(lastlap);

    Laptime* curr = head;
    while(curr->getNext()){
        curr = curr->getNext();
    }
    curr->setNext(last);

}

std::ostream& operator<<(std::ostream& os, const Car& car){

    std::string d_Name = car.getDriverName();
    std::string driverName = d_Name.substr(d_Name.find(" ")+1,3);   // 3 is the length, find return position
    driverName[1] = driverName[1]-32; 
    driverName[2] = driverName[2]-32; 

    Laptime* cur = car.head;
    long total = 0;
    long fastCache = 999999999; 
    while(cur->getNext()){
        if(cur->getLaptime() < fastCache ){
            fastCache = cur->getLaptime();
        }
        total += cur->getLaptime();
        cur = cur->getNext();
    }
    total += cur->getLaptime();
    if(cur->getLaptime() < fastCache){
        fastCache = cur->getLaptime();
    }



    os<< driverName <<"--" << Laptime(fastCache) << "--" << cur << "--" << Laptime(total) << std::endl;
    return os;
}


