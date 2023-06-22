#include "SpikeTrap.h"

SpikeTrap::SpikeTrap()
{
	char nome[50] = "";
	initTexture(nome);
	initSprite(1, 1, 0, 0, 140, 15, 600, 203);
	body.setColor(sf::Color::Green);
	spikeFrame = 0;
	spikeUp = false;
	damage = 2;
}

SpikeTrap::~SpikeTrap()
{
}

bool SpikeTrap::update()
{
	spikeFrame = spikeFrame + 1;
	if (spikeFrame >= 30)
	{
		if (spikeUp == true)
		{
			spikeUp = false;
		}
		else
		{
			spikeUp = true;
		}
		spikeFrame = 0;
	}
	if (spikeUp == true)
	{
		return true;
	}
	else
	{
		return false;
	}

}

int SpikeTrap::getDamage()
{
	return damage;
}

void SpikeTrap::knockback(sf::Sprite * pBody)
{
	if (pBody->getGlobalBounds().left + (pBody->getGlobalBounds().width / 2)
		< this->body.getGlobalBounds().left + (this->body.getGlobalBounds().width / 2))
	{
		pBody->move(sf::Vector2f((this->body.getGlobalBounds().left - (pBody->getGlobalBounds().left
			+ pBody->getGlobalBounds().width + 30)), 0));

	}
	else
	{
		pBody->move(sf::Vector2f(((this->body.getGlobalBounds().left + 
			this->body.getGlobalBounds().width + 30)- (pBody->getGlobalBounds().left)), 0));
	}
}

bool SpikeTrap::getSpikeUp()
{
	return spikeUp;
}
