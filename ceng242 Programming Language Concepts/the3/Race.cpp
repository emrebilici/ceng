#include "Race.h"
#include "Utilizer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE 
*/

Race::Race(std::string race_name){
	this->head = NULL;
	this->race_name = race_name;
	average_laptime.setLaptime(Utilizer::generateAverageLaptime());
	//average_laptime.setLaptime(34535);
	

}
Race::Race(const Race& rhs){
	this->race_name = rhs.race_name;
	this->average_laptime.setLaptime(rhs.average_laptime.getLaptime());
	Car* cur = rhs.head;
	while(head){
		free(head);
		head = head->getNext();
	}

    Car* currentForThis;
    if(cur){
        while(cur->getNext()){
            currentForThis = new Car(cur->getDriverName());
            cur = cur->getNext();
            head = currentForThis;
        }
        
    }
    else{
        head=nullptr;
    }


}

Race::~Race(){}

std::string Race::getRaceName() const{
	return this->race_name;
}

Car* Race::getHead(){
    return this->head;
}

void Race::addCartoRace(){

}


void Race::addCartoRace(Car& car){
	Car* last = new Car(car.getDriverName());
	last->setPerformance(car.getPerformance());

    Car* curr = head;
    if(!curr){
         //curr->setNext(nullptr);
        head = last;
       //std::cout<< *last;

    }
    else{
    while(curr->getNext()!=nullptr){
        curr = curr->getNext();
    }
    curr->setNext(last);
    }

}


int Race::getNumberOfCarsinRace(){
	Car* p = this->head;
	int counter;
	while(p){
		counter++;
		p = p->getNext();
	}
	return counter;

}

void Race::goBacktoLap(int lap){

}

void Race::operator++(){

}


Car Race::operator[](const int car_in_position){
	Car* curr = head;
    int counter = 0;
    int flag = 0;
    if(!curr){
        Car* don = new Car("yok");
        return *don;
    }
    if(curr && !(curr->getNext())){
        if((car_in_position==0)){
            return *curr;
        }
    }
    while(curr->getNext()){
        if(counter==car_in_position){
            flag = 1;
            return *curr;
        }
        curr = curr->getNext();
        counter++;
    }
    if(counter == car_in_position){
        return *curr;
    }


}

Race& Race::operator=(const Race& rhs){
	if (this != &rhs){
        race_name = rhs.race_name;
        this->average_laptime.setLaptime(rhs.average_laptime.getLaptime());

        Car* p = head;
        //Car* q = rhs.head;
        //Car* neww = new Car();
        Car* r = rhs.head;
        while (r) {
        	p = r;
            r = r->getNext();
            p = p->getNext();
        }
    }
    return *this;

}

std::ostream& operator<<(std::ostream& os, const Race& race){
	Car* cur = race.head;
	os<< race.getRaceName() << "    "; //<< cur->getDriverName();
	return os;


}