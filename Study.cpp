/***************************************************************************************************
 * Name: Jessica Albert
 * Project: Final Project - Study.hpp
 * Date: 3/6/19
 * Description: The Study class inherits from abstract class Space. In a Study Space the player will 
 * gain a study point. If a player has 2 study points after landing on a Study space the player 
 * will have completed 1 class. When a class is completed the player gains 1 technical point, 1
 * confidence point, and shed one doubt point. The setback that is possible with this Space can 
 * cause the Player to lose a confidence point. The psoitive outcome possible will be the Player 
 * overcoming a challenging class, finding a networking event item, or finding a professional
 * contact item.
 * ***********************************************************************************************/

#include "Study.hpp"
#include "random.hpp"
#include "ProfessionalContact.hpp"
#include "Items.hpp"
#include "Reference.hpp"

#include <iostream>

Study::Study()
{
	this->symbol = 'S';
	this->maxSides = 5;
	this->type = "Study Space";
}
Study::~Study()
{

}

/**************************************************************************************************
 * This fucntion runs through the functions necessary to complete a round or step. It is called 
 * by the movePlayer funciton in the game class. First it displayes the type of Space the player
 * is in. Then it asks the user to enter an integer between 1 and the max sides for the Space. 
 * Max sides represents how likely a setback will be for a given Space, the more sides the less 
 * likely a setback will be. If the result of the roll matches the user input the setback function
 * occurs, if it does not match the positive funciton is called.
 * ***********************************************************************************************/
void Study::spaceRound(Player *player)
{
	std::cout << "You are in a " << this->type << std::endl;
	std::cout << "I will roll a die and if your entry matches my roll " <<std::endl;
	std::cout << "then a setback on your journey will occur. " << std::endl;
	
	int choice = getInteger(1, this->maxSides);
	int roll = randomNumber(1, this->maxSides);

	if(choice == roll)
		setback(player);

	else
		positive(player);

}
	
/**************************************************************************************************
 * This function updates the symbol data member base don whether the member bool playerOccupies
 * is true or false. If true the Space's symbol is changed to 'X', if false it is set back to 'S'
 * ************************************************************************************************/
void Study::setPlayerPosition()
{
   if(this->playerOccupies == true)
	this->symbol = 'X';

   else
	this->symbol = 'S';
}

/***************************************************************************************************
 * The setback function is called in the round if the user's roll selection matches the output of a 
 * random number generator (this happens in the Game class roundOutcome function). The setback for 
 * the Study Space includes a challenging class, which is a separate function in the Study class. 
 * ************************************************************************************************/
void Study::setback(Player *player)
{
   std::cout << "A setback on your journey has occured. " << std::endl;
   std::cout << "No study point added this round, don't give up!" << std::endl;
   challengingClass(player);
}

/***************************************************************************************************
 * The positive function represents a positive outcome to the round, which is more likely than a 
 * setback. For the Study space the addStudyPoint function is called and the number of study points 
 * for the player is analyzed to determine if the player has finished a class i.e. 2 study points).
 * If the player's study points are divisible by 2 the completeClass function is called. Finally the
 * randomEvent function is called to determine if a special positive event will occur.
 * ************************************************************************************************/
void Study::positive(Player *player)
{
   std::cout << "Positive outcome for this round!" << std::endl;
   addStudyPoint(player);
   if(player->getStudy() % 2 == 0)
      completeClass(player);
   
   if(randomEvent())
   {
	int event = randomNumber(1,2);
	if(event == 1)
		network(player);
	if(event == 2)
		gainProfessionalContact(player);
   }
	
}

/***************************************************************************************************
 * This function gets a random number 1-4, if 1 is returned a special item or outcome is obtained  *
 * during the round. There is a 1 in 4 chance of obtaining the special item. Special items include *
 * finding a professional contact or going to a networking event,
 * ************************************************************************************************/
bool Study::randomEvent() 
{
   int random = randomNumber(1, 4);
   if(random == 1)
      return true;

   else
      return false;
}

/***************************************************************************************************
 * This function adds a study point to the Player object.
 * ************************************************************************************************/
void Study::addStudyPoint(Player *player)
{
   std::cout << "One study point added" << std::endl;
   player->addStudy();
}

/***************************************************************************************************
 * This function is called if the Player's study points are divisible by 2, meaning they have 
 * gotten 2 study points. This function adds a technical, adds a confidence, and removes a doubt 
 * point from the Players stats. 
 * ************************************************************************************************/
void Study::completeClass(Player *player)
{
   std::cout << "Congrats! You have completed a class!" << std::endl;
   std::cout << "Gained 1 Technical, 1 Confidence and lost 1 Doubt." << std::endl;
   player->addTechnical();
   player->addConfidence();
   player->removeDoubt();
   if(player->getStudy() == 16)
	gainDegree(player);
}

/***************************************************************************************************
 * This function represents the challenging class setback. When the player experiences this setback 
 * they lose a confidence point.
 * ************************************************************************************************/
void Study::challengingClass(Player *player)
{
   std::cout << "A challenging class has set you back. One confidence point lost." << std::endl;
   player->removeConfidence();
}

void Study::network(Player *player)
{
	std::cout << "Special networking event! Let's see if you find a Professional Contact." << std::endl;
	int i = randomNumber(0,1);
	if(i == 1)
		gainProfessionalContact(player);
	else
		std::cout << "No Professional Contact gained at this event" << std::endl;
}

void Study::gainProfessionalContact(Player *player)
{
	//std::cout << "Congrats! Professional Contact item acquired! This will help you to score a job. " << std::endl;
	player->setProfessionalContact("true");
	Items *p = new ProfessionalContact();
	player->addItem(p);

	int random = randomNumber(1,10);
	if(random == 5)
		gainReference(player);
}

void Study::gainDegree(Player *player)
{
	//std::cout << "Congrats! Professional Contact item acquired! This will help you to score a job. " << std::endl;
	player->setDegree("true");
	Items *d = new Degree();
	player->addItem(d);
}

void Study::gainReference(Player *player)
{
	player->setReference("true");
	Items *r = new Reference();
	player->addItem(r);

	player->setJobFound("true");
}
