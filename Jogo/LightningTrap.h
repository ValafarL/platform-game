#pragma once
#include "Entities.h"
class LightningTrap : public Entities
{
private:
	int lightningFrame;
	bool lightningOn;
	bool hit;
	sf::Vector2f bodyPosition;
	int shockFrame;
public:
	LightningTrap();
	~LightningTrap();
	bool update();
	void shock(sf::Sprite* obj);
	int damage();
	bool getLightningOn();
	void setHit(sf::Sprite* obj);
};

