#pragma once
#include "Characters.h"
class EnemyWarrior: public Characters
{
private:
	bool canAttack = true;
	sf::Clock ACooldownClock;
	float patrolPath;
	const int HEIGHT = 100;
	const int WIDHT = 50;

public:
	EnemyWarrior(sf::RenderWindow* window, int posX, int posY, int patrolLeft, int patrolRight, Player* player);
	~EnemyWarrior();
	void attack() override;
	void updateAttack() override;
	void attackingSide();
};

