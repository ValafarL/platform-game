#pragma once
#include "Entities.h"
class SpikeTrap : public Entities
{
private:
	int spikeFrame;
	bool spikeUp;
	int damage;
public:
	SpikeTrap();
	~SpikeTrap();
	bool update();
	int getDamage();
	void knockback(sf::Sprite *body);
	bool getSpikeUp();
};

