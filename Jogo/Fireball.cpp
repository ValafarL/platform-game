#include "Fireball.h"

Fireball::Fireball()
{
	char nome[50] = "";
	damage = 1;
	initTexture(nome);
	initSprite(1, 1, 0, 0, 80, 50, -50, 400);
	body.setColor(sf::Color::Yellow);
	hit = false;
}

Fireball::~Fireball()
{
}

void Fireball::update()
{
	body.move(sf::Vector2f(13.f, 0.f));
	if (hit == true)
	{
		damage = 0;
	}
	if (body.getPosition().x >= 1280)
	{
		hit = false;
		damage = 1;
		body.setPosition(-50, 400);
	}
}

int Fireball::getDamage()
{
	return damage;
}

void Fireball::setHit()
{
	hit = true;
}
