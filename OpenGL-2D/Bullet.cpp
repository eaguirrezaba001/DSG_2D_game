#include "Bullet.h"
#include "Player.h"
#include "Renderer.h"
#include <math.h>
#include"Satan.h"


Bullet::Bullet(double x, double y, const char* texture)
	:AnimatedSprite(texture,5, 2, false)
{
	//int m_direction; //0=UP/1=DOWN
    m_hasImpact = false;
	m_fun = true;
	m_x=x;
	m_y=y;
	setDepth(1.1);


}


Bullet::~Bullet()
{
}

//void moveUp();
//void moveDown();

double Bullet::getPosX() { return m_x; }
double Bullet::getPosY() { return m_y; }

void Bullet::setPos(double x, double y) { m_x = x; m_y = y; }


void Bullet::checkImpact() {
	if (m_fun) {

		for (int x = 0; x < Satan::getInstance()->getNumEnemies() ; x++)
		{
			
			Sprite* theEnemy = (Sprite*)Renderer::get()->getDrawable(string("enemy") + to_string(x)); //get the instance called "enemyX"

			if (theEnemy)
			{

				float distance = sqrt(pow((theEnemy->getX() - m_x), 2) + pow((theEnemy->getY() - m_y), 2)); //magic formula to calculate the distance
				if (distance < (theEnemy->getSize() + m_size)) {
					//Collision!!
					//borrar theEnemy del vector<> que tiene renderer 
					theEnemy->kill();
					kill();
					Satan::getInstance()->killEnemy();
					//sumar un punto
					Player::get()->addScore();
					//borrar la bala (llamar a delSprite) 

					m_fun = false;
					m_hasImpact = true;
					return;
				}
			}
		}	
	}
}

void Bullet::draw(double dt) {
	if (getPosY()>1)
	{
		kill();
	}
	else
	{
		checkImpact();
		setPos(getPosX(),getPosY()+0.01);
		AnimatedSprite::draw(dt);
	}
}