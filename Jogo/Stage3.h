#pragma once
#include "stdfx.h"
#include "Player.h"
#include "Tiles.h"
#include "EnemyWarrior.h"
#include "EnemyArcher.h"
#include "EnemyMage.h"
#include "Fireball.h"
#include "LightningTrap.h"
#include "GameState.h"
#include "List.h"
#include "SpikeTrap.h"
#include "Collisions.h"
#include "Portal.h"
#include "Stage.h"

class Stage3 : public Stage
{
protected:
	GameState* gameState;
	sf::RenderWindow* window;
	Portal* portalTC;
	EnemyWarrior* warrior;
	EnemyWarrior* warrior2;
	EnemyWarrior* warrior3;
	EnemyWarrior* warrior4;
	EnemyArcher* archer;
	EnemyArcher* archer2;
	EnemyArcher* archer3;
	EnemyArcher* archer4;
	EnemyMage* mage;
	EnemyMage* mage2;
	Fireball* fireball;
	Fireball* fireball2;
	LightningTrap* lgt;
	LightningTrap* lgt2;
	SpikeTrap* spike;
	SpikeTrap* spike2;
	SpikeTrap* spike3;
	SpikeTrap* spike4;
	Tiles* tile1;
	Tiles* tile2;
	Tiles* tile3;
	Tiles* tile4;
	Tiles* tile5;
	Tiles* tile6;
	Tiles* tile7;
	Tiles* tile8;
public:
	Stage3(sf::RenderWindow* window, Player* p);
	~Stage3();
};


