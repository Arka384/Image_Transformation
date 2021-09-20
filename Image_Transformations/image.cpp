#include "image.h"

void image::LoadImage(std::string fileName)
{
	filePath.append(fileName);
	if (!lodedImage.loadFromFile(filePath))
		exit(1);
	filePath = "Images/";
}

void image::SaveImage(std::string fileName)
{
	outputPath.append(fileName);
	lodedImage.saveToFile(outputPath);
	outputPath = "Images/Converted_";
}

void image::createSprite(void)
{
	imageTex.loadFromImage(lodedImage);
	imageSprite.setTexture(imageTex);
}

void image::drawSprite(sf::RenderWindow & window)
{
	createSprite();
	window.draw(imageSprite);
}

void image::negetiveTransformation(std::string fileName)
{
	LoadImage(fileName);
	sf::Vector2u imageSize = lodedImage.getSize();
	sf::Color pixel;
	int r=0, g=0, b=0, grayscaleIntensity = 0;
	for (int i = 0; i < imageSize.y; i++) {
		for (int j = 0; j < imageSize.x; j++) {
			pixel = lodedImage.getPixel(j, i);
			r = maxIntensity - pixel.r - 1;
			g = maxIntensity - pixel.g - 1;
			b = maxIntensity - pixel.b - 1;
			grayscaleIntensity = ((0.2126*r) + (0.7125*g) + (0.0722*b));
			lodedImage.setPixel(j, i, sf::Color(r, g, b, grayscaleIntensity));
		}
	}
	SaveImage(fileName);
}

void image::logTransformation(std::string fileName, int c)
{
	LoadImage(fileName);
	sf::Vector2u imageSize = lodedImage.getSize();
	sf::Color pixel;
	int r = 0, g = 0, b = 0, grayscaleIntensity = 0, max = 0;

	for (int i = 0; i < imageSize.y; i++) {
		for (int j = 0; j < imageSize.x; j++) {
			pixel = lodedImage.getPixel(j, i);
			r = c * (log(1 + pixel.r));
			g = c * (log(1 + pixel.g));
			b = c * (log(1 + pixel.b));
			grayscaleIntensity = ((0.2126*r) + (0.7125*g) + (0.0722*b));
			lodedImage.setPixel(j, i, sf::Color(r, g, b, grayscaleIntensity));
		}
	}
	SaveImage(fileName);
}

void image::powerLawTransformation(std::string fileName, float c, float gamma)
{
	LoadImage(fileName);
	sf::Vector2u imageSize = lodedImage.getSize();
	sf::Color pixel;
	int r = 0, g = 0, b = 0, grayscaleIntensity = 0;

	for (int i = 0; i < imageSize.y; i++) {
		for (int j = 0; j < imageSize.x; j++) {
			pixel = lodedImage.getPixel(j, i);
			r = c * (pow(pixel.r, gamma));
			g = c * (pow(pixel.g, gamma));
			b = c * (pow(pixel.b, gamma));
			grayscaleIntensity = ((0.2126*r) + (0.7125*g) + (0.0722*b));
			lodedImage.setPixel(j, i, sf::Color(r, g, b, grayscaleIntensity));
		}
	}
	SaveImage(fileName);
}
