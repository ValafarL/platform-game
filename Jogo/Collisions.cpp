#include "Collisions.h"

Collisions::Collisions()
{
}

Collisions::~Collisions()
{
}

void Collisions::windowCollision(sf::Sprite* body)
{
	if (body->getGlobalBounds().top + body->getGlobalBounds().height > window->getSize().y)
	{
		body->setPosition(body->getGlobalBounds().left,
			window->getSize().y - body->getGlobalBounds().height);
	}
	//right
	if (body->getGlobalBounds().left + body->getGlobalBounds().width > window->getSize().x)
	{
		body->setPosition(window->getSize().x - body->getGlobalBounds().width,
			body->getGlobalBounds().top);
	}
	//left
	if (body->getGlobalBounds().left < 0)
	{
		body->setPosition(0,
			body->getGlobalBounds().top);
	}
}


bool Collisions::collideObject(sf::Sprite* body, sf::Sprite* body2)
{
	if (body->getGlobalBounds().left <
		body2->getGlobalBounds().left + body2->getGlobalBounds().width &&
		body->getGlobalBounds().left + body->getGlobalBounds().width >
		body2->getGlobalBounds().left &&
		body->getGlobalBounds().top <
		body2->getGlobalBounds().top + body2->getGlobalBounds().height &&
		body->getGlobalBounds().top + body->getGlobalBounds().height >
		body2->getGlobalBounds().top)
	{

		return true;
	}
	else
	{
		return false;
	}
}

void Collisions::collidingWith(sf::Sprite* body, sf::Sprite* body2)
{
	if (body->getGlobalBounds().left <
		body2->getGlobalBounds().left + body2->getGlobalBounds().width &&
		body->getGlobalBounds().left + body->getGlobalBounds().width >
		body2->getGlobalBounds().left &&
		body->getGlobalBounds().top <
		body2->getGlobalBounds().top + body2->getGlobalBounds().height &&
		body->getGlobalBounds().top + body->getGlobalBounds().height >
		body2->getGlobalBounds().top)
	{
		// down
		if ((body->getGlobalBounds().top + body->getGlobalBounds().height) > body2->getGlobalBounds().top &&
			(body->getGlobalBounds().top + body->getGlobalBounds().height) < (body2->getGlobalBounds().top + (body2->getGlobalBounds().height) / 2))
		{
			int  posY = (body->getGlobalBounds().top + body->getGlobalBounds().height - body2->getGlobalBounds().top);
			body->move(0, -posY);
		}
		//right
		else if (body->getGlobalBounds().left < (body2->getGlobalBounds().left + body2->getGlobalBounds().width) &&
			body->getGlobalBounds().left >(body2->getGlobalBounds().left + (body2->getGlobalBounds().width) / 2))
		{
			int  posX = (body2->getGlobalBounds().left + body2->getGlobalBounds().width - body->getGlobalBounds().left);
			body->move(posX, 0);
		}
		//left
		else if ((body->getGlobalBounds().left + body->getGlobalBounds().width) > body2->getGlobalBounds().left &&
			(body->getGlobalBounds().left + body->getGlobalBounds().width) < (body2->getGlobalBounds().left + (body2->getGlobalBounds().width) / 2))
		{
			int  posX = (body->getGlobalBounds().left + body->getGlobalBounds().width - body2->getGlobalBounds().left);
			body->move(-posX, 0);
		}
	}
}
void Collisions::correctMovementColision(Entities* correctThisEntity, Entities* body2)
{
	if (collideObject(correctThisEntity->getBody(), body2->getBody())) {
		//entity is falling
		if (correctThisEntity->getBody()->getPosition().y > correctThisEntity->getOldY()) {
			int  posY = (correctThisEntity->getBody()->getGlobalBounds().top + correctThisEntity->getBody()->getGlobalBounds().height - body2->getBody()->getGlobalBounds().top);
			if (correctThisEntity->getBody()->getGlobalBounds().top - posY < correctThisEntity->getOldY()){
				posY = 0;
			}
			correctThisEntity->getBody()->move(0, -posY);
		}
		//when entity is moving to the left
		if (correctThisEntity->getBody()->getPosition().x < correctThisEntity->getOldX()) {
			int  posX = (body2->getBody()->getGlobalBounds().left + body2->getBody()->getGlobalBounds().width - correctThisEntity->getBody()->getGlobalBounds().left);
			if (correctThisEntity->getBody()->getGlobalBounds().left + correctThisEntity->getBody()->getGlobalBounds().width + posX > correctThisEntity->getOldX() + correctThisEntity->getBody()->getGlobalBounds().width) {
				posX = 0;
			}
			correctThisEntity->getBody()->move(posX, 0);
		}
		//when entity is moving to the right
		if (correctThisEntity->getBody()->getPosition().x > correctThisEntity->getOldX()) {
			int  posX = (correctThisEntity->getBody()->getGlobalBounds().left + correctThisEntity->getBody()->getGlobalBounds().width - body2->getBody()->getGlobalBounds().left);
			if (correctThisEntity->getBody()->getGlobalBounds().left - posX < correctThisEntity->getOldX()) {
				posX = 0;
			}
			correctThisEntity->getBody()->move(-posX, 0);

		}
	}
}

void Collisions::setWindow(sf::RenderWindow* pWindow)
{
	window = pWindow;
}
