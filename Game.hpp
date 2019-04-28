/***************************************************************************************************
 * Name: Jessica Albert
 * Project: Final Project - Game.hpp
 * Date: 3/9/19
 * Description: The Game class holds all data members and functions pertinent to the gameplay flow
 * of the game. This includes a Player object member, and 9 linked Space objects. The functions
 * included in this class move the Player through the game and figure out the outcome and special
 * events in each round. The Game cladd also initializes the game board by linking all of the Space
 * objects together.
 * ************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Board.hpp"

#include <string>

class Game
{
   private:
        Player *player;
	Space *playerSpace;
	Board *board;

   public:
	Game(Player *, Board*);
	~Game(){};
	//gameplay functions 
	int moveMenu();
	bool roundMenu(int);
	void movePlayer();
//	int roundOutcome();
        void setPlayerSpace();
};
#endif
