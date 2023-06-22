#pragma once
#include "stdfx.h"
class Player
{
private:
	int damage;
	bool bodySide; // true right, false left
	float speed;
	int life;
	bool attacking;
	int attackRange;
	bool alive;
	bool jumping;
	bool onGround;
	float vGravity;
	float vJump;

	int maxHp;
	float lifePercent;
	sf::RectangleShape frontHpBar;
	sf::RectangleShape backHpBar;

	sf::Texture attackTexture;
	sf::Sprite attackSprite;
	sf::Texture texture;
	sf::Sprite body;
	sf::RenderWindow* window;
	sf::Vector2f oldPosition;
	char path[50];
public:
	Player();
	~Player();
	void initTexture(char* path);
	void initSprite(int sX, int sY, int left, int top, int widht, int high, float xPos, float yPos);
	void render();
	void update();
	void hpBar();
	void move();
	bool attack2();
	void setWindow(sf::RenderWindow* pWindow);
	sf::RenderWindow* getWindow();
	sf::Sprite* getBody();
	void gravity();
	void jumpingUp();
	void damageTaken(int damage);
	void setSpeed(float sP);
	void setLife(int cLife);
	float getSpeed();
	int getLife();
	int getDamage();
	void isOnGround();
	void jumpCollision(sf::Sprite* body2);
	bool getJumping();
};

