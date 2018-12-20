#pragma once

#include <string>
using namespace std;
class Drawable
{

	bool alive = true;

public:
	virtual void draw(double dt) = 0;
	string m_name;

	void setName(string name) { m_name = name; };
	string getName() { return m_name; };

	bool isalive() { return alive; }
	void kill() { alive = false; };
};