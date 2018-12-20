#pragma once

#include "Drawable.h"
#include <string>

using namespace std;
class Sprite: public Drawable
{
protected:
	unsigned int m_textureId;

	float m_r, m_g, m_b;
	
	double m_x= 0.0, m_y= 0.0; //position around which the quad is drawn

	double m_depth = 1.0; // the renderer draws depths in range [1.0,20.0]

	double m_size= 1.0; //size of the quad

	double m_angle= 0.0; //rotation angle



public:
	Sprite(const char* texture );
	~Sprite();

	virtual void draw(double dt);
	void setColor(float r, float g, float b);
	void setPosition(double x, double y);
	void setDepth(double depth);
	void setRotation(double angle);
	void setSize(double size);
	double getSize() { return m_size; };
	double getX() { return m_x; };
	double getY() { return m_y; };
	double getDepth() { return m_depth; };
	

};

