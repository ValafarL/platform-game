#pragma once
#include "GameState.h"
class Menu: public GameState
{
private:
	Tiles play;
	char path[50] = "texture/menu/play.png";

public:
	Menu();
	~Menu();
	void createMenu();
	void drawMenu();
	void update();
};

