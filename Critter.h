#pragma once

//-----------------------------------------------------------------
//---------------------------=Includes=----------------------------
//-----------------------------------------------------------------
//libraries
#include <SFML/Graphics.hpp>


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

	//-----------------------------------------------------------------
	//---------------------------=End Data=----------------------------
	//-----------------------------------------------------------------

};//End critter class