#include "GraphicObject3D.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

void GraphicObject3D::setPosition(double x, double y, double z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void GraphicObject3D::addPositionOffset(double x, double y, double z)
{
	//TODO
}

void GraphicObject3D::setRotation(double yaw, double pitch, double roll)
{
	m_yaw = yaw;
	m_pitch = pitch;
	m_roll = roll;
}

void GraphicObject3D::setScale(double scaleX, double scaleY, double scaleZ)
{ 
	m_scaleX = scaleX;
	m_scaleY = scaleY;
	m_scaleZ = scaleZ;
}

void GraphicObject3D::applyMatrix()
{
	//TODO
	//apply the transformation matrix of the object
}