/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - PersonalProject.hpp
 * Description: This class inherits from the abstract class Items. This item is achieved when the
 * Player lands on a Project Space.
 * ************************************************************************************************/

#ifndef PERSONALPROJECT_HPP
#define PERSONALPROJECT_HPP

#include <string>
#include <iostream>
#include "Items.hpp"

class PersonalProject : public Items
{
   private:
	std::string name;

   public:
	PersonalProject();
	~PersonalProject() {};

	virtual void setName(std::string);
	virtual std::string getName();
};
#endif
