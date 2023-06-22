#pragma once
#include "stdfx.h"
class Animation
{
protected:
	sf::Clock animationTimer;
	sf::IntRect currentFrame;
	sf::Sprite *BODY;
public:
	Animation();
	~Animation();
	void setBody(sf::Sprite* body);
	void animationUpdate();
	void idle();
};

