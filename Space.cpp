/***************************************************************************************************
 * Name: Jessica Albert
 * Project: Final Project - Space.hpp
 * Date: 3/8/19
 * Description: The Space class is an abstract class that represents a space on a game board. It
 * has 4 Space pointers that are used to link together a board of Spaces. It has 3 other data 
 * members, a bool to track whether a player occupies this space, a character that indicates what
 * type of space the space is when the board is printed, and string that holds the type of space.
 * All functions are pure virtual, however the setter and getter functions for the data members
 * are defined to avoid re-writing the code in each inherited class. The other pure virtual functions
 * include one to get a random number, one to display a menu with the user's movement options, a 
 * setback and positive outcome function, and a function to get a random event. 
 * ************************************************************************************************/

#include "Space.hpp"

#include <iostream>


Space::Space()
{
   this->up = NULL;
   this->down = NULL;
   this->next = NULL;
   this->prev = NULL;
   this->playerOccupies = false;
}

/***************************************************************************************************
 * The following are setter and getter functions for each protected data member.		   *
 * ************************************************************************************************/
bool Space::getPlayerOccupies()
{
   return this->playerOccupies;
}

void Space::setPlayerOccupies(std::string set)
{
   if(set == "true")
      this->playerOccupies = true;
   
   else if(set == "false")
      this->playerOccupies = false;
}

char Space::getSymbol()
{
   return this->symbol;
}

void Space::setSymbol(char newSymbol)
{
   this->symbol = newSymbol;
}

std::string Space::getType()
{
   return this->type;
}

void Space::setType(std::string newType)
{
   this->type = newType;
}

void Space::setUp(Space * newUp)
{
   this->up = newUp;
}

void Space::setDown(Space * newDown)
{
   this->down = newDown;
}

void Space::setNext(Space * newNext)
{
   this->next = newNext;
}

void Space::setPrev(Space * newPrev)
{
   this->prev = newPrev;
}

Space* Space::getUp()
{
   return this->up;
}
Space* Space::getDown()
{
   return this->down;
}
Space* Space::getNext()
{
   return this->next;
}
Space* Space::getPrev()
{
   return this->prev;
}
