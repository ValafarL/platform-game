#pragma once
#include "stdfx.h"
#include "Player.h"
#include "Tiles.h"
#include "EnemyWarrior.h"
#include "EnemyArcher.h"
#include "Fireball.h"
#include "LightningTrap.h"
#include "GameState.h"
#include "List.h"
#include "SpikeTrap.h"
#include "Collisions.h"
#include "Portal.h"
#include "Entities.h"
#include "Trap.h"
#include "EnemyMage.h"
#include "Stage.h"


class Stage2 : public Stage
{
private:
	GameState* gameState;
	sf::RenderWindow* window;
	Portal* portalTC;

	EnemyWarrior* warrior;
	EnemyWarrior* warrior2;

	EnemyArcher* archer;
	EnemyArcher* archer2;
	EnemyArcher* archer3;

	EnemyMage* mage1;

	Fireball* fireball;
	Fireball* fireball2;

	LightningTrap* lgt;
	LightningTrap* lgt2;

	SpikeTrap* spike;

	Tiles* tile1;
	Tiles* tile2;
	Tiles* tile3;
	Tiles* tile4;
	Tiles* tile5;
	Tiles* tile6;
public:
	Stage2(sf::RenderWindow* window, Player* p);
	~Stage2();
};

