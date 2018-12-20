#pragma once

#include <string>
#include "Sprite.h"

using namespace std;
class Player : public Sprite
{
	static Player* m_player;
	int score = 0;

public:
	Player();
	Player(string name, const char* texture);
	~Player();

	static Player* get();
	string m_name;
	void shoot();
	int getScore() { return score; };
	void addScore() { score += 100; };
	
	
};
