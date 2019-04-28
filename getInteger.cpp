/***************************************************************************************************
 * This function retrieves an integer from the user, validates that the user entered an integer
 * and passes the integer back to the calling function.
 * ************************************************************************************************/
int getInteger()
{
   std::cout << "Please enter the integer that corresponds to your menu choice " << std::endl;
   std::cout << "by typing the integer and pressing the enter key. " << std::endl;

   int choice = 0;
   std::string input = "";

   while(true)
   {
      getline(std::cin, input);
      std::stringstream myStream(input);
      if(isInteger(input) && myStream >> choice)
         break;

      std::cout << "You must enter an integer" << std::endl;
   }

   return choice;
}

int getInteger(int min, int max)
{
   std::cout << "Please enter an integer " << min << " through " << max << std::endl;
   std::cout << "by typing the integer and pressing the enter key. " << std::endl;

   int choice = 0;
   std::string input = "";

   while(true)
   {
      getline(std::cin, input);
      std::stringstream myStream(input);
      if(isInteger(input) && myStream >> choice)
      {
         if(choice >= min && choice <= max)
         break;
      }
      std::cout << "You must enter an integer" << std::endl;
   }

   return choice;
}
/****************************************************************************************************
 * This integer checks that a string passed to it is a positive integer
 * *************************************************************************************************/
bool isInteger(const std::string& s)
{
   std::string::const_iterator itr = s.begin();
   while(itr != s.end() && isdigit(*itr))
      ++itr;
   return !s.empty() && itr == s.end();
}
