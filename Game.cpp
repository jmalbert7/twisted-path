/***************************************************************************************************
 * Name: Jessica Albert
 * Project: Final Project - Game.hpp
 * Date: 3/9/19
 * Description: The Game class holds all data members anf functions pertinent to the gameplay flow
 * of the game. This includes a Player object member, and 9 linked Space objects. The functions
 * included in this class move the Player through the game and figure out the outcome and special
 * events in each round. The Game cladd also initializes the game board by linking all of the Space
 * objects together.
 * ************************************************************************************************/

#include "Game.hpp"
#include "random.hpp"
#include "getInteger.cpp"

#include <iostream>
#include <string>
#include <sstream>

/***************************************************************************************************
 * The constructor for the Game class takes a Player pointer and a Board pointer as parameters. It
 * then initializes the playerSpace Space pointer to the head of the Board passed to it.
 * ************************************************************************************************/
Game::Game(Player *playerIn, Board *boardIn)
{
	this->player = playerIn;
	this->board = boardIn;
	this->playerSpace = this->board->getHeadPtr();
   	this->playerSpace->setPlayerOccupies("true");
   	this->playerSpace->setPlayerPosition();
	std::cout << "Your position on the Board is represented by an 'X':" <<std::endl;
	this->board->printBoard();
}

/***************************************************************************************************
 * This function displays the possible moves for the player to take. It does this by accessing the *
 * Space's up, down, next, and prev pointers. If any of the pointer is pointing to NULL the move is*
 * not a viable option and the move is not displayed. From here the function calls the getInteger  *
 * function to read in the user's input and finally returns the input to the calling function.     *
 * ************************************************************************************************/
int Game::moveMenu()
{
   bool up = false, down = false, next = false, prev = false;

   std::cout << "Possible moves are: " << std::endl;

   if(this->playerSpace->getUp() != NULL)
   {
      up = true;
      std::cout << "1. Move up to " << this->playerSpace->getUp()->getType() << std::endl;
   }
   if(this->playerSpace->getDown() != NULL)
   {
      down = true;
      std::cout << "2. Move down to " << this->playerSpace->getDown()->getType() << std::endl;
   }
   if(this->playerSpace->getNext() != NULL)
   {
      next = true;
      std::cout << "3. Move right to " << this->playerSpace->getNext()->getType() << std::endl;
   }
   if(this->playerSpace->getPrev() != NULL)
   {
      prev = true;
      std::cout << "4. Move left to " << this->playerSpace->getPrev()->getType() << std::endl;
   }

   int choice = 0;
   std::string input = "";
   
   while(true)
   {
      getline(std::cin, input);
      std::stringstream myStream(input);
      if(isInteger(input) && myStream >> choice)
      {
         if(choice == 1 && up)
            break;
         else if(choice == 2 && down)
            break;
         else if(choice == 3 && next)
            break;
         else if(choice == 4 && prev)
            break;
      }
      std::cout << "You must enter a valid menu option" << std::endl;
   } 
 

   return choice;
}

/***************************************************************************************************
 * This function contains the game menu that appears in each round. The menu asks the user if they 
 * want to move to another space, view their stats, view their items or quit. 
 * ************************************************************************************************/
bool Game::roundMenu(int totalChoice)
{
   std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<std::endl;
   std::cout << "Current Board" << std::endl;
   this->board->printBoard();
   std::cout << std::endl << "Please select an action by typing the corresponding integer and the enter key." << std::endl;
   std::cout << "Viewing stats or items does not count as a step." << std::endl << std::endl;

   std::cout << "1. Move to new Space" << std::endl;
   std::cout << "2. View stats " << std::endl;
   std::cout << "3. View items " << std::endl;
   std::cout << "4. Quit " << std::endl;
  
   int choice = 0;
   std::string input = "";
   
   while(true)
   {
      getline(std::cin, input);
      std::stringstream myStream(input);
      if(isInteger(input) && myStream >> choice)
      {
         if(choice >= 1 && choice <= totalChoice)
            break;
      }
      std::cout << "You must enter an integer selection 1 - " << totalChoice << std::endl;
   } 
   
   switch(choice)
   {
      case 1: movePlayer();
//	      this->board->printBoard();
              return true;

      case 2: this->player->displayStats();
              return true;

      case 3: this->player->displayItems();
              return true;
     
      case 4: return false;

      default: roundMenu(4);
   }
}

/***************************************************************************************************
 * This function moves the player from one space to another
 * ************************************************************************************************/
void Game::movePlayer()
{
   //update the current space to not hold the player any longer
   this->playerSpace->setPlayerOccupies("false");
   this->playerSpace->setPlayerPosition();

   //get the player's move selection
   int choice = moveMenu();
   if(choice == 1 && this->playerSpace->getUp() != NULL)
      this->playerSpace = this->playerSpace->getUp();

   if(choice == 2 && this->playerSpace->getDown() != NULL)
      this->playerSpace = this->playerSpace->getDown();

   if(choice == 3 && this->playerSpace->getNext() != NULL)
      this->playerSpace = this->playerSpace->getNext();

   if(choice == 4 && this->playerSpace->getPrev() != NULL)
      this->playerSpace = this->playerSpace->getPrev();

   this->player->addSteps();
   this->playerSpace->setPlayerOccupies("true");
   this->playerSpace->setPlayerPosition();

   //callSpace object round function
   this->playerSpace->spaceRound(this->player);
}

/***************************************************************************************************
 * This function first asks the user to enter a number 1 - the maxSides member variable (dependent *
 * on the Space Type). It then generates a number 1 - maxSides, if the user's selection matches the*
 * output of the random number generator then the setback function for the Space is called.        * 
 * ************************************************************************************************/
/*int Game::roundOutcome(Space *space)
{
   int random = randomNumber(1, space->getMaxSides())

   int choice = getInteger();

   if(choice == random)
	space->setback();

   else(
}
*/
