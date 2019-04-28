/***************************************************************************************************
 * Name: Jessica Albert
 * Project: Final Project - main.cpp
 * Date: 3/11/19
 * Description: The main function initializes a Player, Board, and Game object first. From here it
 * sets a bool equal to the outcome of the game member function roundMenu to determine if the user
 * wants to continue playing the game or quit. After each round it also checks that the Player has
 * taken less than 20 steps (time limit implementation), or if the Player achieved the objective
 * for gaining a Job object. If the Player does not achieve the objective it explains why the game
 * is ending before exiting.
 * ************************************************************************************************/

#include "Space.hpp"
#include "Study.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Game.hpp"

#include <iostream>
#include <ctime>

int main()
{
	srand(time(NULL));
	Player *player = new Player();
	Board *board = new Board(13, 2, 1, 4, 4);	
	Game *game = new Game(player, board);

	bool play = true;
	do{
		play = game->roundMenu(4);
	}while(play == true && player->getSteps() < 20 && player->getJobFound() == false); 

	if(player->getJobFound() == false)
	{
		std::cout << "Sorry, you have not achieved the objective." << std::endl;
		if(player->getSteps() >= 20)
			std::cout << "Too many steps" << std::endl;
		else if(play == false)
			std::cout << "You quit." << std::endl;
	}

	delete player;
	delete board;
	delete game;
	player = NULL;
	board = NULL;
	game = NULL;
	return 0;
}
