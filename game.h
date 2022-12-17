#pragma once
#include "SFML/Graphics.hpp"
struct Bat {
	sf::RectangleShape batShape;
	float batSpeedy;
};
struct Ball {
	sf::CircleShape ball;
	float ball_dx, ball_dy;

};
struct Game {
	sf::RenderWindow window;
	Bat leftBat, rightBat;
	 Ball bal;
	sf::Font font;
	sf::Text leftPlayerScoreText, rightPlayerScoreText;
};
