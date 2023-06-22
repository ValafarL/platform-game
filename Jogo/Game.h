#pragma once
#include "stdfx.h"
#include "Player.h"
#include "Entities.h"
#include "Tiles.h"
#include "GameState.h"
#include "Menu.h"
#include "Stage1.h"
class Game
{
private:
	Player player;
	Stage1 stage1;
	GameState gameState;
	sf::RenderWindow window;
	Menu menu;
public:
	Game();
	~Game();
	void processEvents();
	void update();
	void render();
	void run();
};

