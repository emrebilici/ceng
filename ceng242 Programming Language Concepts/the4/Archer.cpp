#include"Archer.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Archer::Archer(uint id, int x, int y, Team t):Player(id,x,y,t){
	HP = 200;
}			// buna gerek var mı düşünmek gerek

int Archer::getAttackDamage() const{
	return 50;
}
int Archer::getHealPower() const{
	return 0;
}
int Archer::getMaxHP() const{
	return 200;
}
std::vector<Goal> Archer::getGoalPriorityList(){
	std::vector<Goal> v;
	v.push_back(ATTACK); // return { ATTACK} da diyebiliiriz direkt
	return v;
}
const std::string Archer::getClassAbbreviation() const{
	if(getTeam() == BARBARIANS){		//bu ifade de yanlis olabilir Player::getTeam() da olabilir
		return "AR";
	}
	else return "ar";

}
std::vector<Coordinate> Archer::getAttackableCoordinates(){
	//std::vector<Coordinate> v;
	//v.push_back(ATTACK); // return { ATTACK} da diyebiliiriz direkt
	//return v;
	//Coordinate right = Coordinate(1,0);
	Coordinate right2 = Coordinate(2,0);
	//Coordinate up = Coordinate(0,1);
	Coordinate up2 = Coordinate(0,2);
	//Coordinate down = Coordinate(0,-1);
	Coordinate down2 = Coordinate(0,-2);
	//Coordinate left = Coordinate(-1,0);
	Coordinate left2 = Coordinate(-2,0);
	return { getCoord()+right2, getCoord()+up2, getCoord()+down2, getCoord()+left2 };

}
std::vector<Coordinate> Archer::getMoveableCoordinates(){
	return { } ;

}
std::vector<Coordinate> Archer::getHealableCoordinates(){
	return { } ;
}