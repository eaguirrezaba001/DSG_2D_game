#include "stdafx.h"
#include <iostream>
#include "GameLogic.h"
#include "System.h"
#include "World.h"
#include "Player.h"

GameLogic::GameLogic(World& world)
	: m_world(world)
{
	
}





GameLogic::~GameLogic()
{
}

void GameLogic::processInput()
{
	if (!System::keyHit())
		return; //no keyboard event to be processed


	while (System::keyHit())
	{
		char c = System::getNextKey();
		switch (c)
		{

		case 'a':
			//Do whatever needs to be done when 'a' is pressed
			m_world.getPlayer1().moveLeft();
			break;
		case 's':
			//Do whatever needs to be done when 's' is pressed
			m_world.getPlayer1().moveDown();
			break;
		case 'w':
			//Do whatever needs to be done when 's' is pressed
			m_world.getPlayer1().moveUp();
			break;
		case 'd':
			//Do whatever needs to be done when 's' is pressed
			m_world.getPlayer1().moveRight();
			break;

		case 'j':
			//Do whatever needs to be done when 's' is pressed
			m_world.getPlayer2().moveLeft();
			break;
		case 'k':
			//Do whatever needs to be done when 's' is pressed
			m_world.getPlayer2().moveDown();
			break;
		case 'i':
			//Do whatever needs to be done when 's' is pressed
			m_world.getPlayer2().moveUp();
			break;
		case 'l':
			//Do whatever needs to be done when 's' is pressed
			m_world.getPlayer2().moveRight();
			break;

		case 27:
			//'Esc' key pressed. Exit the game
			//With this command we automatically exit of the program, cause this function is already programmed in a library
			exit(0);
		}
	}
}

bool GameLogic::gameHasEnded()
{
	//TODO: We need to check it the game has ended
	return m_world.getTotalCoins() 
		== (m_world.getPlayer1().getcoin() + m_world.getPlayer2().getcoin());
}