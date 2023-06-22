#include "EnemyArcher.h"

EnemyArcher::EnemyArcher()
{
	char nome[50] = "";
	initTexture(nome);
	initSprite(1, 1, 0, 0, 50, 100, 200, 300);
	body.setColor(sf::Color::Cyan);
	setSpeed(5.0);
	setLife(1);
	arrowShot = false;
	arrowV = 0;
	damage = 1;
	attackRange = 250;
	timeShot = 0;
	attackSprite.setTexture(attackTexture);
	attackSprite.setTextureRect(sf::IntRect(0, 0, 60, 10));
	attackSprite.setScale(1, 1);
	attackSprite.setColor(sf::Color::Cyan);
}

EnemyArcher::~EnemyArcher()
{
}

void EnemyArcher::attack()
{
	if(timeShot == 0)
	{
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

	if (timeShot >= 60)
	{
		timeShot = 0;
	}
	else
	{
		timeShot = timeShot + 1;
	}
	gravity();
	move();
	travelArrow();
}

void EnemyArcher::render()
{
	if (arrowShot == true)
	{
		window->draw(attackSprite);
	}
}
