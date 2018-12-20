#pragma once

enum ConsoleColor {White, Blue, Red, Green, Yellow, Black};

class System
{
public:
	System();
	virtual ~System();

	static void clear();
	static void hideCursor();
	static void setCursorPos(int x, int y);
	static void setTextColor(ConsoleColor foregroundColor, ConsoleColor backgroundColor= Black);
	static bool keyHit();
	static char getNextKey();
};

