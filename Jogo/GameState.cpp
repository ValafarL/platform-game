#include "GameState.h"

GameState::GameState()
{
    gameState = 0;
}

GameState::~GameState()
{
}

void GameState::setGameState(int gState)
{
    gameState = gState;
}

int GameState::getGameState()
{
    return gameState;
}

void GameState::processEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void GameState::setWindow(sf::RenderWindow* pWindow)
{
    window = pWindow;
}

sf::RenderWindow* GameState::getWindow()
{
    return window;
}
