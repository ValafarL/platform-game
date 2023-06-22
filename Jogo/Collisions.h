#pragma once
#include "stdfx.h"
class Collisions
{
private:
	sf::RenderWindow* window;

public:
	Collisions();
	~Collisions();
	void windowCollision(sf::Sprite* body);
	bool collideObject(sf::Sprite* body, sf::Sprite* body2);
	void collidingWith(sf::Sprite* body, sf::Sprite* body2);
	void setWindow(sf::RenderWindow* window);
};

