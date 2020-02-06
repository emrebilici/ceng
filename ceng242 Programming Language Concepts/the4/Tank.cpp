#include"Tank.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Tank::Tank(uint id, int x, int y, Team t):Player(id,x,y,t){
	HP = 1000;
}	
int Tank::getAttackDamage() const{
	return 25;
}
int Tank::getHealPower() const{
	return 0;
}
int Tank::getMaxHP() const{
	return 1000;
}
std::vector<Goal> Tank::getGoalPriorityList(){
	std::vector<Goal> v;
	v.push_back(TO_ENEMY); // return { ATTACK} da diyebiliiriz direkt
	v.push_back(ATTACK); 
	v.push_back(CHEST); 
	return v;
}
const std::string Tank::getClassAbbreviation() const{
	if(getTeam() == BARBARIANS){		//bu ifade de yanlis olabilir Player::getTeam() da olabilir
		return "TA";
	}
	else return "ta";

}
std::vector<Coordinate> Tank::getAttackableCoordinates(){
	//std::vector<Coordinate> v;
	//v.push_back(ATTACK); // return { ATTACK} da diyebiliiriz direkt
	//return v;
	Coordinate right = Coordinate(1,0);
	Coordinate up = Coordinate(0,1);
	Coordinate down = Coordinate(0,-1);
	Coordinate left = Coordinate(-1,0);

	return {getCoord()+right, getCoord()+up, getCoord()+down, getCoord()+left};


}
std::vector<Coordinate> Tank::getMoveableCoordinates(){
	Coordinate right = Coordinate(1,0);
	Coordinate up = Coordinate(0,1);
	Coordinate down = Coordinate(0,-1);
	Coordinate left = Coordinate(-1,0);

	return {getCoord()+right, getCoord()+up, getCoord()+down, getCoord()+left};
}
std::vector<Coordinate> Tank::getHealableCoordinates(){

	return { } ;
}