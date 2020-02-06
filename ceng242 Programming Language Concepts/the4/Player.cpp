#include"Player.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Player::Player(uint id,int x, int y, Team team):id(id),coordinate(x,y),team(team){}



uint Player::getID() const{
	return this->id;
}
const Coordinate& Player::getCoord() const{
	return this->coordinate;
}

int Player::getHP() const{
	return this->HP;
}

Team Player::getTeam() const{
	return this->team;
}

std::string Player::getBoardID(){
	if(this->id<10){
		std::string lessid = std::to_string(this->id) ;
		std::string a = "0"+lessid; 
		return a;
	}
	else{
		return std::to_string(this->id);
	}
}


bool Player::attack(Player *enemy){
	if(enemy==this){
		return false;
	}
	int damaged = this->getAttackDamage();
	std::cout << "Player " << this->getBoardID() << " attacked " << "Player " << enemy->getBoardID() << " (" << damaged << ")" << std::endl;
	enemy->HP = enemy->HP - damaged ; 
	return enemy->isDead();
}

void Player::heal(Player *ally){
	int maxhp = ally->getMaxHP();
	int healed = this->getHealPower();

	std::cout << "Player " << this->getBoardID() << " healed " << "Player " << ally->getBoardID() << std::endl;
	
	if(maxhp <= ally->HP + healed) {
		ally->HP = maxhp;
	}
	else{
		ally->HP = ally->HP + healed; 
	}
}

bool Player::isDead() const{
	return (this->HP <= 0);
}
//direkt move et
void Player::movePlayerToCoordinate(Coordinate c){
	//for(int i = 0; i < this->getMoveableCoordinates().size() ; i++){
		
		//std::cout<< *i <<std::endl; 
	//	if(c == getMoveableCoordinates()[i]){  //sorunlu olacak
			Coordinate old = coordinate;
			//coordinate = c + coordinate ;		// buralar biraz daha zor olabilir
			coordinate =  c;
			std::cout << "Player " << this->getBoardID() << " moved from " << old << " to "  << coordinate <<std::endl;
	//	}
	//}

}

std::vector<Coordinate> Player::getHealableCoordinates(){
	return this->getHealableCoordinates();
}

//gereksiz bu
std::vector<Goal> Player::getGoalPriorityList(){
	return this->getGoalPriorityList();
}

std::vector<Coordinate> Player::getMoveableCoordinates(){
	return this->getMoveableCoordinates();
}
std::vector<Coordinate> Player::getAttackableCoordinates(){
	return this->getAttackableCoordinates();
}

const std::string Player::getClassAbbreviation() const{
	return this->getClassAbbreviation();
}