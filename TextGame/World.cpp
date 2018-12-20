#include "stdafx.h"
#include "World.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <fstream>
#include "System.h"
#include "stdafx.h"
#include <stdio.h>
#include <istream>
#include <vector>

World* World::m_pInstance;

void World::ReadFile(std::string filename)
{
	cout << "Reading config file: " << filename << "\n";
	ifstream inputFile;
	char c1, c2;
	inputFile.open(filename, fstream::in);
	if (inputFile.is_open())
	{
		char c = ' ';
		inputFile >> m_width >> c >> m_height >> c >> m_blank >> c >> m_coin >> c >> m_player1 >> c >> m_player2 >> c >> m_wall;
		
		string line;
		
		//load the maze into the vector;
		for (int x = 0; x < m_height; x++) {
			for (int y = 0; y < m_width; y++) {
				inputFile >> c;
				m_maze.push_back(c);
			}
			getline(inputFile, line);
		}
		m_totalCoins = count(m_maze.begin(), m_maze.end(), m_coin);

		inputFile.close();
	}
	else
		cout << "Couldn't open file: " << filename;
}

World::World(std::string nameFile)
{
	m_pInstance = this;

	System::hideCursor();

	//initialize the timer. We want to display the time elapsed since the game began in draw()
	m_timer.start();

	//initalize everything else
	ReadFile(nameFile);
	// init players position
	for (int x = 0; x < m_width; x++) {
		for (int y = 0; y < m_height; y++) {
			if (m_maze[(y*m_width)+x] == m_player1)
				getPlayer1().setpos(x, y);
			else if (m_maze[(y*m_width) + x] == m_player2)
				getPlayer2().setpos(x, y);
		}
	}
	getPlayer1().setid(m_player1);
	getPlayer2().setid(m_player2);
}

World::~World()
{
}

void World::draw()
{

	drawMaze();
	
	//TODO: -write the points each player has
	

	//TODO: -write the time elapsed since the beginning
	//		-set the proper position/color
	std::cout << m_timer.getElapsedTime() << "   ";
}

void World::drawMaze()
{
	System::clear();

	// print scoreboard with players scores and elapsed time
	cout << "\n  ";
	cout << "P1: " << getPlayer1().getcoin();
	cout << "   ";
	cout << "P2: " << getPlayer2().getcoin();
	cout << "   ";
	cout << m_timer.getElapsedTime();
	cout << '\n' << '\n';

	// -draw the maze: walls and each of the cells
	//print the maze in the screen
	cout << ' ' << '|';
	for (int x = 0; x < m_width; x++)
		cout << "-";
	cout << '|' << '\n' << ' ' << '|';
	
	for (int x = 0; x < (m_height*m_width); x++) {
		if (x%m_width == 0 && x != 0)
			cout << '|' << "\n" << ' ' << '|';

		if (m_maze.at(x) == m_blank)
			cout << ' ';
		else
			cout << m_maze.at(x);
	}

	cout << '|' << "\n" << ' ' << '|';
	for (int x = 0; x < m_width; x++)
		cout << "-";
	cout << '|' << ' ' << "\n";

	//we sleep for a while
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
void World::finishGame()
{
	System::clear();

	std::cout << '\n';
	std::cout << " ############################\n ####   ";
	if (getPlayer1().getcoin() < getPlayer2().getcoin())
		std::cout << "PLAYER 2 WIN !";
	else
		std::cout << "PLAYER 1 WIN !";
	std::cout << "   ####\n ############################";

	cout << "\n\n exiting... ";
	for (int countdown = 5; countdown >= 0; countdown--) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1 * 1000));
		cout << countdown;
	}

}

Player& World::getPlayer1()
{
	return a_player1;
}

Player& World::getPlayer2()
{
	return a_player2;
}

int World::getTotalCoins()
{
	return m_totalCoins;
}

int World::getMaxWidth()
{
	return m_width;
}

int World::getMaxHeight()
{
	return m_height;
}

bool World::isCoin(int x, int y)
{
	return (m_maze[(y*m_width) + x] == m_coin);
}

bool World::isWall(int x, int y)
{
	return (m_maze[(y*m_width) + x] == m_wall);
}

bool World::isPlayer(int x, int y)
{
	return (m_maze[(y*m_width) + x] == m_player1)
		|| (m_maze[(y*m_width) + x] == m_player2);
}

void World::clearPosition(int x, int y)
{
	m_maze[(y*m_width) + x] = m_blank;
}
void World::updatePosition(int x, int y, char player)
{
	m_maze[(y*m_width) + x] = player;
}
