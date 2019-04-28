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

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include "Player.hpp"
#include "getInteger.hpp"

class Space
{
   protected:
      //self referential pointers to implement linked grid structure
      Space *up;
      Space *down;
      Space *next;	
      Space *prev;

      //space type data members
      bool playerOccupies;
      char symbol;
      std::string type;
      int maxSides;

   public:
      //constructor/destructor
      Space();
      virtual ~Space() {};

      //setters and getters
      bool getPlayerOccupies();
      void setPlayerOccupies(std::string);
      char getSymbol();
      void setSymbol(char);
      std::string getType();
      void setType(std::string);
      void setUp(Space *);
      void setDown(Space *);
      void setPrev(Space *);
      void setNext(Space *);
      Space* getUp();
      Space* getDown();
      Space* getNext();
      Space* getPrev();
      int getMaxSides();
      void setMaxSides(int);
     
      //pure virtual member functions
      virtual void setback(Player *player) = 0;
      virtual void positive(Player *player) = 0;
      virtual void setPlayerPosition() = 0;
      virtual void spaceRound(Player *player) = 0;

};
#endif
