//-----------------------------------------------------------------
//---------------------------=Includes=----------------------------
//----------------------------------------------------------------
//libraries
#include <SFML/Graphics.hpp>
#include <cstdlib> //gives access to random functions
#include <ctime> //gives access to time functions
#include <string>//gives access to string funcitons


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
	const int NUM_CRITTERS = 5;
	Critter critters[NUM_CRITTERS];
	critters[0].Setup("graphics/panda.png", 5);
	critters[1].Setup("graphics/penguin.png", 10);
	critters[2].Setup("graphics/bear.png", 15);
	critters[3].Setup("graphics/crocodile.png", 20);
	critters[4].Setup("graphics/elephant.png", 25);

	//game font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	//set up score text
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(50, 50);


	//set up title text
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Whack a critter!");
	titleText.setCharacterSize(50);
	titleText.setFillColor(sf::Color::White);
	titleText.setPosition(gameWindow.getSize().x / 2
		- titleText.getLocalBounds().width / 2, 30);

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

			//process input on critters
		    for (int i = 0; i < NUM_CRITTERS; ++i)
			{
				critters[i].input(event);
			}

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


		//see if there is any pending score
		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			score += critters[i].GetPendingScore();
			critters[i].ClearPendingScore();
		}
		scoreText.setString("Score: " + std::to_string(score));

		//-------------------------------------------------
		//--------------=End Update=-----------------------
		//-------------------------------------------------



		//-------------------------------------------------
		//--------------------=Draw=-----------------------
		//-------------------------------------------------

		//clear the window to a single colour
		gameWindow.clear(sf::Color::Cyan);

		//draw everything

		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			critters[i].Draw(gameWindow);
		}
		gameWindow.draw(scoreText);
		gameWindow.draw(titleText);

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