#include "Tiles.h"

Tiles::Tiles()
{
	
}

Tiles::~Tiles()
{
}

void Tiles::createTile(int sX, int sY, int left, int top, int widht, int high, float xPos, float yPos)
{
	initTexture(this->getPath());
	initSprite(sX, sY, left, top, widht, high, xPos, yPos);

}
