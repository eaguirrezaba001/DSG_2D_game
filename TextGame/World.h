#pragma once
#include "Timer.h"
#include "Player.h"
#include <string>
#include <vector>
using namespace std;

class World
{
	static World* m_pInstance;

	Timer m_timer;
	Player a_player1;
	Player a_player2;

	int m_width = 0, m_height = 0, m_totalCoins = 0;
	char m_blank = ' ', m_coin = ' ', m_player1 = ' ', m_player2 = ' ', m_wall = ' ';
	vector<char> m_maze;

	void drawMaze();
	void ReadFile(std::string filename);

public:
	World(string nameFile);
	~World();

	Player& getPlayer1();
	Player& getPlayer2();
	int getTotalCoins();
	int getMaxWidth();
	int getMaxHeight();
	bool isCoin(int x, int y);
	bool isWall(int x, int y);
	bool isPlayer(int x, int y);
	void clearPosition(int x, int y);
	void updatePosition(int x, int y, char player);

	void draw();
	void finishGame();

	static World* getInstance() { return m_pInstance; }
};