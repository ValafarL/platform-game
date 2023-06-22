#include "Collisions.h"

Collisions::Collisions()
{
}

Collisions::~Collisions()
{
}

void Collisions::windowCollision(sf::Sprite* body)
{
	//up
	if (body->getGlobalBounds().top < 0)
	{
		body->setPosition(body->getGlobalBounds().left,
			0);
	}
	//down
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
		////up
		//else if (jumping)
		//{
		//	body->move(0, (body2->getGlobalBounds().top +
		//		body2->getGlobalBounds().height +
		//		body->getGlobalBounds().height) - (body->getGlobalBounds().top + body->getGlobalBounds().height));
		//}
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

void Collisions::setWindow(sf::RenderWindow* pWindow)
{
	window = pWindow;
}
