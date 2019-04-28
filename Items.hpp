/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - Items.hpp
 * Description: This claiss is the parent class for the items stored in the Player's toolkit.
 * This is an abstract class.
 * ************************************************************************************************/

#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>

class Items
{
   private:
	std::string name;

   public:
	Items();
	virtual ~Items() {};

	virtual void setName(std::string) = 0;
	virtual std::string getName();
};
#endif
