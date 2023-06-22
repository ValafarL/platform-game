#include "Player.h"
Player::Player()
{
	bodySide = true;
	jumping = false;
	onGround = false;
	vJump = 80;
	vGravity = 10.0;
	speed = 0.0;
	life = 0;
	oldPosition = sf::Vector2f(0, 0);
	//jumpingTimer.restart();
	attacking = false;

	char nome[50] = "texture/player";
	initTexture(nome);
	initSprite(1, 1, 0, 0, 50, 100, 0, 0);
	body.setColor(sf::Color::Blue);
	setSpeed(7.0);
	life = 5;
	lifePercent = 1;
	maxHp = 5;
	if (!attackTexture.loadFromFile("aa"))
	{
		cout << "FAILED LOADING PNG" << endl;
	}

	frontHpBar.setSize(sf::Vector2f(200* lifePercent, 20));
	frontHpBar.setFillColor(sf::Color::Red);
	frontHpBar.setPosition(10, 10);

	backHpBar.setSize(sf::Vector2f(200, 20));
	backHpBar.setPosition(10, 10);
	backHpBar.setFillColor(sf::Color(25, 25, 25, 200));

	attackSprite.setTexture(attackTexture);
	attackSprite.setTextureRect(sf::IntRect(0, 0, 60, 10));
	attackSprite.setScale(1, 1);
	attackSprite.setColor(sf::Color::Blue);
}

Player::~Player()
{
}

void Player::initTexture(char* path)
{
	if (!texture.loadFromFile(path))
	{
		cout << "FAILED LOADING PNG" << endl;
	}
}

void Player::initSprite(int sX, int sY, int left, int top, int widht, int high, float xPos, float yPos)
{
	body.setTexture(texture);
	body.setTextureRect(sf::IntRect(left, top, widht, high));
	body.setScale(sX, sY);
	body.setPosition(xPos, yPos);
}

void Player::render()
{
	if (attacking == true)
	{
		window->draw(attackSprite);
		attacking = false;
	}
	window->draw(body);
}

void Player::update()
{
	gravity();
	move();
}
void Player::hpBar()
{
	lifePercent = static_cast<float>(life) / static_cast<float>(maxHp);
	if (lifePercent < 0)
	{
		lifePercent = 0;
	}
	sf::RenderWindow* window = getWindow();
	cout << lifePercent << endl;
	frontHpBar.setSize(sf::Vector2f(200 * lifePercent, 20));
	window->draw(backHpBar);
	window->draw(frontHpBar);
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && onGround == true)
	{
		jumping = true;
	}
	if (jumping)
	{
		jumpingUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		body.move(sf::Vector2f(0.f, getSpeed()));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		body.move(sf::Vector2f(getSpeed(), 0.f));
		bodySide = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		body.move(sf::Vector2f(-getSpeed(), 0.f));
		bodySide = false;
	}
}

bool Player::attack2()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		if (bodySide)
		{
			attackSprite.setPosition(body.getGlobalBounds().left + body.getGlobalBounds().width,
				(body.getGlobalBounds().top + (body.getGlobalBounds().height) / 3));
			window->draw(attackSprite);
		}
		else if (!bodySide)
		{
			attackSprite.setPosition(body.getGlobalBounds().left - (attackSprite.getGlobalBounds().width),
				(body.getGlobalBounds().top + (body.getGlobalBounds().height) / 3));
			window->draw(attackSprite);
		}
		return true;
	}
	return false;
}

void Player::setWindow(sf::RenderWindow* pWindow)
{
	window = pWindow;
}

sf::RenderWindow* Player::getWindow()
{
	return window;
}
sf::Sprite* Player::getBody()
{
	return &body;
}

void Player::gravity()
{
	body.move(0, vGravity);
}

void Player::jumpingUp()
{
	if (vJump >= 0)
	{
		body.move(sf::Vector2f(0.f, -vJump));
		onGround = false;
		vJump -= vGravity;
		//jumpingTimer.restart();
	}
	else
	{
		jumping = false;
		vJump = 80;
	}
}

void Player::damageTaken(int damage)
{
	this->setLife(this->getLife() - damage);
}

void Player::setSpeed(float sP)
{
	speed = sP;
}

void Player::setLife(int cLife)
{
	life = cLife;
}

float Player::getSpeed()
{
	return speed;
}

int Player::getLife()
{
	return life;
}

int Player::getDamage()
{
	return damage;
}

void Player::isOnGround()
{
	cout << oldPosition.x<< " " << oldPosition.y << "   " << body.getPosition().x << " " << body.getPosition().y << endl;
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

bool Player::getJumping()
{
	return jumping;
}
