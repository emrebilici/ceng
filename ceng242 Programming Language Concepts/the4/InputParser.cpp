#include"InputParser.h"

/*
YOU MUST WRITE THE IMPLEMENTATIONS OF THE REQUESTED FUNCTIONS
IN THIS FILE. START YOUR IMPLEMENTATIONS BELOW THIS LINE
*/

  /**
   * Parse the initial parameters of the game from stdin.
   * The input will be as follows.
   * First line contains the size of the board.
   * Second line contains the coordinates of the chest.
   * Third line contains the maximum turn number for the game.
   * Fourth line contains the number of players, P.
   * Each of the next P lines contains a description for a player as follows.
   * ID of the player, class of the player, team of the player, x coordinate, y coordinate, .
   * Call the addPlayer method of the Game class to add the players.
   * Example input:
   * 6
   * 3 3
   * 100
   * 2
   * 12 ARCHER BARBARIAN 3 5
   * 11 FIGHTER KNIGHT 1 1
   *
   * @returns Pointer to the Dynamically allocated Game object
   */
Game* InputParser::parseGame(){
	std::string multi;
	std::string line;
	int boardsize = 0;
	Coordinate chestcoor;
	int turn = 0;
	int playernumber = 0;

	int i = 0;
	while(std::getline(std::cin, line)){  //bunun yerine stoi kullan playernumber + 3 diyip for dön
		if(line.empty()){
			break;
		}
		if(i == 0){

		}
		i++;
	}

}