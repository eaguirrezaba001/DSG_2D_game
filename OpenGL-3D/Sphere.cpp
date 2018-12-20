#include "stdafx.h"
#include "Sphere.h"


Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

void Sphere::setColor(float r, float g, float b)
{
	m_r = r;
	m_g = g;
	m_b = b;
}

#define MATH_PI 3.1415
#define RADIUS 1.0

void Sphere::draw()
{
	glDisable(GL_TEXTURE);
	glColor3f(m_r, m_g, m_b);

	int i, j;
	for (i = 0; i <= m_lat; i++)
	{
		double lat0 = MATH_PI * (-double(0.5) + (double)(i - 1) / m_lat);
		double z0 = RADIUS*sin(lat0);
		double zr0 = RADIUS*cos(lat0);

		double lat1 = MATH_PI * (-double(0.5) + (double)i / m_lat);
		double z1 = RADIUS*sin(lat1);
		double zr1 = RADIUS*cos(lat1);

		glBegin(GL_QUAD_STRIP);
		for (j = 0; j <= m_long; j++)
		{
			double lng = 2 * MATH_PI * (double)(j - 1) / m_long;
			double x = cos(lng);
			double y = sin(lng);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(x * zr1, y * zr1, z1);
			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(x * zr0, y * zr0, z0);
		}
		glEnd();
	}
}