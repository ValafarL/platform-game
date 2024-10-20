#include "SpikeTrap.h"

SpikeTrap::SpikeTrap(sf::RenderWindow* window, int posX, int posY, float startDelay)
	:Trap(window)
{
	this->startDelay = startDelay;
	char nome[50] = "";
	initTexture(nome);
	body.setColor(sf::Color::Green);
	trapOn = false;
	canHit = false;
	spikeClock.restart();
	initSprite(1, 1, 0, 0, WIDHT, HEIGHT, posX, posY);
}

SpikeTrap::~SpikeTrap()
{
}

void SpikeTrap::render() {
	if (trapOn) {
		drawBody();
	}
}
void SpikeTrap::update()
{
	if (startDelayComplete) {
		if (trapOn) {
			if (spikeClock.getElapsedTime().asSeconds() > timeOnInSec) {
				spikeClock.restart();
				trapOn = false;
				canHit = false;
			}
		}
		else {
			if (spikeClock.getElapsedTime().asSeconds() > timeOffInSec) {
				spikeClock.restart();

				trapOn = true;
				canHit = true;
			}
		}
	}
	else if(spikeClock.getElapsedTime().asSeconds() > startDelay) {
		startDelayComplete = true;
		spikeClock.restart();
	}
}

void SpikeTrap::handleCollision(Player* obj)
{
	if (canHit) {
		obj->damageTaken(DAMAGE);
		canHit = false;
	}
}
