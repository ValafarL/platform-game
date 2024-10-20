#include "Stage3.h"

Stage3::Stage3(sf::RenderWindow* window, Player* p)
	: Stage(p)
{
    this->window = window;
    player = p;
    mage = new EnemyMage(window, 1270, 0, 0, 0, player);

    warrior = new EnemyWarrior(window, 570, 100, 550, 800, player);
    spike = new SpikeTrap(window, 500, 565,0.8);
    spike2 = new SpikeTrap(window, 640, 565, 1.6);
    spike3 = new SpikeTrap(window, 780, 565, 2.4);
    spike4 = new SpikeTrap(window, 920, 565, 3.2);
    archer = new EnemyArcher(window, 200, 300, 70, 250, player);
    archer2 = new EnemyArcher(window, 400, 300, 450, 800, player);
    archer3 = new EnemyArcher(window, 700, 300, 700, 1100, player);
    lgt = new LightningTrap(window, 270, 580);
    tile8 = new Tiles(window, 300, 20, 0, 250);
    tile1 = new Tiles(window, 128, 20, 1220, 110);
    tile2 = new Tiles(window, 200, 20, 575, 250);
    tile3 = new Tiles(window, 30, 20, 1040, 280);
    tile4 = new Tiles(window, 30, 20, 1250, 450);
    tile5 = new Tiles(window, 1024, 20, 400, 580);
    tile6 = new Tiles(window, 200, 20, 70, 580);
    tile7 = new Tiles(window, 1280, 20, 0, 750);
    portalTC = new Portal(window);

    portalTC->initSprite(1, 1, 0, 0, 130, 120, 100, 100);
    collisions.setWindow(window);

    enemyList.includeElement(mage);
    enemyList.includeElement(warrior);
    enemyList.includeElement(archer);
    enemyList.includeElement(archer2);
    enemyList.includeElement(archer3);
    trapList.includeElement(lgt);
    trapList.includeElement(spike);
    trapList.includeElement(spike2);
    trapList.includeElement(spike3);
    trapList.includeElement(spike4);

    groundList.includeElement(tile1);
    groundList.includeElement(tile2);
    groundList.includeElement(tile3);
    groundList.includeElement(tile4);
    groundList.includeElement(tile5);
    groundList.includeElement(tile6);
    groundList.includeElement(tile7);
    groundList.includeElement(tile8);

    player->getBody()->setPosition(1200, 750);

    NEXT_STAGE = 0;
    portal = portalTC;
}

Stage3::~Stage3()
{
}
