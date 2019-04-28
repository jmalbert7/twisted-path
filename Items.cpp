/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - Items.hpp
 * Description: This claiss is the parent class for the items stored in the Player's toolkit.
 * This is an abstract class.
 * ************************************************************************************************/

#include "Items.hpp"
#include <string>

Items::Items()
{}

void Items::setName(std::string nameIn)
{
	this->name = nameIn;
}
std::string Items::getName()
{
	return this->name;
}
