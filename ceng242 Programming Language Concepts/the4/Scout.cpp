#include"Scout.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Scout::Scout(uint id, int x, int y, Team t):Player(id,x,y,t){
	HP = 125;
}	
int Scout::getAttackDamage() const{
	return 25;
}
int Scout::getHealPower() const{
	return 0;
}
int Scout::getMaxHP() const{
	return 125;
}
std::vector<Goal> Scout::getGoalPriorityList(){
	std::vector<Goal> v;
	v.push_back(CHEST); // return { ATTACK} da diyebiliiriz direkt
	v.push_back(TO_ALLY); 
	v.push_back(ATTACK); 
	return v;
}
const std::string Scout::getClassAbbreviation() const{
	if(getTeam() == BARBARIANS){		//bu ifade de yanlis olabilir Player::getTeam() da olabilir
		return "SC";
	}
	else return "sc";

}
std::vector<Coordinate> Scout::getAttackableCoordinates(){
	//std::vector<Coordinate> v;
	//v.push_back(ATTACK); // return { ATTACK} da diyebiliiriz direkt
	//return v;
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
std::vector<Coordinate> Scout::getMoveableCoordinates(){
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
std::vector<Coordinate> Scout::getHealableCoordinates(){

	return { } ;
}