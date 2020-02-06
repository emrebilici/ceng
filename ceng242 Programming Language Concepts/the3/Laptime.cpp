#include "Laptime.h"
#include "Utilizer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/
Laptime::Laptime(int laptime){
    this->laptime = laptime;
    next = NULL;
}

Laptime::Laptime(const Laptime& rhs){
  /*  Laptime * cur = rhs.next;
    delete next;
    while(cur){
        next->laptime = cur->laptime;
        next->next = cur->next;
        cur = cur->next;
        next = next->next;
    }
    */
    laptime = rhs.laptime;
    next = nullptr;
}

Laptime::~Laptime(){
    
}


void Laptime::addLaptime(Laptime *next){
    this->next = next;
}

bool Laptime::operator<(const Laptime& rhs) const {
    if(rhs.laptime > this->laptime){
        return true;
    }
    else {
        return false;
    }
}

bool Laptime::operator>(const Laptime& rhs) const {
    if(rhs.laptime < laptime){
        return true;
    }
    else {
        return false;
    }
}


Laptime& Laptime::operator+(const Laptime& rhs){
    this->laptime = this->laptime + rhs.laptime;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Laptime& laptime){
    int mil = laptime.laptime;
    int min = mil / 60000;
    mil = mil - 60000*min;
    int sec = mil/1000;
    mil = mil -1000*sec;
    if(sec<10 &&  mil<10){
        os << min <<":" << "0" <<sec << "." << "00" <<mil;
    }
    else if(sec<10 &&  mil<100){
        os << min <<":" << "0" <<sec << "." << "0" <<mil;
    }
    else if(mil<100){
        if(mil<10){
            os << min <<":" << sec << "." << "00" <<mil ;
        }
        else{
        os << min <<":" << sec << "." << "0" <<mil ;
    }
    }
    else if(sec<10){
        os << min <<":" << "0" <<sec << "." << mil ;
    }
    else if(mil>=100 && sec>=10){
    os << min <<":" << sec << "." <<mil ;
    }
    return os;
}

Laptime* Laptime::getNext(){
    return this->next;
}

int Laptime::getLaptime() const{
    return this->laptime;
}


void Laptime::setNext(Laptime* nextt){
    next = nextt;
}

void Laptime::setLaptime(int lapp){
    this->laptime = lapp;
}

Laptime::Laptime(){
    laptime=0;
    next=nullptr;
}