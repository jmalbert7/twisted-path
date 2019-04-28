/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - Reference.hpp
 * Description: This claiss is the parent class for the items stored in the Player's toolkit.
 * This is an abstract class.
 * ************************************************************************************************/

#include "Reference.hpp"
#include <string>

Reference::Reference()
{
	this->name = "Personal Project";
	std::cout << "Congrats! " << name << " earned" << std::endl;
	std::cout << "Reference fast tracks you to the objective!!!" << std::endl;
}

void Reference::setName(std::string nameIn)
{
	this->name = nameIn;
}
std::string Reference::getName()
{
	return this->name;
}
