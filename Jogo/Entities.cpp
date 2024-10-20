#include "Entities.h"

Entities::Entities(sf::RenderWindow* window):
	texture(),
	body()
{
	this->window = window;
}

Entities::~Entities()
{
}

void Entities::setWindow(sf::RenderWindow* mWindow)
{
	window = mWindow;
}

sf::RenderWindow* Entities::getWindow()
{
	return window;
}

void Entities::initTexture(char* path)
{
	if (!texture.loadFromFile(path))
	{
		cout << "FAILED LOADING PNG" << endl;
	}
}

void Entities::initSprite(int sX, int sY, int left, int top, int widht, int high, float xPos, float yPos)
{
	body.setTexture(texture);
	body.setTextureRect(sf::IntRect(left, top, widht, high));
	body.setScale(sX, sY);
	body.setPosition(xPos, yPos);
}

sf::Sprite* Entities::getBody()
{
	return &body;
}

void Entities::drawBody()
{
	window->draw(body);
}

void Entities::setPath(const  char *pPath)
{
	strcpy_s(path, pPath);

}

char* Entities::getPath()
{
	return path;
}

float Entities::getOldX()
{
	return oldX;
}

float Entities::getOldY()
{
	return oldY;
}

void Entities::updatePosition()
{
	oldX = body.getPosition().x;
	oldY = body.getPosition().y;
}
