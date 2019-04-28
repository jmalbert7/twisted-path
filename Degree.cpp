/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - Degree.cpp
 * Description: This class inherits from the abstract class Items.
 * * ************************************************************************************************/

#include "Degree.hpp"
#include <string>

Degree::Degree()
{
	this->name = "Degree";
	std::cout << "Congrats! " << name << " earned" << std::endl;
}

void Degree::setName(std::string nameIn)
{
	this->name = nameIn;
}
std::string Degree::getName()
{
	return this->name;
}
