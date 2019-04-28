/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - Degree.hpp
 * Description: This class inherits from the abtract class Items. A Degree item is achieved by the 
 * player if they earn 16 Study points in the course of the game.
 * ************************************************************************************************/

#ifndef DEGREE_HPP
#define DEGREE_HPP

#include <string>
#include <iostream>
#include "Items.hpp"

class Degree : public Items
{
   private:
	std::string name;

   public:
	Degree();
	~Degree() {};

	virtual void setName(std::string);
	virtual std::string getName();
};
#endif
