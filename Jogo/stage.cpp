#include "stage.h"

Stage::Stage(Player* player)
{
}

Stage::~Stage()
{
}

void Stage::render()
{
    portal->drawBody();
    pAux2 = groundList.getFirst();
    while (pAux2 != NULL)
    {
        pTile = pAux2->getElement();
        pTile->drawBody();
        pAux2 = pAux2->getNext();
    }
    pAux3 = trapList.getFirst();
    while (pAux3 != NULL)
    {
        pTrap = pAux3->getElement();
        pTrap->render();
        pAux3 = pAux3->getNext();
    }
    pAux = enemyList.getFirst();
    while (pAux != NULL)
    {
        pChar = pAux->getElement();
        pChar->drawBody();
        pChar->render();
        pAux = pAux->getNext();
    }
    player->render();
}

void Stage::update()
{
    player->update();
    if (player->getEnterPortal() && collisions.collideObject(player->getBody(), portal->getBody())) {
        gameState->setGameState(NEXT_STAGE);
    }
    pAux2 = groundList.getFirst();
    while (pAux2 != NULL)
    {
        pTile = pAux2->getElement();
        player->jumpCollision(pTile->getBody());
        collisions.correctMovementColision(player, pTile);
        pAux2 = pAux2->getNext();
    }
    pAux3 = trapList.getFirst();
    while (pAux3 != NULL)
    {
        pTrap = pAux3->getElement();
        pTrap->update();
        if (collisions.collideObject(pTrap->getBody(), player->getBody())) {
            pTrap->handleCollision(player);
        }
        pAux3 = pAux3->getNext();
    }
    pAux = enemyList.getFirst();
    while (pAux != NULL)
    {
        pChar = pAux->getElement();
        if (pChar->getLife() <= 0)
        {
            Element <Characters>* pAux2 = pAux->getNext();
            enemyList.remove(pAux);
            pChar->dead();
            pAux = pAux2;

        }
        else
        {
            collisions.correctMovementColision(player, pChar);
            pChar->update();
            collisions.correctMovementColision(pChar, player);
            if (player->getAttacking() && player->getAttackingHit() == false) {
                if (collisions.collideObject(pChar->getBody(), player->getAttackArea())) {
                    player->setAttackingHit(true);
                    pChar->damageTaken(player->getDamage());
                }
            }

            pAux2 = groundList.getFirst();
            while (pAux2 != NULL)
            {
                pTile = pAux2->getElement();
                collisions.correctMovementColision(pChar, pTile);
                pAux2 = pAux2->getNext();
            }
            collisions.windowCollision(pChar->getBody());
            if (pChar->charClass != "mage") {
                pChar->verifyPlayerInATTRange();
            }
            collisions.windowCollision(pChar->getBody());
            pChar->updatePosition();
            pAux = pAux->getNext();

        }
    }
    collisions.windowCollision(player->getBody());
    player->isOnGround();
    player->updatePosition();
}

void Stage::setGameState(GameState* gameState)
{
    this->gameState = gameState;
}

void Stage::setPlayerPosition(int x, int y)
{
    player->getBody()->setPosition(x, y);
}
