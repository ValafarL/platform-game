#pragma once
#include "stdfx.h"
#include "Entities.h"

class Player: public Entities
{
private:
	int damage = 1;
	bool bodySide = true; // true right, false left
	float speed = 7.0;
	int life = 5;
	bool attacking = false;
	bool attackHit = false;
	int attackRange;
	bool alive = true;
	bool jumping = false;
	bool onGround = false;
	float vGravity = 10.0f;
	float vJump = 80;
	sf::Clock ACooldownClock;
	sf::Clock shockTime;

	float attackCooldown;
	float attackDuration;
	bool enterPortal = false;

	const int maxHp = 5;
	float lifePercent = 1;
	sf::RectangleShape frontHpBar;
	sf::RectangleShape backHpBar;

	sf::Texture attackTexture;
	sf::Sprite attackArea;
	sf::Texture texture;
	sf::RenderWindow* window;
	sf::Vector2f oldPosition;
	char path[50];
public:
	bool isShocked = false;
	Player(sf::RenderWindow* window);
	~Player();
	void render();
	void update();
	void hpBar();
	void handleKeysPressed();
	void move(float x, float y);
	void attack2();
	void attackSide();
	sf::RenderWindow* getWindow();
	sf::Sprite* getAttackArea();
	void gravity();
	void damageTaken(int damage);
	void dealDamageTo(sf::Sprite* body2);
	void isJumping();
	
	void setWindow(sf::RenderWindow* pWindow);
	void setAttackingHit(bool hit);

	int getLife();
	int getDamage();
	bool getAttacking();
	bool getAttackingHit();
	bool getEnterPortal();

	void isOnGround();
	void jumpCollision(sf::Sprite* body2);
};
