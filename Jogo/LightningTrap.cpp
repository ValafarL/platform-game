#include "LightningTrap.h"

LightningTrap::LightningTrap()
{
	char nome[50] = "";
	initTexture(nome);
	initSprite(1, 1, 0, 0, 150, 20, 0, 490);
	body.setColor(sf::Color::Cyan);
	lightningFrame = 0;
	lightningOn = false;
	hit = false;
	shockFrame = 0;
}

LightningTrap::~LightningTrap()
{
}

bool LightningTrap::update()
{
	lightningFrame = lightningFrame + 1;
	if (lightningFrame >= 120)
	{
		if (lightningOn == true)
		{
			lightningOn = false;
		}
		else
		{
			lightningOn = true;
			hit = false;
		}
		lightningFrame = 0;
	}
	if (lightningOn == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LightningTrap::shock(sf::Sprite* obj)
{
	if (shockFrame <= 60)
	{
		obj->setPosition(sf::Vector2f(bodyPosition.x, bodyPosition.y - 10));
	}
	else
	{
		shockFrame = 0;
	}
}

int LightningTrap::damage()
{
	if (hit == false)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

bool LightningTrap::getLightningOn()
{
	return lightningOn;
}

void LightningTrap::setHit(sf::Sprite* obj)
{
	if (hit == false)
	{
		hit = true;
		bodyPosition = obj->getPosition();
	}
	else
	{
		hit = true;
	}
	
}
