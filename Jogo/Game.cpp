#include "Game.h"

Game::Game() :
    window(sf::VideoMode(1280, 768), "Game"),
    stage1(&window, &player),
    stage2(&window, &player),
    stage3(&window, &player),
    gameState(),
    player(&window)
{

    window.setFramerateLimit(60);
    player.setWindow(&window);
    menu.setWindow(&window);
    
    stage1.setGameState(&gameState);
    stage2.setGameState(&gameState);
    stage3.setGameState(&gameState);
    
    menu.createMenu();
}

Game::~Game()
{

}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {

            window.close();
        }
        if (gameState.getGameState() == 0)
        {
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                gameState.setGameState(2);
        }
        else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                gameState.setGameState(0);
        }
    }
}

void Game::update()
{   
    if (player.getLife() > 0) {
        if (gameState.getGameState() != stateChanged) {
            changeStage();
        }
        stateChanged = gameState.getGameState();
        if (gameState.getGameState() == 1)
        {
            stage1.update();
        }
        else if (gameState.getGameState() == 2)
        {
            stage2.update();
        }
        else if (gameState.getGameState() == 3)
        {
            stage3.update();
        }
    }
}

void Game::render()
{
    window.clear();
    
    if (gameState.getGameState() == 0)
    {
        menu.drawMenu();
    }
    else if (gameState.getGameState() == 1)
    {
        stage1.render();
    }
    else if (gameState.getGameState() == 2)
    {
        stage2.render();
    }
    else if (gameState.getGameState() == 3)
    {
        stage3.render();
    }
    window.display();
}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::changeStage()
{
    if (gameState.getGameState() == 1)
    {
        stage1.setPlayerPosition(50, 50);
    }
    else if (gameState.getGameState() == 2)
    {
        stage2.setPlayerPosition(0, 50);
    }
    else if (gameState.getGameState() == 3)
    {
        stage3.setPlayerPosition(1200, 750);
    }
}
