/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - ProfessionalContact.cpp
 * Description: This class inherits from abstract class Items. A Player can gain this item if they 
 * attend a networking event and the random event is favorable.
 * ************************************************************************************************/

#include "ProfessionalContact.hpp"
#include <string>

ProfessionalContact::ProfessionalContact()
{
	this->name = "Professional Contact";
	std::cout << "Congrats! " << name << " earned" << std::endl;
}

void ProfessionalContact::setName(std::string nameIn)
{
	this->name = nameIn;
}
std::string ProfessionalContact::getName()
{
	return this->name;
}
