#include"Priest.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Priest::Priest(uint id, int x, int y, Team t):Player(id,x,y,t){
	HP = 150;
}	
int Priest::getAttackDamage() const{
	return 0;
}
int Priest::getHealPower() const{
	return 50;
}
int Priest::getMaxHP() const{
	return 150;
}
std::vector<Goal> Priest::getGoalPriorityList(){
	std::vector<Goal> v;
	v.push_back(HEAL); // return { ATTACK} da diyebiliiriz direkt
	v.push_back(TO_ALLY); 
	v.push_back(CHEST); 
	return v;
}
const std::string Priest::getClassAbbreviation() const{
	if(getTeam() == BARBARIANS){		//bu ifade de yanlis olabilir Player::getTeam() da olabilir
		return "PR";
	}
	else return "pr";

}
std::vector<Coordinate> Priest::getAttackableCoordinates(){
	//std::vector<Coordinate> v;
	//v.push_back(ATTACK); // return { ATTACK} da diyebiliiriz direkt
	//return v;
	return { } ;


}
std::vector<Coordinate> Priest::getMoveableCoordinates(){
	Coordinate right = Coordinate(1,0);
	Coordinate up = Coordinate(0,1);
	Coordinate down = Coordinate(0,-1);
	Coordinate left = Coordinate(-1,0);
	Coordinate rightup = Coordinate(1,1);
	Coordinate leftup = Coordinate(-1,1);
	Coordinate rightdown = Coordinate(1,-1);
	Coordinate leftdown = Coordinate(-1,-1);
	return {getCoord()+right, getCoord()+up, getCoord()+down, getCoord()+left,getCoord()+ rightup,getCoord()+ leftup , getCoord()+ rightdown, getCoord()+leftdown};
}
std::vector<Coordinate> Priest::getHealableCoordinates(){
	Coordinate right = Coordinate(1,0);
	Coordinate up = Coordinate(0,1);
	Coordinate down = Coordinate(0,-1);
	Coordinate left = Coordinate(-1,0);
	Coordinate rightup = Coordinate(1,1);
	Coordinate leftup = Coordinate(-1,1);
	Coordinate rightdown = Coordinate(1,-1);
	Coordinate leftdown = Coordinate(-1,-1);
	return {getCoord()+right, getCoord()+up, getCoord()+down, getCoord()+left,getCoord()+ rightup,getCoord()+ leftup , getCoord()+ rightdown, getCoord()+leftdown};
}