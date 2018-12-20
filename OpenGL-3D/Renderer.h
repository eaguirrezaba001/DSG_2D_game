#pragma once

class GraphicObject3D;
class Camera;
#include <vector>
using namespace std;

class Renderer
{
	static Renderer* m_pRenderer;
	int m_windowWidth = 0, m_windowHeight = 0;

	vector <GraphicObject3D*> m_objects3D;

	vector <Camera*> m_cameras;
	Camera* m_pActiveCamera = nullptr;

public:
	Renderer();
	~Renderer();

	void initialize(int argc, char** argv);

	void drawScene();

	void addObject(GraphicObject3D* pObj);

	void addCamera(Camera* pCamera);
	Camera* getActiveCamera();

	void reshapeWindow(int x, int y);

	static void __drawScene();
	static void __reshapeWindow(int x, int y);
};

