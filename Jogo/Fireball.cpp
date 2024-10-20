#include "Fireball.h"

Fireball::Fireball(sf::RenderWindow* window, bool side, int startX, int endX, int posX, int posY)
	:Trap(window)
{
	this->side = side;
	this->startX = startX;
	this->endX = endX;
	if (side) {
		speed = 13.f;
	}
	else {
		speed = -13.f;
	}
	char nome[50] = "";
	damage = 0;
	initTexture(nome);
	body.setColor(sf::Color::Yellow);
	hit = false;
	initSprite(1, 1, 0, 0, WIDHT, HEIGHT, posX, posY);
}

Fireball::~Fireball()
{
}

void Fireball::update()
{
	body.move(sf::Vector2f(speed, 0.f));
	if (hit == true)
	{
		damage = 0;
	}
	if (side == true && body.getPosition().x >= endX)
	{
		hit = false;
		damage = 0;
		body.setPosition(startX, body.getPosition().y);
	}
	if (side == false && body.getPosition().x <= endX)
	{
		hit = false;
		damage = 0;
		body.setPosition(startX, body.getPosition().y);
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
