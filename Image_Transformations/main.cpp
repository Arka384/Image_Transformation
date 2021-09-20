#include "image.h"
#include "updates.h"

void input(int &choice, std::string &name);

int main()
{
	std::string fileName;
	int choice = 0;
	input(choice, fileName);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "ImageTransform", sf::Style::Close);

	image img;
	img.LoadImage(fileName);
	loadSprites();
	if (choice == 1)
		img.negetiveTransformation(fileName);

	bool mousePressed = false, executed = false;
	sf::Vector2i mousePos;
	
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::MouseButtonPressed:
				mousePressed = true;
				executed = true;
				break;
			case sf::Event::MouseButtonReleased:
				mousePressed = false;
				break;
			default:
				break;
			}
		}

		mousePos = sf::Mouse::getPosition(window);
		if(choice != 1)
			updateButtons(mousePos, mousePressed);
		if (choice != 1 && executed) {
			if (choice == 2)
				img.logTransformation(fileName, c);
			else
				img.powerLawTransformation(fileName, c, gamma);
			executed = false;
		}
		updateTexts();

		window.clear();
		img.drawSprite(window);
		if(choice != 1)
			drawSprites(window);
		window.display();
	}
	return 0;
}

void input(int &choice, std::string &name) {
	std::cout << "\nEnter file name: ";
	std::cin >> name;
	std::cout << "\n1 -> Invert Colours";
	std::cout << "\n2 -> Log Transformation";
	std::cout << "\n3 -> PowerLaw Transformation";
	std::cout << "\nEnter choice: ";
	std::cin >> choice;
	std::cout << "\n\nLast converted imgae will be saved in the images folder\n";
}

