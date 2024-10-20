#include "Stage2.h"

Stage2::Stage2(sf::RenderWindow* window, Player* p)
    : Stage(p)
{
    this->window = window;
    player = p;
    archer = new EnemyArcher(window, 150, 100, 10, 450, player);
    archer2 = new EnemyArcher(window, 1000, 100, 800, 1270, player);
    archer3 = new EnemyArcher(window, 600, 600, 500, 800, player);
    warrior = new EnemyWarrior(window, 150, 600, 300, 1000, player);
    warrior2 = new EnemyWarrior(window, 1180, 600, 300, 1000, player);
    spike = new SpikeTrap(window, 800, 203);
    lgt = new LightningTrap(window, 0, 480);
    lgt2 = new LightningTrap(window, 1152, 480);
    fireball = new Fireball(window, true, -50, 1280, -50, 410);
    fireball2 = new Fireball(window, false, 1280, -50, 1280, 410);
    tile1 = new Tiles(window, 128, 20, 0, 110);
    tile2 = new Tiles(window, 128, 20, 1152, 110);
    tile3 = new Tiles(window, 448, 20, 0, 250);
    tile4 = new Tiles(window, 448, 20, 832, 250);
    tile5 = new Tiles(window, 1024, 20, 128, 480);
    tile6 = new Tiles(window, 1280, 20, 0, 750);
    portalTC = new Portal(window);

    portalTC->initSprite(1, 1, 0, 0, 130, 120, 580, 625);
    collisions.setWindow(window);

    enemyList.includeElement(archer);
    enemyList.includeElement(archer2);
    enemyList.includeElement(archer3);
    enemyList.includeElement(warrior);
    enemyList.includeElement(warrior2);
    trapList.includeElement(spike);
    trapList.includeElement(fireball);
    trapList.includeElement(fireball2);
    trapList.includeElement(lgt);
    trapList.includeElement(lgt2);

    groundList.includeElement(tile1);
    groundList.includeElement(tile2);
    groundList.includeElement(tile3);
    groundList.includeElement(tile4);
    groundList.includeElement(tile5);
    groundList.includeElement(tile6);

    NEXT_STAGE = 3;
    portal = portalTC;
}

Stage2::~Stage2()
{
}
