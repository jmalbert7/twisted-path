

#include "Player.hpp"
#include "Items.hpp"
#include "Degree.hpp"
#include "PersonalProject.hpp"
#include "Job.hpp"
#include "ProfessionalContact.hpp"

#include <iostream>
#include <string>

/***************************************************************************************************
 * The constuctor initializes the Player with high Doubt points and relatively low points for the 
 * other stats. It also initalizes all the Items Object obtained bool variables to false. It prints
 * the intro to the game and the Player's starting stats to the user.
 * ************************************************************************************************/
Player::Player()
{
	this->doubt = 5;
	this->courage = 3;
	this->confidence = 1;
	this->technical = 0;
	this->study = 0;
	this->steps = 0;
	this->jobFound = false;
	this->contact = false;
	this->degree = false;
	this->project = false;
	this->reference = false;
	intro();
	std::cout << "Starting stats are: " << std::endl;
	displayStats();
}

/***************************************************************************************************
 * The destructor deletes each Items object in the Player's Items vector.
 * ************************************************************************************************/
Player::~Player()
{
	for(unsigned int i = 0; i < this->items.size(); i++)
	{
		Items* it = items.at(i);
		delete(it);
		it = NULL;
	}
}

/***************************************************************************************************
 * this function displays the objective and theme of the game
 * ************************************************************************************************/
void Player::intro()
{
	std::cout << std::endl << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Welcome to the Game of Life - Twisted Path Edition!" << std::endl;
	std::cout << "The objective of the game is to get a job as a software developer." << std::endl;
	std::cout << "To complete the objective you must traverse the board to gain" << std::endl;
	std::cout << "Technical, Confidence, and Courage points while shedding Doubt points." << std::endl;
	std::cout << "The spaces on the board include Study(S), Project(P) and Apply(A)." << std::endl;
	std::cout << "You can only achieve the objective if you have 0 Doubt, 5 Technical" << std::endl;
	std::cout << "5 Courage, and 5 Confidence points." << std::endl;
	std::cout << "There are also hidden items in the game that will help you reach the objective." << std::endl;
	std::cout << "A menu will prompt you with possible moves for each round. You have 20 steps to complete the objective. " << std::endl;
	std::cout << "Good Luck!" << std::endl << std::endl;
}

/***************************************************************************************************
 * This function displays the Player data to the user
 * ************************************************************************************************/
void Player::displayStats()
{
 	std::cout << "Doubts: " << this->doubt << std::endl;		
 	std::cout << "Confidence: " << this->confidence << std::endl;		
 	std::cout << "Courage: " << this->courage << std::endl;		
 	std::cout << "Technical: " << this->technical << std::endl;		
	std::cout << "Study points: " << this->study << std::endl;
	std::cout << "You have taken " << this->steps << " steps, " << 20 - this->steps << " steps are left in the game." << std::endl << std::endl;
}

/***************************************************************************************************
 * The following are the setter and getter functions for the Player data members. 
 * ************************************************************************************************/
int Player::getConfidence()
{
	return this->confidence;
}

void Player::addConfidence()
{
	this->confidence += 1;
}

void Player::removeConfidence()
{
	this->confidence -= 1;
}

int Player::getTechnical()
{
	return this->technical;
}

void Player::addTechnical()
{
	this->technical += 1;
}

void Player::removeTechnical()
{
	this->technical -= 1;
}

int Player::getCourage()
{
	return this->courage;
}

void Player::addCourage()
{
	this->courage += 1;
}

void Player::removeCourage()
{
	this->courage -= 1;
}

int Player::getDoubt()
{
	return this->doubt;
}

void Player::addDoubt()
{
	this->doubt += 1;
}

void Player::removeDoubt()
{
	this->doubt -= 1;
}

int Player::getStudy()
{
	return this->study;
}

void Player::addStudy()
{
	this->study += 1;
}

int Player::getSteps()
{
	return this->steps;
}

void Player::addSteps()
{
	this->steps += 1;
}

void Player::setJobFound(std::string set)
{
	if(set == "true")
		this->jobFound = true;
	else
		this->jobFound = false;
}

bool Player::getJobFound()
{
	return this->jobFound;
}

void Player::setDegree(std::string set)
{
	if(set == "true")
		this->degree = true;
	else
		this->degree = false;
}

bool Player::getDegree()
{
	return this->degree;
}

void Player::setProject(std::string set)
{
	if(set == "true")
		this->project = true;
	else
		this->project = false;
}

bool Player::getProfessionalContact()
{
	return this->contact;
}

void Player::setProfessionalContact(std::string set)
{
	if(set == "true")
		this->contact= true;
	else
		this->contact = false;
}

bool Player::getReference()
{
	return this->reference;
}

void Player::setReference(std::string set)
{
	if(set == "true")
		this->reference= true;
	else
		this->reference = false;
}

bool Player::getProject()
{
	return this->project;
}

/***************************************************************************************************
 * This function prints all the items in the Player's Items vector. This is part of the main menu
 * ************************************************************************************************/
void Player::displayItems()
{
	if(!this->items.empty())
	{
		std::cout << "You have the following items: " << std::endl;
		for(unsigned int i = 0; i < this->items.size(); i++)
		{
			std::cout << items[i]->getName() << ", ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "You have no items. " << std::endl;
}

/***************************************************************************************************
 * This function adds an item to the Player's Items pointer vector.
 * ************************************************************************************************/
void Player::addItem(Items *newItem)
{
	items.push_back(newItem);
}

