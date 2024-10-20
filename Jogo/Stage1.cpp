#include "Stage1.h"

Stage1::Stage1(sf::RenderWindow* window, Player* p)
    : Stage(p)
{
    this->window = window;
    player = p;
    warrior = new EnemyWarrior(window, 500, 300, 200, 900, player);
    warrior2 = new EnemyWarrior(window, 600, 300, 400, 1100, player);
    warrior3 = new EnemyWarrior(window, 300, 550, 200, 1100, player);
    warrior4 = new EnemyWarrior(window, 600, 550, 200, 1100, player);
    warrior5 = new EnemyWarrior(window, 900, 550, 200, 1100, player);
    tile1 = new Tiles(window, 1280, 50, 0, 718);
    tile2 = new Tiles(window, 1130, 50, 150, 468);
    tile3 = new Tiles(window, 1130, 50, 0, 218);
    portalTC = new Portal(window);
    spike = new SpikeTrap(window, 800, 203);
    spike2 = new SpikeTrap(window, 500, 203);
    spike3 = new SpikeTrap(window, 450, 705);

    portalTC->initSprite(1, 1, 0, 0, 130, 120, 1100, 595);
    collisions.setWindow(window);

    enemyList.includeElement(warrior);
    enemyList.includeElement(warrior2);
    enemyList.includeElement(warrior3);
    enemyList.includeElement(warrior4);
    enemyList.includeElement(warrior5);
    groundList.includeElement(tile1);
    groundList.includeElement(tile2);
    groundList.includeElement(tile3);
    trapList.includeElement(spike);
    trapList.includeElement(spike2);
    trapList.includeElement(spike3);

    NEXT_STAGE = 2;
    portal = portalTC;
}

Stage1::~Stage1()
{
}

