#pragma once

//-----------------------------------------------------------------
//---------------------------=Includes=----------------------------
//-----------------------------------------------------------------
//libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Critter
{
	//-----------------------------------------------------------------
	//-----------------------------=Behaviour=------------------------------
	//-----------------------------------------------------------------

public:

	//Constructor
	Critter();
	
	//Render the Critter to the target
	void Draw(sf::RenderTarget& _target);


	//process input on Critter
	void input(sf::Event _gameEvent);

	//getter for pending score data
	int GetPendingScore();

	//clear pending score
	void ClearPendingScore();
	
	//set the critter type
	void Setup(std::string _textureFile, int _pointValue);

	//-----------------------------------------------------------------
	//-----------------------------=End behaviour=------------------------------
	//-----------------------------------------------------------------


	//-----------------------------------------------------------------
	//-----------------------------=Data=------------------------------
	//-----------------------------------------------------------------
private:
	
	sf::Sprite m_sprite;
	//m_ means "member" of the class
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathsound;
	sf::SoundBuffer m_deathBuffer;
	int m_pendingScore;
	int m_scoreValue;

	//-----------------------------------------------------------------
	//---------------------------=End Data=----------------------------
	//-----------------------------------------------------------------

};//End critter class