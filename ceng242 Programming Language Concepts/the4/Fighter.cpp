#include"Fighter.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Fighter::Fighter(uint id, int x, int y, Team t):Player(id,x,y,t){
	HP = 400;
}	
int Fighter::getAttackDamage() const{
	return 100;
}
int Fighter::getHealPower() const{
	return 0;
}
int Fighter::getMaxHP() const{
	return 400;
}
std::vector<Goal> Fighter::getGoalPriorityList(){
	std::vector<Goal> v;
	v.push_back(ATTACK); // return { ATTACK} da diyebiliiriz direkt
	v.push_back(TO_ENEMY); 
	v.push_back(CHEST); 
	return v;
}
const std::string Fighter::getClassAbbreviation() const{
	if(getTeam() == BARBARIANS){		//bu ifade de yanlis olabilir Player::getTeam() da olabilir
		return "FI";
	}
	else return "fi";

}
std::vector<Coordinate> Fighter::getAttackableCoordinates(){
	//std::vector<Coordinate> v;
	//v.push_back(ATTACK); // return { ATTACK} da diyebiliiriz direkt
	//return v;
	Coordinate right = Coordinate(1,0);
	Coordinate up = Coordinate(0,1);
	Coordinate down = Coordinate(0,-1);
	Coordinate left = Coordinate(-1,0);
	return {getCoord()+right, getCoord()+up, getCoord()+down, getCoord()+left  };

}
std::vector<Coordinate> Fighter::getMoveableCoordinates(){
	Coordinate right = Coordinate(1,0);
	Coordinate up = Coordinate(0,1);
	Coordinate down = Coordinate(0,-1);
	Coordinate left = Coordinate(-1,0);
	return {getCoord()+right, getCoord()+up, getCoord()+down, getCoord()+left  };


}
std::vector<Coordinate> Fighter::getHealableCoordinates(){
	return { } ;
}