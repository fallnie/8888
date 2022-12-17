#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

void initBat(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batPosition)
{
	bat.setSize(batSize);
	bat.setFillColor(batColor);
	bat.setPosition(batPosition);
}
void initBall(sf::CircleShape& ball, const sf::Color ballColor, const sf::Vector2f ballPosition)
{
	ball.setRadius(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition(ballPosition);
}
void initScore(sf::Text& player, sf::Font& font, float pos1, float pos2, int size) {
	player.setFont(font);
	player.setCharacterSize(size);
	player.setPosition(pos1, pos2);
}
void ballReboundX(float& ballSpeed, int& playerScore, sf::Text& scoreText) {
	ballSpeed = -ballSpeed;
	playerScore++;
	scoreText.setString(std::to_string(playerScore));
}
void ControlBat(sf::RectangleShape& bat,float& BatSpeedy, sf::Keyboard::Key up_key, sf::Keyboard::Key down_key) {
	if (sf::Keyboard::isKeyPressed(up_key)) {
		BatSpeedy = -batSpeed;
	}
	if (sf::Keyboard::isKeyPressed(down_key)) {
		BatSpeedy = batSpeed;
	}
	bat.move(0, BatSpeedy);
	BatSpeedy = 0;
}
void drawAll(sf::RenderWindow& window , sf::RectangleShape bat, sf::RectangleShape bat1, sf::CircleShape& ball, sf::Text scoreText, sf::Text scoreText1) {
	window.draw(bat);
	window.draw(bat1);
	window.draw(ball);
	window.draw(scoreText);
	window.draw(scoreText1);
}
