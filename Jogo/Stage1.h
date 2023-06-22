#pragma once
#include "stdfx.h"
#include "Player.h"
#include "Entities.h"
#include "Tiles.h"
#include "EnemyWarrior.h"
#include "GameState.h"
#include "List.h"
#include "Element.h"
#include "SpikeTrap.h"
#include "Fireball.h"
#include "LightningTrap.h"
#include "EnemyArcher.h"
#include "Collisions.h"
class Stage1: public GameState
{
private:
	Player* player;
	Collisions collisions;
	EnemyWarrior* warrior;
	EnemyArcher* archer;
	SpikeTrap spike;
	Fireball fireball;
	LightningTrap lightning;
	Tiles tile1;
	Tiles tile2;
	Tiles tile3;
	List<Characters> enemyList;
public:
	Stage1();
	~Stage1();
	void createScenario();
	void render();
	void update();
	void setPlayer(Player *player);
};

