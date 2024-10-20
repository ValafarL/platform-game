#include "EnemyMage.h"

EnemyMage::EnemyMage(sf::RenderWindow* window, int posX, int posY, int patrolLeft, int patrolRight, Player* player)
	:Characters(window, player)
{
	char nome[50] = "texture/knight/_idle";
	initTexture(nome);
	body.setColor(sf::Color::Yellow);
	setLife(1);
	attackCooldown = 1;
	attackDuration = 2;
	speed = 5.0f;
	initSprite(1, 1, 0, 0, WIDHT, HEIGHT, posX, posY);
	attackSprite.setTexture(attackTexture);
	attackSprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
	attackSprite.setScale(1, 1);
	attackSprite.setColor(sf::Color::Blue);
	ACooldownClock.restart();
	AMoveClock.restart();
	attacking = false;
	attackRange = 1300;
	charClass = "mage";
}

EnemyMage::~EnemyMage()
{
}

void EnemyMage::update()
{
	this->gravity();
	this->patrol();
	attack();
	updateAttack();
}

void EnemyMage::attack()
{
	if (attacking) {
		if (ACooldownClock.getElapsedTime().asSeconds() > attackDuration) {
			attacking = false;
			attackDirectionCalculated = false;
		}
	}
	else {
		if (ACooldownClock.getElapsedTime().asSeconds() >= attackCooldown) {
			ACooldownClock.restart();
			AMoveClock.restart();
			attacking = true;
			attackSprite.setPosition(body.getPosition());
			calculateAttackDirection();
			PPosition = player->getBody()->getPosition();
		}
	}
}

void EnemyMage::calculateAttackDirection()
{
	sf::Vector2f direction;
	if (!attackDirectionCalculated) {
		direction.x = player->getBody()->getGlobalBounds().left + (player->getBody()->getGlobalBounds().width / 2) - attackSprite.getPosition().x;
		direction.y = player->getBody()->getGlobalBounds().top + (player->getBody()->getGlobalBounds().height / 2) - attackSprite.getPosition().y;
		float length = sqrt(direction.x * direction.x + direction.y * direction.y);
		if (length != 0) {
			direction.x /= length;
			direction.y /= length;
		}
		attackDirection = direction;
		attackDirectionCalculated = true;
	}
}

void EnemyMage::updateAttack()
{
	if (attacking && AMoveClock.getElapsedTime().asMicroseconds() >= 1) {
		float attackSpeed = 10.0f;
		attackSprite.move(attackDirection.x * attackSpeed, attackDirection.y * attackSpeed);
		if (attackSprite.getPosition().x < 0 || attackSprite.getPosition().x > 1280 || 
			attackSprite.getPosition().y < 0 || attackSprite.getPosition().y > 768) {
			attacking = false;
			attackDirectionCalculated = false;
		}
		if (collision.collideObject(&attackSprite, player->getBody())) {
			player->damageTaken(1);
			attacking = false;
			attackDirectionCalculated = false;
		}
		AMoveClock.restart();
	}
}
