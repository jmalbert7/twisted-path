/***************************************************************************************************
 * Name: Jessica Albert
 * Project: Final Project - Board.hpp
 * Date: 3/9/19
 * Description: The Board class initializes each Space object and links the new objects together to
 * create a square board of Spaces. This class will allow the board to be scalable because the user
 * of the class can dictate the number of each type of space is initialized and the number of rows
 * and columns of the Board. The Spaces are linked together via Space pointers.
 * ***********************************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Space.hpp"

class Board
{
   private:
	int numSpace1; 
	int numSpace2;
	int numSpace3;
	int numRows;
	int numCols;
	Space *head;
	Space *playerPosition;
	int study;
	int project;
	int apply;

   public:
	//constructor and destructor
	Board(int, int, int, int, int);
	~Board();

	//setters and getters for data members needed to construct the Space board
	int getNumSpace1();
	void setNumSpace1(int);
	int getNumSpace2();
	void setNumSpace2(int);
	int getNumSpace3();
	void setNumSpace3(int);
	int getNumRows();
	void setNumRows(int);
	int getNumCols();
	void setNumCols(int);
	Space* getHeadPtr();

	//functions to build the Space objects and link them together
	void addBack(Space *&);
	void addDown(Space *, Space *);
	void buildBoard();
	void printBoard();
};

#endif
