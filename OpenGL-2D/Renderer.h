#pragma once

class Drawable;
#include <vector>
#include <string>
#include "Sprite.h"


using namespace std;
#include "Timer.h"

class Renderer
{
	static Renderer* m_pRenderer;
	int m_windowWidth = 0, m_windowHeight = 0;
	double m_frameDuration = 0.0;
	Timer m_frameTimer;
	vector <Drawable*> m_objects2D;
	vector <Drawable*> m_deadObjects2D;

	void set2DMatrix();
public:
	Renderer();
	~Renderer();

	void initialize(int argc, char** argv);

	void setFrameRate(int framesPerSecond);

	static Renderer* get(); //this method returns the only instance to the renderer. Needs to be called after the constructor

	void drawScene();
	void addObject(Drawable* pObj);
	void delObject(Drawable* pObj1);
	Drawable* getDrawable(string name);
	void reshapeWindow(int x, int y);
	vector <Drawable*> getObjectsInRenderer() { return m_objects2D; }; //posiblemente eliminemos este metodo...
	int numPrintedObjects() { return m_objects2D.size(); };

	static void __drawScene();
	static void __reshapeWindow(int x, int y);
};

