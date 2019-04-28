/***************************************************************************************************
 * Name: Jessica Albert
 * Project: Final Project - Project.hpp
 * Date: 3/6/19
 * Description: The Project class inherits from abstract class Space. In a Project Space the player will 
 * gain a study point. If a player has 2 study points after landing on a Project space the player 
 * will have completed 1 class. When a class is completed the player gains 1 technical point, 1
 * confidence point, and shed one doubt point. The setback that is possible with this Space can 
 * cause the Player to lose a confidence point. The psoitive outcome possible will be the Player 
 * overcoming a challenging class, finding a networking event item, or finding a professional
 * contact item.
 * ***********************************************************************************************/

#include "Project.hpp"
#include "random.hpp"
#include "Items.hpp"
#include "PersonalProject.hpp"
#include "ProfessionalContact.hpp"

#include <iostream>

Project::Project()
{
	this->symbol = 'P';
	this->maxSides = 5;
	this->type = "Project Space";
}
Project::~Project()
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
void Project::spaceRound(Player *player)
{
	std::cout << "You are in a " << this->type << std::endl;
	std::cout << "No setbacks possible in this space!" <<std::endl;

	positive(player);

}
	
/**************************************************************************************************
 * This function updates the symbol data member base don whether the member bool playerOccupies
 * is true or false. If true the Space's symbol is changed to 'X', if false it is set back to 'S'
 * ************************************************************************************************/
void Project::setPlayerPosition()
{
   if(this->playerOccupies == true)
	this->symbol = 'X';

   else
	this->symbol = 'P';
}

/***************************************************************************************************
 * The positive function represents a positive outcome to the round, which is more likely than a 
 * setback. For the Project space the addProjectPoint function is called and the number of study points 
 * for the player is analyzed to determine if the player has finished a class i.e. 2 study points).
 * If the player's study points are divisible by 2 the completeClass function is called. Finally the
 * randomEvent function is called to determine if a special positive event will occur.
 * ************************************************************************************************/
void Project::positive(Player *player)
{
   std::cout << "Positive outcome for this round!" << std::endl;
   std::cout << "Gain 1 Technical, 1 Confidence, 1 Courage and lose 1 Doubt." << std::endl;

   player->addTechnical();
   player->addConfidence();
   player->addCourage();
   player->removeDoubt();
   gainProject(player);
   
	
}



void Project::gainProject(Player *player)
{
	//std::cout << "Personal project completed! This will help you score a job!" << std::endl;
	player->setProject("true");
	Items *pro = new PersonalProject();
	player->addItem(pro);
}
