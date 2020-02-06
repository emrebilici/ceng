#include"Game.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/
Game::Game(uint maxTurnNumber, uint boardSize, Coordinate chest):board(boardSize, &players ,chest),maxTurnNumber(maxTurnNumber) {
	turnNumber = 0;
	died = 0;
}

Game::~Game(){

}


void Game::addPlayer(int id, int x, int y, Team team, std::string cls){
	
		if(cls== "ARCHER")
		{
			Player* archer = new Archer(id,x,y,team);
			players.push_back(archer);
		}
		else if(cls== "FIGHTER"){
			
			Player* fighter = new Fighter(id,x,y,team);
			players.push_back(fighter);
		}
		 else if("PRIEST" ==cls){
			Player* priest = new Priest(id,x,y,team);
			players.push_back(priest);
		}
		else if (cls=="SCOUT"){
			Player* scout = new Scout(id,x,y,team);
			players.push_back(scout);
		}
		else if( "TANK"==cls){
			Player* tank = new Tank(id,x,y,team);
			players.push_back(tank);
		}

	std::sort(players.begin(), players.end(), [](Player* p1, Player* p2){return p1->getID() < p2->getID(); });					//https://stackoverflow.com/questions/1380463/sorting-a-vector-of-custom-objects


}

bool Game::isGameEnded(){
/*
   * Game ended at turn 13. All barbarians dead. Knight victory.-DONE
   * Game ended at turn 121. All knights dead. Barbarian victory. -done
   * Game ended at turn 52. Chest captured. Barbarian victory. -done
   * Game ended at turn 215. Maximum turn number reached. Knight victory. -done
*/
	int barbarFlag = 0;
	int knightFlag = 0;
	if(maxTurnNumber == turnNumber){
		std::cout << "Game ended at turn " << maxTurnNumber << ". Maximum turn number reached. Knight victory." << std::endl;
		return true;
	}
	for (int i = 0; i < players.size(); i++){
    	if(players.at(i)->getCoord() == board.getChestCoordinates() && players.at(i)->getTeam()== BARBARIANS){
    		std::cout << "Game ended at turn " << turnNumber << ". Chest captured. Barbarian victory." << std::endl;
    		return true;
    	}
    	else if((players.at(i)->getTeam() == BARBARIANS) ){
    		barbarFlag++;
    	}
    	else if((players.at(i)->getTeam() == KNIGHTS) ){
    		knightFlag++;
    	}

	}
	if(players.size() == knightFlag){
		std::cout << "Game ended at turn " << turnNumber << ". All barbarians dead. Knight victory." << std::endl;
		return true;
	}
	else if(players.size() == barbarFlag){
		std::cout << "Game ended at turn " << turnNumber << ". All knights dead. Barbarian victory." << std::endl;
		return true;
	}
	else false;

}

void Game::playTurn(){
  /**
   * Play a turn for each player.
   * Actions are taken in the order of ID numbers of players (player with
   * smaller ID acts first).
   * At the start of the turn it announces that the turn has started by printing
   * to stdout. Turn numbers starts with 1.
   * Ex: "Turn 13 has started."
   * Call playTurnForPlayer for every player.
   *
   */
	turnNumber++;
	std::cout << "Turn " << turnNumber << " has started." << std::endl;
	for(int i=0 ; i < players.size() ; i++){

		playTurnForPlayer((players)[i]);
		if(died){
			died = 0;
			i = i - 1;
		}
		//std::cout<< players[i]->getID() <<std::endl;
	}




}


  /**
   * Play a turn for the given player.
   * If the player is dead announce its death by printing the boardID of the player
   * as in "Player 07 died.". Remove that player from the board and release its resources.
   *  -done 
   * Each player has a goal list sorted by its priority for that player.
   * When a player plays a turn it iterates over its goal list and tries to take
   * an action. Valid actions are attack, move and heal. A player can take only
   * one action in a turn, and if there is no action it can take it stops and does nothing.
   * Before moving a player you must check if the coordinate to move is valid.
   * Meaning that, the coordinate is in the bounds of the board and there are no
   * players there.
   *
   * IMPORTANT NOTE: every usage of the word nearest is referencing smallest the manhattan
   * distance, which is formulated as (abs(x_1-x_2) + abs(y_1-y_2)). operator-
   * overloaded in Coordinate.h computes exactly that, so you can use that method to
   * calculate the distance between two coordinates.
   *
   * Below are the explanations for goals:
   *
   * ATTACK:
   *   - If there are any enemies in the attack range of the player attack to it.
   *     If there are more than 1 enemy in the range attack to the one with
   *     lowest ID. If there is no one to attack try the next goal.
   *
   * CHEST:
   *   - Move to the direction of the chest, if both vertical and horizontal moves
   *     are available, pick the horizontal one. If the horizontal move is blocked
   *     but the vertical move is not, move vertically. If all directions towards
   *     the chest is blocked try the next goal.
   *
   * TO_ENEMY:
   *   - Move towards the nearest enemy. If there are more than one enemies with the same distance
   *     move towards the one with the smallest ID. If both vertical and horizontal moves
   *     are available, pick the horizontal one. If an enemy is in the squares
   *     that the player can move or every move that brings the player closer to
   *     the selected enemy is blocked, try the next goal.
   *
   * TO_ALLY:
   *   - Move towards the nearest ally. If there are more than one allies with the same distance
   *     move towards the one with the smallest ID.  If both vertical and horizontal moves
   *     are available, pick the horizontal one. If an ally is in the squares
   *     that the player can move or every move that brings the player closer to
   *     the selected ally is blocked, try the next goal.
   *
   * HEAL:
   *   - If there are any allies in the healing range heal all of them. if there
   *     is no one to heal try the next goal.
   *
   *
   * @return the goal that the action was taken upon. NO_GOAL if no action was taken.
   */
Goal Game::playTurnForPlayer(Player* player){
	int i=0;
	if(player->isDead()){
		died = 1;
		std::cout << "Player " << player->getBoardID() << " died." << std::endl;
		for( i=0 ; i < players.size() ; i++){
			if(players.at(i)->getID() == player->getID()){
				break;
			}	
		}

		players.erase(players.begin()+i);
		return NO_GOAL;
	}
	bool f = false;
	int g = 0;
	if( player->getGoalPriorityList().at(g) && (player->getGoalPriorityList().at(g) == HEAL)){

		for(int k = 0; k < player->getHealableCoordinates().size() ; k++){		//heal edebilecegi koordinatlar
			if(board[player->getHealableCoordinates().at(k)]){					// bu koordinatlarda biri var mi? 
				if(board[player->getHealableCoordinates().at(k)]->getTeam() == player->getTeam()) {		//koordinat doluysa takima bak . ayni takimsa tedavi et.
					//std::cout << board[player->getHealableCoordinates().at(k)]->getHP() << std::endl;
					if(board[player->getHealableCoordinates().at(k)]->getHP() != board[player->getHealableCoordinates().at(k)]->getMaxHP()){
						player->heal(board[player->getHealableCoordinates().at(k)]);
						
						f = true;
					}
					//std::cout << board[player->getHealableCoordinates().at(k)]->getHP()   << std::endl ; 	// iyilestireceklerini veriyo
				}
			}		
		}
		
		if(f){
			return HEAL;
		}
		else g++;
	}

	if( (player->getGoalPriorityList().at(g) == ATTACK) ){
		uint minid = UINT_MAX;
		int location = 0;
		for(int k = 0; k < player->getAttackableCoordinates().size() ; k++){		//attack edebilecegi koordinatlar
			if( board[player->getAttackableCoordinates().at(k)] && (board[player->getAttackableCoordinates().at(k)]->getTeam() != player->getTeam())) {		// bu koordinatlarda biri var mi? farkli takim mi
				if(minid > board[player->getAttackableCoordinates().at(k)]->getID()){	//minimumu bul
					minid =  board[player->getAttackableCoordinates().at(k)]->getID();
					location = k;
					f = true;
				}

			}		
		}
		if (f){			// eger attack edilecek biri varsa dal.
			player->attack(board[player->getAttackableCoordinates().at(location)]);
			std::cout << board[player->getAttackableCoordinates().at(location)]->getHP()   << std::endl ;
			return ATTACK;
		}
		else {
			g++;
		}	
	
	}


}
