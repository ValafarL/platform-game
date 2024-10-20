#include "Player.h"
Player::Player(sf::RenderWindow* window)
	:Entities(window)
{
	oldPosition = sf::Vector2f(0, 0);

	char nome[50] = "texture/player";
	initTexture(nome);
	initSprite(1, 1, 0, 0, 50, 100, 0, 0);
	body.setColor(sf::Color::Blue);
	if (!attackTexture.loadFromFile("aa"))
	{
		cout << "FAILED LOADING PNG" << endl;
	}
	attackCooldown = 0.2;
	attackDuration = 0.2;
	ACooldownClock.restart();

	frontHpBar.setSize(sf::Vector2f(200* lifePercent, 20));
	frontHpBar.setFillColor(sf::Color::Red);
	frontHpBar.setPosition(10, 10);

	backHpBar.setSize(sf::Vector2f(200, 20));
	backHpBar.setPosition(10, 10);
	backHpBar.setFillColor(sf::Color(25, 25, 25, 200));

	attackArea.setTexture(attackTexture);
	attackArea.setTextureRect(sf::IntRect(0, 0, 60, 10));
	attackArea.setScale(1, 1);
	attackArea.setColor(sf::Color::Blue);
	oldX = body.getPosition().x;
	oldY = body.getPosition().y;
}

Player::~Player()
{
}

void Player::render()
{
	window->draw(backHpBar);
	window->draw(frontHpBar);
	if (ACooldownClock.getElapsedTime().asSeconds() <= attackCooldown && attacking == true)
	{
		window->draw(attackArea);
	}
	window->draw(body);
}

void Player::update()
{
	enterPortal = false;
	hpBar();
	if (ACooldownClock.getElapsedTime().asSeconds() <= attackCooldown && attacking == true)
	{
		attackSide();
	}
	else {
		attacking = false;
	}
	if (!isShocked) {
		gravity();
		handleKeysPressed();
	}
	isShocked = false;
}
void Player::hpBar()
{
	lifePercent = static_cast<float>(life) / static_cast<float>(maxHp);
	if (lifePercent < 0)
	{
		lifePercent = 0;
	}
	sf::RenderWindow* window = getWindow();
	frontHpBar.setSize(sf::Vector2f(200 * lifePercent, 20));
}

void Player::handleKeysPressed()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && onGround == true)
	{
		jumping = true;
	}
	if (jumping)
	{
		isJumping();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		enterPortal = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move(speed, 0.f);
		bodySide = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move(-speed, 0.f);
		bodySide = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		attack2();
	}
}

void Player::move(float x, float y)
{
	body.move(sf::Vector2f(x, y));
}

void Player::attack2()
{
	if (ACooldownClock.getElapsedTime().asSeconds() >= attackCooldown && attacking == false) {
		attackSide();
		ACooldownClock.restart();
		attacking = true;
		attackHit = false;
	}
}
void Player::attackSide() {
	if (bodySide)
	{
		attackArea.setPosition(body.getGlobalBounds().left + body.getGlobalBounds().width,
			(body.getGlobalBounds().top + (body.getGlobalBounds().height) / 3));
	}
	else
	{
		attackArea.setPosition(body.getGlobalBounds().left - (attackArea.getGlobalBounds().width),
			(body.getGlobalBounds().top + (body.getGlobalBounds().height) / 3));
	}
}

void Player::setWindow(sf::RenderWindow* pWindow)
{
	window = pWindow;
}

sf::RenderWindow* Player::getWindow()
{
	return window;
}

sf::Sprite* Player::getAttackArea()
{
	return &attackArea;
}

void Player::gravity()
{
	body.move(0, vGravity);
}

void Player::isJumping()
{
	if (vJump >= 0)
	{
		body.move(sf::Vector2f(0.f, -vJump));
		onGround = false;
		vJump -= vGravity;
	}
	else
	{
		jumping = false;
		vJump = 80;
	}
}

void Player::damageTaken(int damage)
{
	this->life = this->life - damage;
}

void Player::dealDamageTo(sf::Sprite* body2)
{
}

void Player::setAttackingHit(bool hit)
{
	attackHit = hit;
}

int Player::getLife()
{
	return life;
}

int Player::getDamage()
{
	return damage;
}

bool Player::getAttacking()
{
	return attacking;
}

void Player::isOnGround()
{
	if (oldPosition.y == body.getPosition().y)
	{
		onGround = true;
	}
	else
	{
		onGround = false;
	}
	oldPosition = body.getPosition();
}

void Player::jumpCollision(sf::Sprite *body2)
{
	if (jumping)
	{
		if (body.getGlobalBounds().left <
			body2->getGlobalBounds().left + body2->getGlobalBounds().width &&
			body.getGlobalBounds().left + body.getGlobalBounds().width >
			body2->getGlobalBounds().left &&
			body.getGlobalBounds().top <
			body2->getGlobalBounds().top + body2->getGlobalBounds().height &&
			body.getGlobalBounds().top + body.getGlobalBounds().height >
			body2->getGlobalBounds().top)
		
		{
			body.move(0, (body2->getGlobalBounds().top +
				body2->getGlobalBounds().height +
				body.getGlobalBounds().height) - (body.getGlobalBounds().top + body.getGlobalBounds().height));
		}
	}
}
bool Player::getAttackingHit()
{
	return attackHit;
}

bool Player::getEnterPortal()
{
	return enterPortal;
}
