#pragma once

class Renderer;

class InputHandler
{
	static InputHandler* m_pInputHandler;
	Renderer& m_renderer;
public:

	bool leftPressed = false , rightPressed = false, spacePressed = false;

	InputHandler(Renderer& renderer);
	~InputHandler();

	void initialize();

	void update();
	static void __processKeyboard(unsigned char key, int x, int y);
	static void __processKeyboardUp(unsigned char key, int x, int y);

	//bool spacePressed() { return spacePressed; };

};

