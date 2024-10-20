#include "Trap.h"

Trap::Trap(sf::RenderWindow* window)
	:Entities(window)
{
}

Trap::~Trap()
{
}

void Trap::update()
{
}

void Trap::render()
{
	drawBody();
}

void Trap::handleCollision(Player* obj)
{
}
