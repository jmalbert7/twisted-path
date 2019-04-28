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


#ifndef APPLY_HPP
#define APPLY_HPP

#include "Space.hpp"
#include "random.hpp"

class Apply : public Space
{
   private:

   public:
	//constructor/destructor
	Apply();
	~Apply();

	//redefine Space pure virtual functions
	virtual void setback(Player *player);
	virtual void positive(Player *player);
	virtual void setPlayerPosition();
	virtual void spaceRound(Player *player);

	//possible outcome events
	void applyFail(Player *player);
	void checkApplication(Player *player);
	void applySuccess(Player *player);
};
#endif
