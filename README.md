# twisted-path
Fun little game to represent my Twisted Path to becoming a developer

I submitted this as my final project for my C++ programming class. This is a board game in which the player must traverse different 
spaces to collect skill points and objects that will launch them into their software development career. The ultimate objective of 
the game is to apply for and obtain a full time job in the field in less than 20 steps. However, as in life, there are challenges
and setbacks that the player will have to overcome to win the game.

The game is implemented by a grid of Study, Project, and Apply spaces which inherit from the abstact Space class. The spaces are linked 
in a grid via pointers to provide a linked list structure. As you play you will pick up objects like Personal Project or Professional
Contact, etc, which are also class objects that inherit from the abstract class Items. You can view your skill points and achieved objects
at any time by selecting the appropriate menu option. 

In each space you land on you will select a number based on the prompt, a die is rolled and if the die matches your number a setback on
your journey will occur. Depending on the type of space you are on this will usually mean using up a term with no points or objects 
acquired. Project spaces have no setbacks while Study spaces are relatively low risk and the Apply space is the highest risk. 


