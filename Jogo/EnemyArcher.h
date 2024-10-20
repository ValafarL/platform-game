#pragma once
#include "Characters.h"
class EnemyArcher : public Characters
{
private:
	bool arrowShot = false;
	int arrowV = 0;
	sf::Clock ACooldownClock;
	const int HEIGHT = 100;
	const int WIDHT = 50;


public:
	EnemyArcher(sf::RenderWindow* window, int posX, int posY, int patrolLeft, int patrolRight, Player* player);
	~EnemyArcher();
	void attack();
	void travelArrow();
	void arrowCollide();
	void update();
	void render();
};

