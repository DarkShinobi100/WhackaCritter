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

{
	//set up the sprite
	m_texture.loadFromFile("graphics/panda.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand()% sf::VideoMode::getDesktopMode().width, rand() % sf::VideoMode::getDesktopMode().height);
}



void Critter::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
	//pass in the target to draw to
}