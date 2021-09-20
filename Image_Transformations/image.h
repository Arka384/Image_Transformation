#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cmath>

class image
{
private:
	sf::Image lodedImage;
	sf::Texture imageTex;
	sf::Sprite imageSprite;
	std::string filePath = "Images/";
	std::string outputPath = "Images/Converted_";
	int maxIntensity = 256;

public:
	void LoadImage(std::string fileName);
	void SaveImage(std::string fileName);
	void createSprite(void);
	void drawSprite(sf::RenderWindow &window);
	void negetiveTransformation(std::string fileName);
	void logTransformation(std::string fileName, int c);
	void powerLawTransformation(std::string fileName, float c, float gamma);
};

