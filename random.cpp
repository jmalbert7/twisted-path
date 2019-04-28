#include <iostream>

/***************************************************************************************************
 * This function generates and returns a random number between the minimum and maximum passed to it*
 * ************************************************************************************************/
int randomNumber(int min, int max)
{
   return (std::rand() % (max - min + 1) + min);
}


