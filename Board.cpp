/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/6/19
 * Project: Final Project - Board.cpp
 * Description: The Board class initializes the linked list of Space objects for the game.
 * ************************************************************************************************/
#include "random.hpp"
#include "Board.hpp"
#include "Space.hpp"
#include "Study.hpp"
#include "Project.hpp"
#include "Apply.hpp"

#include <iostream>


/***************************************************************************************************
 * The Board class constructor takes the number of each type of space you would like added to the 
 * (assumg 3 different types of spaces) and the umber of rows and columns of the board. The 
 * constructor automatically builds the board when it is called.
 * ************************************************************************************************/
Board::Board(int numStudy, int numProject, int numApply, int row, int col)
{
	this->numSpace1 = numStudy;
	this->numSpace2 = numProject;
	this->numSpace3 = numApply;
	this->numRows = row;
	this->numCols = col;
	this->head = NULL;
	this->study = 0;
	this->project = 0;
	this->apply = 0;
	buildBoard();
}

/***************************************************************************************************
 * The destructor traverses the linked spaces in the board and deletes them one at a time. The head 
 * of the list is moved down to the next row while a pair of Space pointers deleted the spaces
 * in the previous row until all the spaces are gone
 * ************************************************************************************************/
Board::~Board()
{
	Space *ptr = this->head;
	Space *garbage = ptr;

	while(head != NULL)
	{
			ptr = head;
			garbage = ptr;
			if(head->getDown() != NULL)
			{
				head = head->getDown();
			}
			else
			{
				head = NULL;
			}
			while(ptr != NULL)
			{
				ptr = ptr->getNext();
				delete garbage;
				garbage = ptr;
			}
			
	}
				
				
}


/***************************************************************************************************
 * The following are a list of setters and getters for the Board class data members
 * ************************************************************************************************/
int Board::getNumSpace1()
{
	return this->numSpace1;
}

void Board::setNumSpace1(int numStudy)
{
	this->numSpace1 = numStudy;
}

int Board::getNumSpace2()
{
	return this->numSpace2;
}

void Board::setNumSpace2(int numProject)
{
	this->numSpace2 = numProject;
}

int Board::getNumSpace3()
{
	return this->numSpace3;
}

void Board::setNumSpace3(int numApply)
{
	this->numSpace3 = numApply;
}

int Board::getNumRows()
{
	return this->numRows;
}

void Board::setNumRows(int row)
{
	this->numRows = row;
}

int Board::getNumCols()
{
	return this->numCols;
}

void Board::setNumCols(int col)
{
	this->numCols = col;
}

Space* Board::getHeadPtr()
{
	return this->head;
}


/***************************************************************************************************
 * This function builds the board of Space objects row by row. 
 * ************************************************************************************************/
void Board::buildBoard()
{
	Space *newHead = NULL;
	Space *ptr = NULL;
	addBack(newHead);
	
	this->head = newHead; 
	for(int i = 0; i < (this->numRows - 1); i++)
	{
		ptr = NULL;
		addBack(ptr);
		addDown(newHead, ptr);
		newHead = ptr;
	}
	std::cout << "The starting Board is: " <<std::endl;
	printBoard();
}

/***************************************************************************************************
 * This function adds a new Space object to the end of a list of Space objects. The function
 * stops adding Spaces to the end once the number of spaces are equal to the numCols member variable
 * ************************************************************************************************/
void Board::addBack(Space *&newHead)
{
	Space *ptr = NULL;
	Space *subHead = newHead;
	bool success = false;
	int type = 0;
	for(int i = 0; i < this->numCols; i++)
	{
		type = randomNumber(1,3);
		
		//if the list is empty
		if(subHead == NULL)
		{
			while(success == false)
			{
				if(this->study < this->numSpace1 && type == 1)
				{
					subHead = new Study();
					this->study++;
					success = true;
				}
				else if(this->project < this->numSpace2 && type == 2 )
				{
					subHead = new Project();
					this->project++;
					success = true;
				}
				else if(this->apply < this->numSpace3 && type == 3)
				{
					subHead = new Apply();
					this->apply++;
					success = true;
				}
				else
				{
					type = randomNumber(1,3);
				}
				if(success)
				{
				newHead = subHead;
				}
			}
		}
		else
		{
			while(success == false)
			{
				if(this->study < this->numSpace1 && type == 1)
				{
					ptr = new Study();
					this->study++;
					success = true;
				}
				else if(this->project < this->numSpace2 && type == 2)
				{
					ptr = new Project();
					this->project++;
					success = true;
				}
				else if(this->apply < this->numSpace3 && type == 3)
				{
					ptr = new Apply();
					this->apply++;
					success = true;
				}
				else
				{
					type = randomNumber(1,3);
				}
			}
	
			subHead->setNext(ptr);
			ptr->setPrev(subHead);
			subHead = subHead->getNext();
		}
		success = false;
	}
}

/****************************************************************************************************
 * The add down function knits two rows of linked Space objects together. 
 * ************************************************************************************************/	
void Board::addDown(Space *top, Space *bottom)
{
	Space *ptr1 = top;
	Space *ptr2 = bottom;
	
	if(ptr1 != NULL && ptr2 != NULL)
	{
		ptr1->setDown(ptr2);
		ptr2->setUp(ptr1);
	
		for(int i = 0; i < (this->numCols - 1); i++)
		{
			ptr1 = ptr1->getNext();
			ptr2 = ptr2->getNext();

			ptr1->setDown(ptr2);
			ptr2->setUp(ptr1);
		}
	}
}

/***************************************************************************************************
 * This funciton calls the Space member function getSymbol() to get and print the board of spaces
 * ************************************************************************************************/
void Board::printBoard()
{

	Space *ptr = this->head;
	Space *subHead = this->head;
	bool done = false;
	
	do{
		for(int c = 0; c < this->numCols; c++)
		{
			if(ptr != NULL)
			{
				std::cout << ptr->getSymbol() << " ";
 				ptr = ptr->getNext();
			}
		}
		if(subHead != NULL)
		{
			subHead = subHead->getDown();
			ptr = subHead;
			std::cout<< std::endl;
		}
		else
			done = true;
	}while(done == false);		
}


