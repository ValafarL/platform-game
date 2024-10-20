#pragma once
#include "Entities.h"
#include "Player.h"
class Trap : public Entities
{
protected:
	bool trapOn;
	bool canHit;

public:
	Trap(sf::RenderWindow* window);
	~Trap();
	virtual void update();
	virtual void render();
	virtual void handleCollision(Player* obj);
};

