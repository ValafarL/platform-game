#include "EnemyWarrior.h"

EnemyWarrior::EnemyWarrior(sf::RenderWindow* window, int posX, int posY, int patrolLeft, int patrolRight, Player* player)
	:Characters(window, player)
{
	char nome[50] = "texture/knight/_idle";
	initTexture(nome);
	body.setColor(sf::Color::Red);
	life = 3;
	speed = 5.0;
	damage = 1;
	attackCooldown = 1;
	attackDuration = 0.5;
	attackRange = 75;
	ACooldownClock.restart();

	attackSprite.setTexture(attackTexture);
	attackSprite.setTextureRect(sf::IntRect(0, 0, 80, 10));
	attackSprite.setScale(1, 1);
	attackSprite.setColor(sf::Color::Blue);
	initSprite(1, 1, 0, 0, WIDHT, HEIGHT, posX, posY);
	this->patrolLeft = patrolLeft;
	this->patrolRight = patrolRight;
	charClass = "warrior";
}

EnemyWarrior::~EnemyWarrior()
{
}

void EnemyWarrior::attack(){
	if (attacking) {
		attackingSide();		
		if (ACooldownClock.getElapsedTime().asSeconds() > attackDuration) {
			attacking = false;
		}
	}
	else {
		if (ACooldownClock.getElapsedTime().asSeconds() >= attackCooldown) {
			ACooldownClock.restart();
			attacking = true;
			player->damageTaken(getDamage());
		}
	}
}

void EnemyWarrior::updateAttack(){
	if (ACooldownClock.getElapsedTime().asSeconds() >= attackCooldown) {
		canAttack = true;
	}
}

void EnemyWarrior::attackingSide()
{
	if (bodySide)
	{
		attackSprite.setPosition(body.getGlobalBounds().left + body.getGlobalBounds().width,
			(body.getGlobalBounds().top + (body.getGlobalBounds().height) / 3));
	}
	else if (!bodySide)
	{
		attackSprite.setPosition(body.getGlobalBounds().left - (attackSprite.getGlobalBounds().width),
			(body.getGlobalBounds().top + (body.getGlobalBounds().height) / 3));
	}
}

