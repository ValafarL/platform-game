#pragma once
#include "Trap.h"
#include "Player.h"

class LightningTrap : public Trap
{
private:
	const int DAMAGE = 1;
	const int timeOnInSec = 2;
	const int timeOffInSec = 1;
	sf::Vector2f bodyPosition;
	sf::Clock lightningClock;
	const int HEIGHT = 15;
	const int WIDHT = 128;

public:
	LightningTrap(sf::RenderWindow* window, int posX, int posY);
	~LightningTrap();
	void render();
	void update();
	void handleCollision(Player* obj);
	void shock(Player* obj);
};

