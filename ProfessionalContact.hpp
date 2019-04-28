/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - ProfessionalContact.hpp
 * Description: This class inherits from the abstract class Items. A player can gain this item if
 * they attend a networking event (random event in the Study class). 
 * ************************************************************************************************/

#ifndef PROFESSIONALCONTACT_HPP
#define PROFESSIONALCONTACT_HPP

#include <string>
#include <iostream>
#include "Items.hpp"

class ProfessionalContact : public Items
{
   private:
	std::string name;

   public:
	ProfessionalContact();
	~ProfessionalContact() {};

	virtual void setName(std::string);
	virtual std::string getName();
};
#endif
