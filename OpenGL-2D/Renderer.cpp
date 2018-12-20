#include "stdafx.h"
#include "Renderer.h"
#include "Drawable.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "../3rd-party/glew-2.0.0/src/glew.h"
#include <algorithm>
#include <thread>
#include <chrono>

Renderer* Renderer::m_pRenderer = nullptr;

Renderer::Renderer()
{
	m_pRenderer = this;
	m_frameTimer.start();
}


Renderer::~Renderer()
{
	for (int i = 0; i < m_objects2D.size(); i++)
		delete m_objects2D[i];
}

Renderer* Renderer::get()
{
	return m_pRenderer;
}

void Renderer::initialize(int argc, char** argv)
{
	//INIT GLUT/////////////////////
	////////////////////////////////
	//init window and OpenGL context
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow(argv[0]);
	
	//OpenGL global initializations
	glEnable(GL_DEPTH_TEST);

	//init Glew. We need it to use "modern" features as 3d textures
	glewInit();

	//callback functions
	glutDisplayFunc(__drawScene);
	glutReshapeFunc(__reshapeWindow);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
}

void Renderer::setFrameRate(int framesPerSecond)
{
	m_frameDuration = 1.0 / (double)std::max(1, framesPerSecond);
}

void Renderer::set2DMatrix()
{
	//set projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, 20.0);

	//set modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void Renderer::reshapeWindow(int w, int h)
{
	//Reshape callback function
	m_windowHeight = h;
	m_windowWidth = w;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Renderer::addObject(Drawable* pObj)
{
	m_objects2D.push_back(pObj);
}

void Renderer::delObject(Drawable* pObj1)
{
	m_objects2D.push_back(pObj1);
}

void Renderer::drawScene()
{
	//clean the backbuffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//set the 2d modelview matrix
	set2DMatrix();

	for (auto it = m_objects2D.begin(); it != m_objects2D.end();)
	{
		if (!(*it)->isalive())
		{
			delete (*it);
			it = m_objects2D.erase(it);
		}
		else it++;
	}

	for (auto it = m_objects2D.begin(); it != m_objects2D.end(); ++it)
	{
		(*it)->draw(m_frameDuration);
	}
	double elapsedTime = m_frameTimer.getElapsedTime();
	if (elapsedTime < m_frameDuration)
	{
		double timeAsleep = m_frameDuration - elapsedTime;
		std::this_thread::sleep_for(chrono::duration<double, std::ratio<1>>(timeAsleep)); //sleep until m_frameDuration seconds passed since last frame
		m_frameTimer.getElapsedTime(true); //reset the timer
	}
}


//Nevermind these static functions: auxiliary stuff to fit openGL's callbacks
void Renderer::__drawScene()
{
	if (m_pRenderer)
		m_pRenderer->drawScene();
}
void Renderer::__reshapeWindow(int x, int y)
{
	if (m_pRenderer)
		m_pRenderer->reshapeWindow(x, y);
}

Drawable* Renderer::getDrawable(string name) {
	
	for (int x = 0; x < m_objects2D.size(); x++)
	{
		if (m_objects2D[x]->getName() == name)
		{	
			return m_objects2D[x];
		}
	}
	
	return nullptr;
}