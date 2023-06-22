#include "Characters.h"

Characters::Characters()
{
	damage = 1;
	bodySide = true;
	jumping = false;
	onGround = false;
	vJump = 80;
	vGravity = 10.0;
	speed = 0.0;
	life = 0;
	jumpingTimer.restart();
	attacking = false;
	playerBody = NULL;
}

Characters::~Characters()
{
}

void Characters::render()
{
	if (attacking == true)
	{
		window->draw(attackSprite);
		attacking = false;
	}
}

void Characters::update()
{
	gravity();
	move();
}

void Characters::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && onGround == true)
	{
		jumping = true;
	}
	if (jumping)
	{
		jumpingUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		body.move(sf::Vector2f(0.f, getSpeed()));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		body.move(sf::Vector2f(getSpeed(), 0.f));
		bodySide = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		body.move(sf::Vector2f(-getSpeed(), 0.f));
		bodySide = false;
	}
}

void Characters::moveTo(sf::Sprite* pBody, Player * player)
{
	if (body.getGlobalBounds().left - (body.getGlobalBounds().width * 6) <
		pBody->getGlobalBounds().left + pBody->getGlobalBounds().width && pBody->getPosition().x <= 
		body.getGlobalBounds().left && body.getGlobalBounds().top - body.getGlobalBounds().height < pBody->getGlobalBounds().top
		&& body.getGlobalBounds().top + body.getGlobalBounds().height + 20 >= pBody->getGlobalBounds().top + pBody->getGlobalBounds().height)
	{
		if (body.getPosition().x > pBody->getPosition().x + pBody->getGlobalBounds().width + attackRange)
		{
			body.move(-speed, 0);
			bodySide = false;
		}
		else
		{
			bodySide = false;
			//player->damageTaken(getDamage());
			this->attack();
		}
		cout << "ARROZ DOCE" << endl;
	}
	if ((body.getGlobalBounds().left + body.getGlobalBounds().width )+ (body.getGlobalBounds().width * 6) >
		pBody->getGlobalBounds().left  && pBody->getPosition().x >= body.getGlobalBounds().left
		&& body.getGlobalBounds().top - body.getGlobalBounds().height < pBody->getGlobalBounds().top
		&& body.getGlobalBounds().top + body.getGlobalBounds().height + 20 >= pBody->getGlobalBounds().top + pBody->getGlobalBounds().height)
	{
		if (body.getPosition().x + body.getGlobalBounds().width <  (pBody->getPosition().x - attackRange))
		{
			body.move(speed, 0);
			bodySide = true;
		}
		else
		{
			//player->damageTaken(getDamage());
			bodySide = true;
			this->attack();
		}
	}
}

void Characters::setSpeed(float sP)
{
	speed = sP;
}

float Characters::getSpeed()
{
	return speed;
}

void Characters::setPosition(float x, float y)
{
	body.setPosition(sf::Vector2f(x, y));
}

void Characters::gravity()
{
	body.move(0, vGravity);
}

void Characters::jumpingUp()
{
	if (vJump >= 0)
	{
			body.move(sf::Vector2f(0.f, -vJump));
			onGround = false;
			vJump -= vGravity;
			jumpingTimer.restart();
	}
	else
	{
			jumping = false;
			vJump = 80;
	}
}

void Characters::setLife(int cLife)
{
	life = cLife;
}

void Characters::setPlayerBody(sf::Sprite* playerBody)
{
	this->playerBody = playerBody;
}

void Characters::setPlayer(Player* pPlayer)
{
	player = pPlayer;
}

int Characters::getLife()
{
	return life;
}

int Characters::getDamage()
{
	return damage;
}

void Characters::dead()
{
	delete(this);
}

void Characters::damageTaken(int damage)
{
	this->setLife(this->getLife() - damage);
}

void Characters::attack()
{
}

