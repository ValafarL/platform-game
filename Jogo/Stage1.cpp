#include "Stage1.h"

Stage1::Stage1():
    enemyList(),
    spike(),
    fireball(),
    lightning()
{

    warrior = NULL;
    warrior = new EnemyWarrior();
    archer = NULL;
    archer = new EnemyArcher();
    enemyList.includeElement(warrior);
    enemyList.includeElement(archer);
}

Stage1::~Stage1()
{
}

void Stage1::createScenario()
{
    Element<Characters>* pAux;
    Characters* pCha;
    pAux = enemyList.getFirst();
    while (pAux != NULL)
    {
        pCha = pAux->getElement();
        pCha->setWindow(window);
        pCha->setPlayerBody(player->getBody());
        pCha->setPlayer(player);
        pAux = pAux->getNext();
    }
    collisions.setWindow(window);

    spike.setWindow(window);
    fireball.setWindow(window);
    lightning.setWindow(window);

    tile1.setWindow(window);
    tile2.setWindow(window);
    tile3.setWindow(window);

    tile1.createTile(1, 1, 0, 0, window->getSize().x, 50, 0, window->getSize().y - 50);
    tile2.createTile(1, 1, 0, 0, window->getSize().x - 150, 50, 150, window->getSize().y - 300);
    tile3.createTile(1, 1, 0, 0, window->getSize().x - 150, 50, 0, window->getSize().y - 550);
}

void Stage1::render()
{
    if (spike.update())
    {
        spike.drawBody();
    }
    fireball.drawBody();
    if (lightning.update())
    {
        lightning.drawBody();
    }
    
    tile1.drawBody();
    tile2.drawBody();
    tile3.drawBody();

    player->render();
    player->hpBar();
    player->attack2();
    Element<Characters>* pAux;
    Characters* pChar;

    pAux = enemyList.getFirst();
    while (pAux != NULL)
    {
        pChar = pAux->getElement();
        if (pChar->getLife() > 0)
        {
            pChar->drawBody();
            pChar->render();
        }
        pAux = pAux->getNext();
    }
}

void Stage1::update()
{

    player->update();
    fireball.update();
    Element<Characters>* pAux;
    Characters* pChar;
    pAux = enemyList.getFirst();
    while (pAux != NULL)
    {
        pChar = pAux->getElement();
        if (pChar->getLife() <= 0)
        {
            Element <Characters>* pAux2 = pAux->getNext();
            pChar->dead();
            enemyList.remove(pAux);
            pAux = pAux2;
        }
        else
        {

            collisions.collidingWith(player->getBody(), pChar->getBody());
            pChar->update();
            collisions.collidingWith(pChar->getBody(), player->getBody());
            collisions.collidingWith(pChar->getBody(), tile1.getBody());
            collisions.collidingWith(pChar->getBody(), tile2.getBody());
            collisions.collidingWith(pChar->getBody(), tile3.getBody());
            collisions.windowCollision(pChar->getBody());
            pChar->moveTo(player->getBody(), player);
            pAux = pAux->getNext();
        }

    }
    if (collisions.collideObject(player->getBody(), fireball.getBody()))
    {
        player->damageTaken(fireball.getDamage());
        fireball.setHit();
    }
    if (collisions.collideObject(player->getBody(), spike.getBody()) && spike.getSpikeUp())
    {
        player->damageTaken(spike.getDamage());
        spike.knockback(player->getBody());
    }
    if (collisions.collideObject(player->getBody(), lightning.getBody()) && lightning.getLightningOn())
    {
        player->damageTaken(lightning.damage());
        lightning.setHit(player->getBody());
        lightning.shock(player->getBody());
    }
 
    player->jumpCollision(tile1.getBody());
    player->jumpCollision(tile2.getBody());
    player->jumpCollision(tile3.getBody());

    collisions.collidingWith(player->getBody(), tile1.getBody());
    collisions.collidingWith(player->getBody(), tile2.getBody());
    collisions.collidingWith(player->getBody(), tile3.getBody());

    collisions.windowCollision(player->getBody());

    player->isOnGround();
}

void Stage1::setPlayer(Player* player)
{
    this->player = player;
}
