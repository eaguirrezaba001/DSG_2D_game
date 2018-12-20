#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Player.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "AnimatedSprite.h"
#include "Text.h"
#include "Timer.h"
#include <iostream>
#include <thread>
#include <conio.h>
#include "../3rd-party/SoundManager/SoundManager.h" //relative path to the main header
#include "Satan.h"

int main(int argc, char** argv)
{
	SoundManager soundManager;
	SoundManager* pSoundManager = SoundManager::getInstance();
	pSoundManager->setVerbose(true);
	// TODO uncomment for background music
//	pSoundManager->createAudioObject("snd/soundtrack-01.wav");
	pSoundManager->createAudioObject("snd/cannon.wav");
	//pSoundManager->createAudioObject("snd/fireball.wav");
	//pSoundManager->createAudioObject("snd/explosion.wav");

	int audioObjBg = pSoundManager->getAudioObjectId("snd/soundtrack-01.wav");
	// TODO uncomment for background music
//	pSoundManager->play(audioObjBg, 1.f);
	system("cls");
	std::cout << "  _________                          \n";
	std::cout << " /   _____/__________    ____  ____  \n";
	std::cout << " \_____   \\ ____ \\__  \\ _/ ___\\/ __ \\ \n";
	std::cout << " /        \\  |_> > __ \\   \\__\\  ___/ \n";
	std::cout << "/_______  /   __(____  /\\___  >___  >\n";
	std::cout << "        \\/|__|       \\/     \\/    \\/ \n\n\n";

	std::cout << "         .__                         .___                   \n";
	std::cout << "         |__| _______  _______     __| _/___________  ______\n";
	std::cout << "         |  |/    \\  \\/ /\\__  \\   / __ |/ __ \\_  __ \\/  ___/\n";
	std::cout << "         |  |   |  \\   /  / __ \\_/ /_/ \\  ___/|  | \\/\\___ \\ \n";
	std::cout << "         |__|___|  /\\_/  (____  /\\____ |\\___  >__|  /____  >\n";
	std::cout << "                 \\/           \\/      \\/    \\/           \\/ \n\n\n\n";

	std::cout << "                 Insert 25pts to start the game!!! (or press any key)";
	getch();
	system("cls");

	Renderer renderer;
	renderer.setFrameRate(30);
	InputHandler inputHandler(renderer);
	
	renderer.initialize(argc, argv);
	inputHandler.initialize();
	
	// set the background with the highest depth
	Sprite* bg = new Sprite("img/background.jpg");
	bg->setDepth(10);
	renderer.addObject(bg);

	//test objects
	Player* jugador = new Player("jugador", "img/fighter-01.png");
	renderer.addObject(jugador);
	Satan* satanas = new Satan;
	satanas->createEnemies();


	
	//number of columns
	double c = 4.00;





	Text2D *Text2D11 = new Text2D("Player1textName",-0.125,-0.8,1.5);
	Text2D11->setColor(13, 120, 254);
	renderer.addObject(Text2D11);

	Timer time;
	time.start();

	Text2D *Text2D12 = new Text2D("TimerP", 0.5, -0.8, 1.5);
	Text2D12->setColor(13, 120, 254);
	renderer.addObject(Text2D12);
	

	while (1)
	{
		bool gameOver = false;
		Text2D11->setText("Points: "+to_string(jugador->getScore()));
		Text2D12->setText("Time: " + to_string((int)time.getElapsedTime()));
		
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();
		inputHandler.update();
		if (inputHandler.spacePressed) {
			int audioObjShoot = pSoundManager->getAudioObjectId("snd/cannon.wav");
			pSoundManager->play(audioObjShoot, 1.f);
		}


	
		if (Satan::getInstance()->getNumEnemies() <= Satan::getInstance()->getKilledEnemies()) {
			gameOver = true;

			Sprite* gameover = new Sprite("img/you-win.jpg");
			gameover->setDepth(1);
			renderer.addObject(gameover);
		}
		for (int id= 0; id<satanas->getNumEnemies(); id++)
		{
				Sprite* theEnemy = (Sprite*)renderer.getDrawable(string("enemy") + to_string(id));
				if (theEnemy != nullptr)
				{
					if (theEnemy->getY() >= -0.25) {
						theEnemy->setPosition(theEnemy->getX(), theEnemy->getY() - 0.0001);
					}
					
					else {
						gameOver = true;

						Sprite* gameover = new Sprite("img/game-over.png");
						gameover->setDepth(1.01);
						renderer.addObject(gameover);
					}
				}
							
		}  
		


		//RENDER////////////////////
		////////////////////////////



		glutPostRedisplay();
		glutSwapBuffers();
		if (gameOver)
			break;
	}
   
	glutMainLoopEvent();
	glutPostRedisplay();
	glutSwapBuffers();
	
	cout << "\n\n exiting... ";
	for (int countdown = 5; countdown >= 0; countdown--) {
		this_thread::sleep_for(std::chrono::milliseconds(1 * 1000));
		cout << countdown;
	}



	return 0;

}
