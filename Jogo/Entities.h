#pragma once
#include "stdfx.h"
class Entities
{
protected:
	sf::Texture texture;
	sf::Sprite body;
	sf::RenderWindow* window;
	char path[50];
	float oldX;
	float oldY;

public:
	Entities(sf::RenderWindow* window);
	~Entities();
	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();
	void initTexture(char* path);
	void initSprite(int sX, int sY, int left, int top, int widht, int height, float xPos, float yPos);
	sf::Sprite* getBody();
	void drawBody();
	void setPath(const char* pPath);
	char* getPath();
	float getOldX();
	float getOldY();
	void updatePosition();

};

