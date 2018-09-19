//-----------------------------------------------------------------
//---------------------------=Includes=----------------------------
//-----------------------------------------------------------------
//project includes
#include "Critter.h"


//libraraies include
#include <cstdlib>


Critter::Critter()
//initialisation list
	: m_sprite()
	, m_texture()
	, m_alive(true)
	, m_deathsound()
	, m_deathBuffer()
	, m_pendingScore(0)
	, m_scoreValue(1)

{
	
	//set-up the death sound
	m_deathBuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathsound.setBuffer(m_deathBuffer);
}



void Critter::Draw(sf::RenderTarget& _target)
{
	//if alive then draw the sprites
	if (m_alive == true)
	{
		_target.draw(m_sprite);
		//pass in the target to draw to
	}
}


void Critter::input(sf::Event _gameEvent)
{ //only handle input if alive
	if (m_alive == true)
	{
		
		//check if the event is a click
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{

			//did they click on this critter?
			if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
			{
				//they clicked it!

				//we die
				m_alive = false;

				//play the death sound
				m_deathsound.play();

				//add to pending score
				m_pendingScore += m_scoreValue;

			}
		}//end Event event statement
	}
}


int Critter::GetPendingScore()
{
	return m_pendingScore;
}

//clear pending score
void Critter::ClearPendingScore()
{
	m_pendingScore = 0;
}

//set the critter type
void Critter::Setup(std::string _textureFile, int _pointValue)
{
	//set up the sprite
	m_texture.loadFromFile(_textureFile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width, rand() % sf::VideoMode::getDesktopMode().height);

	//set scores value dependant on image used
	m_scoreValue = _pointValue;

}