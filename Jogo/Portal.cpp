#include "Portal.h"

Portal::Portal(sf::RenderWindow* window)
	:Entities(window)
{
	char nome[50] = "texture/portal";
	initTexture(nome);
	body.setColor(sf::Color::Magenta);
}

Portal::~Portal()
{
}
