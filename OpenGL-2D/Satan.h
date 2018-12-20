#pragma once
class Satan
{
	int m_numEnemies;
	//Number of enemies
	double E = 8.00;

	//Start position of X
	const double xmin = -0.7;
	double x = xmin;
	//Start position of Y
	double y = 0.25;

	//Separation between enemies
	double r;

	double t = 0.15;

	//number of columns
	double c = 4.00;
	int id = 0;
	int numEnemies;
	int killedEnemies = 0;
	static Satan* m_pInstance;
public:
	Satan();
	~Satan();

	void createEnemies();
	void setNumEnemies(int numEnemies) { m_numEnemies = numEnemies;  };
	int getNumEnemies() { return m_numEnemies;  };
	int getKilledEnemies() { return killedEnemies; };


	static Satan* getInstance() { return m_pInstance; }
	void killEnemy() { killedEnemies++; };
};

