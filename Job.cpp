/***************************************************************************************************
 * Name: Jessica Albert
 * Date: 3/16/19
 * Project: Final Project - Job.hpp
 * Description: This class inherits from the abstract class Items. When a Player acquires this 
 * Item the objective is achieved and the game is won.
 * ************************************************************************************************/


#include "Job.hpp"
#include <string>

Job::Job()
{
	this->name = "Job";
	std::cout << "Objective complete. Goodbye!" << std::endl;
}

void Job::setName(std::string nameIn)
{
	this->name = nameIn;
}
std::string Job::getName()
{
	return this->name;
}
