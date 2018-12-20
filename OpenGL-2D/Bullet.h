#pragma once
#include "AnimatedSprite.h"
class Bullet :
	public AnimatedSprite
{

	//int m_direction; //0=UP/1=DOWN
	bool m_hasImpact;
	bool m_fun;

public:
	Bullet(double x,double y, const char* texture);
	~Bullet();

	//void moveUp();
	//void moveDown();

	double getPosX();
	double getPosY();

	void setPos(double x,double y);
	void checkImpact();
	void draw(double dt);


};




