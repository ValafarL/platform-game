#include "LightningTrap.h"

LightningTrap::LightningTrap(sf::RenderWindow* window, int posX, int posY)
	:Trap(window)
{
	char nome[50] = "";
	initTexture(nome);
	initSprite(1, 1, 0, 0, 150, 20, 0, 490);
	body.setColor(sf::Color::Magenta);
	trapOn = false;
	canHit = false;
	lightningClock.restart();
	initSprite(1, 1, 0, 0, WIDHT, HEIGHT, posX, posY);
}

LightningTrap::~LightningTrap()
{
}

void LightningTrap::render() {
	if (trapOn) {
		drawBody();
	}
}
void LightningTrap::update()
{
	if (trapOn) {
		if (lightningClock.getElapsedTime().asSeconds() > timeOnInSec) {
			lightningClock.restart();
			trapOn = false;
			canHit = false;
		}
	}
	else {
		if (lightningClock.getElapsedTime().asSeconds() > timeOffInSec) {
			lightningClock.restart();
			trapOn = true;
			canHit = true;
		}
	}
}

void LightningTrap::handleCollision(Player* obj)
{
	if (canHit) {
		obj->damageTaken(DAMAGE);
		canHit = false;
	}
	shock(obj);
}

void LightningTrap::shock(Player* obj)
{
	if (trapOn)
	{
		obj->isShocked = true;
	}
}


