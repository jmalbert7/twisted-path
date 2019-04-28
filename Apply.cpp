/***************************************************************************************************
 * Name: Jessica Albert
 * Project: Final Project - Apply.hpp
 * Date: 3/6/19
 * Description: The Apply class inherits from abstract class Space. In a Apply Space the player
 * will apply to achieve the objective. They probability of a setback for this space is 50/50.
 * If a positive outcome occurs the player's "application" is checked for 0 Doubt points, 5 each
 * Techincal, Courage, Confidence and at least 1 Personal Project Item. If the application checks
 * out the player achieves the objective and gains the Job item and the program ends.
 * ***********************************************************************************************/

#include "Apply.hpp"
#include "random.hpp"
#include "Items.hpp"
#include "Job.hpp"

#include <iostream>

Apply::Apply()
{
	this->symbol = 'A';
	this->maxSides = 2; //50/50 shot of getting a call back
	this->type = "Apply Space";
}
Apply::~Apply()
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
void Apply::spaceRound(Player *player)
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
void Apply::setPlayerPosition()
{
   if(this->playerOccupies == true)
	this->symbol = 'X';

   else
	this->symbol = 'A';
}

/***************************************************************************************************
 * The setback function is called in the round if the user's roll selection matches the output of a 
 * random number generator (this happens in the Game class roundOutcome function). 
 * ************************************************************************************************/
void Apply::setback(Player *player)
{
   std::cout << "A setback on your journey has occured. " << std::endl;
   std::cout << "Don't give up!" << std::endl;
   applyFail(player);
}

/***************************************************************************************************
 * The positive function represents a positive outcome to the round setback. 
 * ************************************************************************************************/
void Apply::positive(Player *player)
{
   std::cout << "Positive outcome for this round!" << std::endl;
   std::cout << "But first we have to check over your application..." << std::endl;
 
   checkApplication(player); 
	
}

/***************************************************************************************************
 * This function represents the setback for the Apply space. When this function is called the 
 * player loses one confidence point and gains one doubt point. 
 * ************************************************************************************************/
void Apply::applyFail(Player *player)
{
   std::cout << "Unfortunately the application process did not go so well." << std::endl;
   std::cout << "1 Doubt point gained, 1 Confidence point lost" << std::endl;

   player->removeConfidence();
   player->addDoubt();
}

/**************************************************************************************************
 * This function checks that the player has a personal project, 5 Confidence, 5 Courage, 5
 * Technical, and 0 doubt points. If these things are all true the applySuccess function is called
 * ***********************************************************************************************/
void Apply::checkApplication(Player *player)
{
   if(player->getDoubt() <= 0 && player->getConfidence() >= 5 && player->getCourage() >= 5
      && player->getTechnical() >= 5 && player->getProject() == true)
   {
	applySuccess(player);
   }

   else
   {
      std::cout << "Your application is missing some key elements." << std::endl;
      std::cout << "Make sure you have 0 Doubt, 5 Confidence, 5 Courage, and 5 Technical points." << std::endl;
      std::cout << "You must also have at least 1 Personal Project." << std::endl;
   }
}
      
/**************************************************************************************************
 * If this function is called the player has gotten a job and the objective has been completed.
 * ************************************************************************************************/
void Apply::applySuccess(Player *player)
{
   std::cout << "Congrats! Your hard work has paid off and you got a job!" << std::endl;     
   player->setJobFound("true");
   Items *j = new Job();
   player->addItem(j);
}
      


