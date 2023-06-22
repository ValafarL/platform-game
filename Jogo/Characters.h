#pragma once
#include "stdfx.h"
#include "Entities.h"
#include "List.h"
#include "Player.h"
class Characters:public Entities
{
protected:
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
	Player *player;
	sf::Clock jumpingTimer;
	sf::Texture attackTexture;
	sf::Sprite attackSprite;
	sf::Sprite* playerBody;


public:
	Characters();
	~Characters();
	virtual void render();
	virtual void update();

	// collisions
	
	//movement
	virtual void move();
	void moveTo(sf::Sprite* pBody, Player* player);
	void gravity();
	void jumpingUp();

	//gets
	float getSpeed();
	int getLife();
	int getDamage();

	//sets
	void setSpeed(float sP);
	void setPosition(float x, float y);
	void setLife(int cLife);
	void setPlayerBody(sf::Sprite* playerBody);
	void setPlayer(Player* pPlayer);

	//others
	void dead();
	void damageTaken(int damage);

	void virtual attack();
};

