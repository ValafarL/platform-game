#pragma once
#include "stdfx.h"
#include "Player.h"
#include "Tiles.h"
#include "EnemyWarrior.h"
#include "GameState.h"
#include "List.h"
#include "SpikeTrap.h"
#include "Collisions.h"
#include "Portal.h"
#include "Stage.h"


class Stage1 :public Stage
{
private:
	Portal* portalTC;
	GameState* gameState;
	EnemyWarrior* warrior;
	EnemyWarrior* warrior2;
	EnemyWarrior* warrior3;
	EnemyWarrior* warrior4;
	EnemyWarrior* warrior5;

	sf::RenderWindow* window;
	SpikeTrap* spike;
	SpikeTrap* spike2;
	SpikeTrap* spike3;
	Tiles* tile1;
	Tiles* tile2;
	Tiles* tile3;
public:
	Stage1(sf::RenderWindow* window, Player* p);
	~Stage1();
};

