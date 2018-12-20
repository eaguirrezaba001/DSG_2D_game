// TextGame.cpp : Main program entry point
//

#include "stdafx.h"
#include "World.h"
#include "GameLogic.h"


int main()
{
	World world("file.csv");
	GameLogic gameLogic(world);

	while (!gameLogic.gameHasEnded())
	{
		world.draw();

		gameLogic.processInput();
	}

	world.finishGame();

    return 0;
}

