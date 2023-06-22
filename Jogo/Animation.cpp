#include "Animation.h"

Animation::Animation()
{
	animationTimer.restart();
}

Animation::~Animation()
{
}

void Animation::setBody(sf::Sprite* body)
{
	BODY = body;
}

void Animation::animationUpdate()
{
}

void Animation::idle()
{
	if (animationTimer.getElapsedTime().asSeconds() >= 0.2f)
	{
		currentFrame.top = 0;
		currentFrame.left += 50.f;
		if (currentFrame.left >= 200.f)
			currentFrame.left = 0;
		animationTimer.restart();
		BODY->setTextureRect(currentFrame);
	}
}
