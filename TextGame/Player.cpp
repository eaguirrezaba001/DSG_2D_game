#include "stdafx.h"
#include "Player.h"
#include "World.h"
//Griffith !!!!!!


Player::Player()
{
	coins = 0;
}

Player::~Player()
{
}


void Player::moveUp()
{
	if ((this->getY()>0 )
		&& !World::getInstance()->isWall(c_x, c_y - 1)
		&& !World::getInstance()->isPlayer(c_x, c_y - 1))
	{
			World::getInstance()->clearPosition(c_x, c_y); 
			if (World::getInstance()->isCoin(c_x, c_y - 1))
				coins++;
			c_y--;
	}
	World::getInstance()->updatePosition(c_x, c_y, m_player);
}

void Player::moveDown()
{ 
	if ((this->getY() < World::getInstance()->getMaxHeight()-1)
		&& !World::getInstance()->isWall(c_x, c_y + 1)
		&& !World::getInstance()->isPlayer(c_x, c_y + 1))
	{
		World::getInstance()->clearPosition(c_x, c_y);
		if (World::getInstance()->isCoin(c_x, c_y + 1))
			coins++;
		c_y++; 
	}
		World::getInstance()->updatePosition(c_x, c_y, m_player);
}

void Player::moveRight()
{
	if ((this->getX() < World::getInstance()->getMaxWidth()-1)
		&& !World::getInstance()->isWall(c_x + 1, c_y)
		&& !World::getInstance()->isPlayer(c_x + 1, c_y))
	{
		World::getInstance()->clearPosition(c_x, c_y);
		if (World::getInstance()->isCoin(c_x + 1, c_y))
			coins++;
		c_x++;
	}
		World::getInstance()->updatePosition(c_x, c_y, m_player);
}

void Player::moveLeft()
{
	if ((this->getX() > 0)
		&& !World::getInstance()->isWall(c_x - 1, c_y)
		&& !World::getInstance()->isPlayer(c_x - 1, c_y))
	{
		World::getInstance()->clearPosition(c_x, c_y);
		if (World::getInstance()->isCoin(c_x - 1, c_y))
			coins++;
		c_x--;
	}
		World::getInstance()->updatePosition(c_x, c_y, m_player);
}

int Player::getX() {

	return c_x;
}

int Player::getY() {

	return c_y;
}

int Player::getcoin() {

	return coins;
}

void Player::addcoin(){

	coins++;
}

void Player::setpos(int x, int y) {

	c_x = x;
	c_y = y;

}

void Player::setid(char id)
{
	m_player = id;
}
