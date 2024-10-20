#pragma once
#include "Entities.h"
#include "Trap.h"
class SpikeTrap : public Trap
{
private:
	const int DAMAGE = 2;
	const int timeOnInSec = 1;
	const int timeOffInSec = 1;
	sf::Clock spikeClock;
	const int HEIGHT = 15;
	const int WIDHT = 140;
	bool startDelayComplete = false;
	float startDelay;

public:
	SpikeTrap(sf::RenderWindow* window, int posX, int posY, float startDelay = 0.0f);
	~SpikeTrap();
	void render();
	void update();
	void handleCollision(Player* obj);
};

