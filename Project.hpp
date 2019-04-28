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

#ifndef PROJECT_HPP
#define PROJECT_HPP

#include "Space.hpp"
#include "random.hpp"
#include "Items.hpp"
#include "PersonalProject.hpp"


class Project : public Space
{
   private:

   public:
	//constructor/destructor
	Project();
	~Project();

	//redefine Space pure virtual functions
	virtual void positive(Player *player);
	virtual void setPlayerPosition();
	virtual void spaceRound(Player *player);
	virtual void setback(Player *player){};

	//possible outcome events
	void gainProject(Player *player);
};
#endif
