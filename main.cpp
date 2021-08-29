#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Mapandee");

	
	sf::CircleShape collision(40.f);
	collision.setPosition({ 800,470});
	collision.setFillColor(sf::Color::Red);

	
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("img/panda.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	
	
	sf::Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);

	int spriteSizeX = playerTexture.getSize().x / 3;
	int spriteSizeY = playerTexture.getSize().y / 4;

	shapeSprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

	sf::Vector2f spawnPoint = { 4.f, 40.f };
	shapeSprite.setPosition(spawnPoint);

	int animationFrame = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shapeSprite);
		window.draw(collision);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			shapeSprite.move(.2f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 2, spriteSizeX, 32));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			shapeSprite.move(-.2f, 0.f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 1, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			shapeSprite.move(0.f, -.2f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			shapeSprite.move(0.f, .2f);
			shapeSprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, 0,spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		animationFrame++;

		if (animationFrame >= 2) {
			animationFrame = 0;
		}
		if (collision.getGlobalBounds().intersects(shapeSprite.getGlobalBounds())) {
			shapeSprite.setPosition(spawnPoint);
		}
		

		
	}
	return 0;
}