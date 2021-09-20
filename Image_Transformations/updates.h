#pragma once
#include "image.h"
#include <sstream>

sf::Sprite buttons[4];
sf::Texture button_tex_up, button_tex_down;
float c = 250.f, gamma = 0.f;
sf::Text C, Gamma, lableC, lableGamma;
sf::Font font;

void loadSprites(void)
{
	button_tex_up.loadFromFile("Sprites/up.png");
	button_tex_down.loadFromFile("Sprites/down.png");

	for (int i = 0; i < 3; i+=2)
		buttons[i].setTexture(button_tex_up);
	for (int i = 1; i < 4; i+=2)
		buttons[i].setTexture(button_tex_down);
	for (int i = 0; i < 4; i++)
		buttons[i].setPosition(1280 - 60, (i * 100) + 10);
		

	font.loadFromFile("font.ttf");
	C.setFont(font);
	C.setCharacterSize(35);
	C.setFillColor(sf::Color::White);

	Gamma.setFont(font);
	Gamma.setCharacterSize(35);
	Gamma.setFillColor(sf::Color::White);

	lableC.setFont(font);
	lableC.setCharacterSize(25);
	lableC.setFillColor(sf::Color::White);
	lableC.setRotation(-90.f);
	lableC.setString("C - Level");
	lableC.setPosition(1280 - 120, 130);

	lableGamma.setFont(font);
	lableGamma.setCharacterSize(25);
	lableGamma.setFillColor(sf::Color::White);
	lableGamma.setRotation(-90.f);
	lableGamma.setString("Gamma - Level");
	lableGamma.setPosition(1280 - 120, 370);
}

void updateTexts(void)
{
	std::stringstream cs, gs;
	cs << c;
	C.setString(cs.str());
	C.setPosition(1280 - C.getGlobalBounds().width / 2 - 40, 55);
	gs << gamma;
	Gamma.setString(gs.str());
	Gamma.setPosition(1280 - Gamma.getGlobalBounds().width / 2 - 40, 255);
}

void updateButtons(sf::Vector2i mousePos, bool &pressed)
{
	for (int i = 0; i < 4; i++) {
		buttons[i].setPosition(1280 - 60, (i * 100) + 10);
		buttons[i].setScale(1, 1);
		int hot = mousePos.x > buttons[i].getPosition().x && mousePos.x < buttons[i].getPosition().x + buttons[i].getGlobalBounds().width &&
			mousePos.y > buttons[i].getPosition().y && mousePos.y < buttons[i].getPosition().y + buttons[i].getGlobalBounds().height;
		if (hot) {
			buttons[i].setScale(0.9, 0.9);
			buttons[i].setPosition(buttons[i].getPosition().x + 2, buttons[i].getPosition().y + 2);
		}
		if (hot && pressed) {
			pressed = false;
			switch (i)
			{
			case 0:
				c += 10;
				if (c > 250)
					c = 0;
				break;
			case 1:
				c -= 10;
				if (c < 0)
					c = 250;
				break;
			case 2:
				gamma += 0.5;
				break;
			case 3:
				gamma -= 0.5;
				break;
			default:
				break;
			}
		}
	}
}

void drawSprites(sf::RenderWindow &window)
{
	for (int i = 0; i < 4; i++)
		window.draw(buttons[i]);
	window.draw(C);
	window.draw(Gamma);
	window.draw(lableC);
	window.draw(lableGamma);
}