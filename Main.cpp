//-----------------------------------------------------------------
//---------------------------=Includes=----------------------------
//----------------------------------------------------------------
//libraries
#include <SFML/Graphics.hpp>
#include <cstdlib> //gives access to random functions
#include <ctime> //gives access to time functions



//project inludes
#include "Critter.h"



int main()
{
	//-------------------------------------------------------------
	//---------------------=Game setup=----------------------------
	//--------------------------------------------------------------


	//Rendom Window creation
	sf::RenderWindow gameWindow; //Makes a variable called gameWindow of the type renderwindow
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Whack a critter!",
		sf::Style::Titlebar | sf::Style::Close);
	
	//Timer functionality
	sf::Clock gameClock; //game clock

	//seed our random number generator
	srand(time(NULL));

	//create an instance of our critter class
	Critter panda;

	//----------------------------------------------------
	//---------------=End game setup=---------------------
	//----------------------------------------------------


	//----------------------------------------------
	//----------------=Game loop=-------------------
	//----------------------------------------------
	//Runs every frame untile the game is closed
	while (gameWindow.isOpen()) // while continues to loop while the (condition) is true
	{

		//------------------------------------------------
		//------------------=Input=-----------------------
		//------------------------------------------------

		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}//end while(event polling loop)


		//-------------------------------------------------
		//-------------=End Input=-------------------------
		//-------------------------------------------------


		//-------------------------------------------------
		//---------------------=Update=--------------------
		//-------------------------------------------------

		//update time
		sf::Time frameTime = gameClock.restart();

		//-------------------------------------------------
		//--------------=End Update=-----------------------
		//-------------------------------------------------



		//-------------------------------------------------
		//--------------------=Draw=-----------------------
		//-------------------------------------------------

		//clear the window to a single colour
		gameWindow.clear(sf::Color::Cyan);

		//draw everything
		panda.Draw(gameWindow);

		//display the window contents to the screen
		gameWindow.display();

		//--------------------------------------------------
		//--------------=End draw=--------------------------
		//--------------------------------------------------

	}//end of game while loop

	//------------------------------------------------------
	//----------------=end game loop=-----------------------
	//------------------------------------------------------

	//exit point for the program
	return 0;

} //end of the main() function