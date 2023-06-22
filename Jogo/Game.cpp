#include "Game.h"

Game::Game() :
    window(sf::VideoMode(1280, 768), "Game"),
    gameState()
{
    window.setFramerateLimit(60);
    player.setWindow(&window);
    menu.setWindow(&window);
    stage1.setWindow(&window);
    stage1.setPlayer(&player);
    stage1.createScenario();
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
                gameState.setGameState(1);
        }
        else if (gameState.getGameState() == 1)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                gameState.setGameState(0);
        }
    }
}

void Game::update()
{   
    if (gameState.getGameState() == 1)
    {
        stage1.update();
        cout << "CARALHO" << endl;
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
