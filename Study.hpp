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

#ifndef STUDY_HPP
#define STUDY_HPP

#include "Space.hpp"
#include "random.hpp"
#include "Items.hpp"
#include "Degree.hpp"
#include "ProfessionalContact.hpp"


class Study : public Space
{
   private:

   public:
	//constructor/destructor
	Study();
	~Study();

	//redefine Space pure virtual functions
	virtual void setback(Player *player);
	virtual void positive(Player *player);
	virtual void setPlayerPosition();
	virtual void spaceRound(Player *player);

	//possible outcome events
	bool randomEvent();
	void challengingClass(Player *player);
	void addStudyPoint(Player *player);
	void gainNetworking(Player *player);
	void gainProfessionalContact(Player *player);
	void completeClass(Player *player);
	void network(Player *player);
	void gainDegree(Player *player);
	void gainReference(Player *player);
};
#endif
