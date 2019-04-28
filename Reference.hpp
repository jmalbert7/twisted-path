/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - Reference.hpp
 * Description: This class inherits from the abstract class Items.
 * ************************************************************************************************/

#ifndef REFERENCE_HPP
#define REFERENCE_HPP

#include <string>
#include <iostream>
#include "Items.hpp"

class Reference : public Items
{
   private:
	std::string name;

   public:
	Reference();
	~Reference() {};

	virtual void setName(std::string);
	virtual std::string getName();
};
#endif
