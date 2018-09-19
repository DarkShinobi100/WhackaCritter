//-----------------------------------------------------------------
//---------------------------=Includes=----------------------------
//-----------------------------------------------------------------
//project includes
#include "Critter.h"


Critter::Critter()
//initialisation list
	: m_sprite()
	, m_texture()

{
	//set up the sprite
	m_texture.loadFromFile("graphics/panda.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(300, 300);
}



void Critter::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
	//pass in the target to draw to
}