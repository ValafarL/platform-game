#pragma once
#include "Entities.h"
class Tiles: public Entities
{
private:
	char path[50];

public:
	Tiles();
	~Tiles();
	void createTile(int sX, int sY, int left, int top, int widht, int high, float xPos, float yPos);
};

