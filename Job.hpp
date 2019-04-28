/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - Job.hpp
 * Description: This class inherits from the abstract class Items. When a Player acquires this 
 * Item the objective is achieved and the game is won.
 * ************************************************************************************************/

#ifndef JOB_HPP
#define JOB_HPP

#include <string>
#include <iostream>
#include "Items.hpp"

class Job : public Items
{
   private:
	std::string name;

   public:
	Job();
	~Job() {};

	virtual void setName(std::string);
	virtual std::string getName();
};
#endif
