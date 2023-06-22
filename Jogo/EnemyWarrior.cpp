#include "EnemyWarrior.h"

EnemyWarrior::EnemyWarrior()
{
	char nome[50] = "texture/knight/_idle";
	initTexture(nome);
	initSprite(1, 1, 0, 0, 50, 100, 200, 100);
	body.setColor(sf::Color::Red);
	setSpeed(5.0);
	setLife(1);
	damage = 0;
	attackRange = 75;
	attackSprite.setTexture(attackTexture);
	attackSprite.setTextureRect(sf::IntRect(0, 0, 80, 10));
	attackSprite.setScale(1, 1);
	attackSprite.setColor(sf::Color::Blue);
}

EnemyWarrior::~EnemyWarrior()
{
}

void EnemyWarrior::attack()
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
		attacking = true;
}
