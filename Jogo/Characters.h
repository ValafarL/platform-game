#pragma once
#include "stdfx.h"
#include "Entities.h"
#include "List.h"
#include <string>
#include "Player.h"

class Characters:public Entities
{
protected:
	sf::Clock ADurationClock;

	bool patrolSide = true;
	bool alive = true;
	bool bodySide = true; // true right, false left
	bool attacking = false;
	bool followPlayer = false;
	bool jumping = false;
	bool onGround = false;
	
	int attackRange;
	int patrolLeft = 0;
	int patrolRight = 0;
	int life;
	int damage;

	float attackCooldown;
	float attackDuration;
	float speed = 5.0f;
	float vGravity = 10.0f;
	float vJump = 80;
	

	Player *player;
	sf::Clock jumpingTimer;
	sf::Texture attackTexture;
	sf::Sprite attackSprite;
	sf::Sprite* playerBody;


public:
	std::string charClass;
	Characters(sf::RenderWindow* window, Player* player);
	~Characters();
	virtual void render();
	virtual void update();

	// collisions
	
	//movement
	virtual void verifyPlayerInATTRange();
	void gravity();
	void jumpingUp();
	void patrol();

	//gets
	int getLife();
	int getDamage();

	//sets
	void setLife(int cLife);
	void setPlayerBody(sf::Sprite* playerBody);
	void setPlayer(Player* pPlayer);

	//others
	void dead();
	void damageTaken(int damage);

	void virtual attack();
	void virtual updateAttack();
};

