   #include "stdafx.h"
#include "InputHandler.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Renderer.h"
#include "Player.h"
#include <iostream>

InputHandler* InputHandler::m_pInputHandler = nullptr;

InputHandler::InputHandler(Renderer& renderer): m_renderer(renderer)
{
	m_pInputHandler = this;
}


InputHandler::~InputHandler()
{
}

void InputHandler::initialize()
{
	glutKeyboardFunc(__processKeyboard);
	glutKeyboardUpFunc(__processKeyboardUp);
}


void InputHandler::update() 
{
	//keyboard callback function
	Sprite* thePlayer = (Sprite*)m_renderer.getDrawable("jugador");

	if (spacePressed)
		((Player*)thePlayer)->shoot();
 
	if (leftPressed) {
		if (thePlayer->getX() > -1)
			thePlayer->setPosition(thePlayer->getX() - 0.01, thePlayer->getY());
	}
		

	if (rightPressed) {
		if (thePlayer->getX() <= 1)
			thePlayer->setPosition(thePlayer->getX() + 0.01, thePlayer->getY());		
	}
		
		

}

void InputHandler::__processKeyboard(unsigned char key, int x, int y)
{
	if (m_pInputHandler)
	{
		switch (key)
		{
		case 32: //ASCII KEY SPACE
			m_pInputHandler->spacePressed = true;
			break;
		case 'a':
			m_pInputHandler->leftPressed = true;
			break;
		case 'd':
			m_pInputHandler->rightPressed = true;
			break;
		}

	}
	
}


void InputHandler::__processKeyboardUp(unsigned char key, int x, int y)
{
	
	if (m_pInputHandler->leftPressed)
		m_pInputHandler->leftPressed = false;
	else if (m_pInputHandler->rightPressed)
		m_pInputHandler->rightPressed = false;
	else
		m_pInputHandler->spacePressed = false;



}