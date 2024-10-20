#pragma once
#include "Characters.h"
#include "Collisions.h"
class EnemyMage: public Characters
{
protected:
	const int HEIGHT = 100;
	const int WIDHT = 50;
	sf::Clock ACooldownClock;
	sf::Clock AMoveClock;
	sf::Vector2f PPosition;
	sf::Vector2f attackDirection;
	bool attackDirectionCalculated = false;
	Collisions collision;

public:
	EnemyMage(sf::RenderWindow* window, int posX, int posY, int patrolLeft, int patrolRight, Player *player);
	~EnemyMage();
	void update() override;
	void attack() override;
	void calculateAttackDirection();
	void updateAttack() override;
};

