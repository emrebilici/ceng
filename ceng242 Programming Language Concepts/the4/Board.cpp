#include"Board.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

Board::Board(uint _size, std::vector<Player*>* _players, Coordinate chest):size(_size), players(_players), chest(chest) {

}

Board::~Board(){
}

bool Board::isCoordinateInBoard(const Coordinate& c){
	Coordinate boardSize = Coordinate(((this->size)-1), ((this->size)-1));
	Coordinate zeroPoint = Coordinate(0,0);
	if((c < boardSize  || c == boardSize) && (zeroPoint < c || zeroPoint== c)) {
		true;
	}
	else{
		false;
	}
}

bool Board::isPlayerOnCoordinate(const Coordinate& c){
	if(!isCoordinateInBoard(c)){
		return false;
	}
	for(int i = 0; i< players->size() ; i++) {
		if( c == (*players)[i]->getCoord()){
			return true;
		}	
		else
		false;	
	}
}

Player* Board::operator [](const Coordinate& c) {
	if(isPlayerOnCoordinate(c)){
		for(int i = 0; i< players->size() ; i++) {
			if( c == players->at(i)->getCoord()){ //players->at(i) = (*players)[i]
				return (*players)[i];
			}
		}
	}
	else nullptr;
}

Coordinate Board::getChestCoordinates(){
	return chest;
}

void Board::printBoardwithID(){
	for(int j = 0; j < size; j++ ){
		for (int i = 0 ; i < size; i++){
			if(isPlayerOnCoordinate(Coordinate(i,j))){
				std::cout<< operator[](Coordinate(i,j))->getBoardID();
			}
			else if(isPlayerOnCoordinate(Coordinate(i,j)) == 0 && Coordinate(i,j)==getChestCoordinates() ){
				std::cout<< "Ch" ;
			}
			else{
				
				std::cout<< "__" ;
			}
			if(i!=size-1) {

				std::cout<< " " ;
			}
		}
		std::cout<<"" <<std::endl ;
	}
}


void Board::printBoardwithClass(){
	for(int j = 0; j < size; j++ ){
		for (int i = 0 ; i < size; i++){
			if(isPlayerOnCoordinate(Coordinate(i,j))){
				std::cout<< operator[](Coordinate(i,j))->getClassAbbreviation();
			}
			else if(isPlayerOnCoordinate(Coordinate(i,j)) == 0 && Coordinate(i,j)==getChestCoordinates() ){
				std::cout<< "Ch" ;
			}
			else{
				
				std::cout<< "__" ;
			}
			if(i!=size-1) {

				std::cout<< " " ;
			}
		}
		std::cout<<"" <<std::endl ;
	}
}