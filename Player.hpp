/***************************************************************************************************
 * Name: Jessica Albert
 * Project: Final Project - Player.hpp
 * Date: 3/10/19
 * Description: The Player class is used to implement the 'Game of Life' text game. In this game
 * the player has 20 steps to get a job as a programmer. They must do this by shedding doubts, and
 * gaining confidence, technical know-how, and courage points. Once the required points are obtained
 * the Player gets the job. The player has 8 data members described below. It also has functions to 
 * move to update it's location on the Space board, add a new item to its collection, and display 
 * its stats, and update its stats.
 * ************************************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>

#include "Items.hpp"

class Player
{
   private:
	//player stats
	int confidence;
	int doubt;
	int technical;
	int courage;
	int study;
	int steps;
	bool jobFound;
	bool project;
	bool degree;
	bool contact;
	bool reference;

	//player's items
	std::vector<Items*> items;
	
   public:
	Player();
	~Player();

	void intro();
	
	int getConfidence();
	void addConfidence();
	void removeConfidence();
	int getTechnical();
	void addTechnical();
	void removeTechnical();
	int getCourage();
	void addCourage();
	void removeCourage();
	int getDoubt();
	void addDoubt();
	void removeDoubt();
	int getStudy();
	void addStudy();
	int getSteps();
	void addSteps();
	bool getJobFound();
	void setJobFound(std::string);
	bool getDegree();
	void setDegree(std::string);
	bool getProject();
	void setProject(std::string);
	bool getProfessionalContact();
	void setProfessionalContact(std::string);
	bool getReference();
	void setReference(std::string);

	void displayStats();
	void displayItems();
	void addItem(Items *);

};

#endif
