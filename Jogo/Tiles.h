#pragma once
#include "Entities.h"
class Tiles: public Entities
{
private:
	int height = 50;
	int widht = 70;

public:
	Tiles(sf::RenderWindow* window,int widht, int height , int posX, int posY);
	~Tiles();
	void createTile(int sX, int sY, int left, int top, int widht, int high, float xPos, float yPos);
};

