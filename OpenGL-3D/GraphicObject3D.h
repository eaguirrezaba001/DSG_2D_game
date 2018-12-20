#pragma once


class GraphicObject3D
{
protected:
	double m_x= 0.0, m_y= 0.0, m_z= 0.0;
	double m_yaw= 0.0, m_pitch= 0.0, m_roll= 0.0;
	double m_scaleX= 1.0, m_scaleY= 1.0, m_scaleZ= 1.0;
public:
	virtual void draw() = 0;

	void setPosition(double x, double y, double z);
	void addPositionOffset(double x, double y, double z);
	void setRotation(double yaw, double pitch, double roll);
	void setScale(double scaleX, double scaleY, double scaleZ);
	void applyMatrix();
};