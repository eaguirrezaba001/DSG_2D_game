#pragma once

class Renderer;

class InputHandler
{
	static InputHandler* m_pInputHandler;
	Renderer& m_renderer;
public:
	InputHandler(Renderer& renderer);
	~InputHandler();

	void initialize();

	void processKeyboard(unsigned char key, int x, int y);
	static void __processKeyboard(unsigned char key, int x, int y);
};

