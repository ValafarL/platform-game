#pragma once
#include "stdfx.h"
#include "Player.h"
#include "Entities.h"
#include "Tiles.h"
#include "GameState.h"
#include "Menu.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"


class Game
{
private:
	Player player;
	Stage1 stage1;
	Stage2 stage2;
	Stage3 stage3;
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

