#pragma once

#include "GraphicObject3D.h"

class Sphere: public GraphicObject3D
{
	float m_r, m_g, m_b;
	int m_lat= 10, m_long= 10;
public:
	Sphere();
	~Sphere();

	virtual void draw();
	void setColor(float r, float g, float b);
	void setResolution(int lat, int lon) { m_lat = lat; m_long = lon; }
};

