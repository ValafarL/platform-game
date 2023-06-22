#pragma once
#include "stdfx.h"
#include "Entities.h"
#include "Tiles.h"
#include "EnemyWarrior.h"
#include "Player.h"
class GameState
{
protected:
	int gameState;
	sf::RenderWindow* window;

public:
	GameState();
	~GameState();
	void setGameState(int gState);
	int getGameState();
	void processEvents();
	void setWindow(sf::RenderWindow* pWindow);
	sf::RenderWindow* getWindow();
};

