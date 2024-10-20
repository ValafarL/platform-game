#pragma once
#include "Trap.h"
class Fireball : public Trap
{
private:
	int damage;
	bool hit;
	bool side;
	float speed;
	int startX;
	int endX;
	const int HEIGHT = 50;
	const int WIDHT = 70;
public:
	Fireball(sf::RenderWindow* window, bool side, int startX, int endX, int posX, int posY);
	~Fireball();
	void update();
	int getDamage();
	void setHit();
};

