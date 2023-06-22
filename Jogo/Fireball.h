#pragma once
#include "Entities.h"
class Fireball : public Entities
{
private:
	int damage;
	bool hit;
public:
	Fireball();
	~Fireball();
	void update();
	int getDamage();
	void setHit();
};

