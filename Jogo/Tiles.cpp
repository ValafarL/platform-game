#include "Tiles.h"

Tiles::Tiles(sf::RenderWindow* window, int widht, int height, int posX, int posY)
	:Entities(window)
{
	initTexture(this->getPath());
	initSprite(1, 1, 0, 0, widht, height, posX, posY);

}

Tiles::~Tiles()
{
}

void Tiles::createTile(int sX, int sY, int left, int top, int widht, int high, float xPos, float yPos)
{
	initTexture(this->getPath());
	initSprite(sX, sY, left, top, widht, high, xPos, yPos);

}
