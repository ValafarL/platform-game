#include "Characters.h"

Characters::Characters(sf::RenderWindow* window, Player* player)
	:Entities(window)
{
	this->player = player;
	jumpingTimer.restart();
	playerBody = player->getBody();
}

Characters::~Characters()
{
}

void Characters::render()
{
	drawBody();
	if (this->attacking == true)
	{
		window->draw(this->attackSprite);
	}
}

void Characters::update()
{
	this->gravity();
	this->patrol();
}


void Characters::verifyPlayerInATTRange()
{
	if (body.getGlobalBounds().top - body.getGlobalBounds().height < playerBody->getGlobalBounds().top && 
		body.getGlobalBounds().top + body.getGlobalBounds().height + 20 >= playerBody->getGlobalBounds().top + playerBody->getGlobalBounds().height &&
		((body.getGlobalBounds().left < playerBody->getGlobalBounds().left &&
			playerBody->getGlobalBounds().left <= body.getGlobalBounds().left + body.getGlobalBounds().width + attackRange)
			||
			(body.getGlobalBounds().left > playerBody->getGlobalBounds().left &&
				playerBody->getGlobalBounds().left >= body.getGlobalBounds().left - attackRange)))
	{
		if (body.getPosition().x > playerBody->getPosition().x && bodySide == false) {
			this->attack();
		}
		else if (body.getPosition().x < playerBody->getPosition().x && bodySide == true) {
			this->attack();
		}
	}
	else {
		attacking = false;
	}
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

void Characters::patrol()
{
	if (patrolLeft != patrolRight && followPlayer == false) {
		if (body.getGlobalBounds().left < patrolLeft) {
			patrolSide = true;
		}
		else if ((body.getGlobalBounds().left + body.getGlobalBounds().width) > patrolRight) {
			patrolSide = false;
		}
		if (patrolSide == true) {
			body.move(sf::Vector2f(speed, 0.f));
			bodySide = true;
		}
		else {
			body.move(sf::Vector2f(-speed, 0.f));
			bodySide = false;
		}
	}
}

void Characters::setLife(int cLife)
{
	this->life = cLife;
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

void Characters::updateAttack()
{
}

