/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - PersonalProject.hpp
 * Description: This class inherits from the abstract class Items. This item is achieved when the
 * Player lands on a Project Space.
 * ************************************************************************************************/


#include "PersonalProject.hpp"
#include <string>

PersonalProject::PersonalProject()
{
	this->name = "Personal Project";
	std::cout << "Congrats! " << name << " earned" << std::endl;
}

void PersonalProject::setName(std::string nameIn)
{
	this->name = nameIn;
}
std::string PersonalProject::getName()
{
	return this->name;
}
