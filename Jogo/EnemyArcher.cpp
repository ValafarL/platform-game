#include "EnemyArcher.h"

EnemyArcher::EnemyArcher(sf::RenderWindow* window, int posX, int posY, int patrolLeft, int patrolRight, Player* player)
	:Characters(window, player)
{
	char nome[50] = "";
	initTexture(nome);
	body.setColor(sf::Color::Cyan);
	attackSprite.setTexture(attackTexture);
	attackSprite.setTextureRect(sf::IntRect(0, 0, 60, 10));
	attackSprite.setScale(1, 1);
	attackSprite.setColor(sf::Color::Cyan);
	initSprite(1, 1, 0, 0, WIDHT, HEIGHT, posX, posY);

	life = 1;
	speed = 5.0;
	damage = 1;
	attackRange = 1050;
	this->patrolLeft = patrolLeft;
	this->patrolRight = patrolRight;
	charClass = "archer";
	ACooldownClock.restart();

}

EnemyArcher::~EnemyArcher()
{
}

void EnemyArcher::attack()
{
	if(ACooldownClock.getElapsedTime().asSeconds() >= 1)
	{
		ACooldownClock.restart();
		if (bodySide)
		{
			arrowShot = true;
			arrowV = +10;
			attackSprite.setPosition(body.getGlobalBounds().left + body.getGlobalBounds().width,
				(body.getGlobalBounds().top + (body.getGlobalBounds().height) / 3));
		}
		else if (!bodySide)
		{
			arrowShot = true;
			arrowV = -10;
			attackSprite.setPosition(body.getGlobalBounds().left - (attackSprite.getGlobalBounds().width),
				(body.getGlobalBounds().top + (body.getGlobalBounds().height) / 3));
		}
		attacking = true;
	}
}

void EnemyArcher::travelArrow()
{
	if (arrowShot)
	{
		attackSprite.move(sf::Vector2f(arrowV, 0));
	}
}

void EnemyArcher::arrowCollide()
{
	if (attackSprite.getGlobalBounds().left <
		playerBody->getGlobalBounds().left + playerBody->getGlobalBounds().width &&
		attackSprite.getGlobalBounds().left + attackSprite.getGlobalBounds().width >
		playerBody->getGlobalBounds().left &&
		attackSprite.getGlobalBounds().top <
		playerBody->getGlobalBounds().top + playerBody->getGlobalBounds().height &&
		attackSprite.getGlobalBounds().top + attackSprite.getGlobalBounds().height >
		playerBody->getGlobalBounds().top)
	{
		arrowShot = false;
		player->damageTaken(getDamage());
	}
	else
	{
		if (attackSprite.getGlobalBounds().left + attackSprite.getGlobalBounds().width > window->getSize().x)
		{
			arrowShot = false;
		}
		if (attackSprite.getGlobalBounds().left < 0)
		{
			arrowShot = false;
		}
	}
}

void EnemyArcher::update()
{
	if (arrowShot)
	{
		arrowCollide();
	}
	gravity();
	travelArrow();
	patrol();
}

void EnemyArcher::render()
{
	if (arrowShot == true)
	{
		window->draw(attackSprite);
	}
}
