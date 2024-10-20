#pragma once
#include "stdfx.h"
#include "Tiles.h"
#include "Trap.h"
#include "List.h"
#include "Characters.h"
#include "Player.h"
#include "Collisions.h"
#include "GameState.h"
#include "Portal.h"




class Stage
{
protected:
	Player* player;
	GameState* gameState;
	int NEXT_STAGE = 0;
	Collisions collisions;
	Portal *portal;

	Element<Characters>* pAux;
	Characters* pChar;
	Element<Tiles>* pAux2;
	Tiles* pTile;
	Element<Trap>* pAux3;
	Trap* pTrap;

	List<Characters> enemyList;
	List<Tiles> groundList;
	List<Trap> trapList;
public:
	Stage(Player* player);
	~Stage();
	void render();
	void update();
	void setGameState(GameState* gameState);

};

