#include "menu.h"

Menu::Menu()
	: play(window, 250, 50, 540, 359)
{
	play.setPath("texture/menu/play.png");
}

Menu::~Menu()
{
}

void Menu::createMenu()
{	
	play.setWindow(this->getWindow());
	play.setPath("texture/menu/play.png");
	play.createTile(1, 1, 0, 0, 250, 50, 540, 359);

}

void Menu::drawMenu()
{
	play.drawBody();
}

void Menu::update()
{
}
