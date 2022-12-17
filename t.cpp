#include "functions.h"
#include "settings.h"
#include "game.h"
#include <ctime>
using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);

	/*Game.window.setSize(VideoMode (WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);*/
	//создание объектов игры
	//ракетки
	RectangleShape leftBat, rightBat;
	/*leftBat.setSize(batSize);
	rightBat.setSize(batSize);
	leftBat.setFillColor(leftBatColor);
	rightBat.setFillColor(rightBatColor);
	leftBat.setPosition(batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	rightBat.setPosition(WINDOW_WIDTH - batOffset, (WINDOW_HEIGHT - batHeight) / 2);*/
	initBat(leftBat, leftBatColor, leftBatStartPos);
	initBat(rightBat, rightBatColor, rightBatStartPos);
	float leftBatSpeedy = 0.f;
	float rightBatSpeedy = 0.f;


	//шарик
	CircleShape ball;
	/*(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition((WINDOW_WIDTH - 2 * ballRadius) / 2,
		(WINDOW_HEIGHT - 2 * ballRadius) / 2);*/
	initBall(ball, ballColor, BallStartPos);

	srand(time(nullptr));
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];
	float ball_dx = 2.f;
	float ball_dy = 2.f;

	//счет
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text leftPlayerScoreText;
	Text rightPlayerScoreText;
	initScore(leftPlayerScoreText, font, 200.f, 10.f, 64);
	initScore(rightPlayerScoreText, font, 550.f, 10.f, 64);
	leftPlayerScoreText.setString(std::to_string(leftPlayerScore));
	rightPlayerScoreText.setString(std::to_string(rightPlayerScore));

	/*initScore(leftPlayerScoreText, font, 200.f, 10.f, 64);
	initScore(rightPlayerScoreText, font, 550.f, 10.f, 64);*/
	/*leftPlayerScoreText.setFont(font);
	leftPlayerScoreText.setCharacterSize(64);
	leftPlayerScoreText.setPosition(200.f, 10.f);
	rightPlayerScoreText.setFont(font);
	rightPlayerScoreText.setCharacterSize(64);
	rightPlayerScoreText.setPosition(550.f, 10.f);*/




	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		//2 Обновление объектов
		//шарик
		ball.move(ball_speedx, ball_speedy);
		/*if (ball.getPosition().x<=0||ball.getPosition().x >= (WINDOW_WIDTH - 2 * ballRadius))
		{
			ball_speedx = -ball_speedx;
		}*/






		if (ball.getPosition().y <= 0 || ball.getPosition().y >= (WINDOW_HEIGHT - 2 * ballRadius))
		{
			ball_speedy = -ball_speedy;
		}

		if (ball.getPosition().x <= 0)
		{
			ballReboundX(ball_speedx, rightPlayerScore, rightPlayerScoreText);
		}
		if (ball.getPosition().x >= (WINDOW_WIDTH - 2 * ballRadius))
		{
			ballReboundX(ball_speedx, leftPlayerScore, leftPlayerScoreText);
		
		}


		float midLeftX = ball.getPosition().x;
		float midLeftY = ball.getPosition().y + ballRadius;
		float midRightX = ball.getPosition().x + ballRadius * 2;
		float midRightY = ball.getPosition().y + ballRadius;
		float midupx = ball.getPosition().x + ballRadius;
		float midupy = ball.getPosition().y;
		float middownx = ball.getPosition().x + ballRadius * 2;
		float middowny = ball.getPosition().y + ballRadius * 2;

		if ((leftBat.getPosition().x <= midLeftX && midLeftX <= leftBat.getPosition().x + batWidth) && (leftBat.getPosition().y <= midLeftY && midLeftY <= leftBat.getPosition().y + batHeight))
		{

			ball_speedx = -ball_speedx;
		}
		if ((leftBat.getPosition().x <= middownx && middownx <= leftBat.getPosition().x + batWidth) && (leftBat.getPosition().y <= middowny && middowny <= leftBat.getPosition().y + batHeight))
		{

			ball_speedx = -ball_speedx;
		}
		if ((leftBat.getPosition().x <= midupx && midupx <= leftBat.getPosition().x + batWidth) && (leftBat.getPosition().y <= midupy && midupy <= leftBat.getPosition().y + batHeight))
		{

			ball_speedx = -ball_speedx;
		}
		if ((rightBat.getPosition().x <= middownx && middownx <= rightBat.getPosition().x + batWidth) && (rightBat.getPosition().y <= middowny && middowny <= rightBat.getPosition().y + batHeight))
		{

			ball_speedx = -ball_speedx;
		}
		if ((rightBat.getPosition().x <= midupx && midupx <= rightBat.getPosition().x + batWidth) && (rightBat.getPosition().y <= midupy && midupy <= rightBat.getPosition().y + batHeight))
		{

			ball_speedx = -ball_speedx;
		}


		/*if ((leftBat.getPosition().x <= midLeftX && midLeftX <= leftBat.getPosition().x + batWidth) && (leftBat.getPosition().y <= midLeftY && midLeftY <= leftBat.getPosition().y + batHeight))
		{
			ball_speedx = -ball_speedx;
		}
		if ((leftBat.getPosition().y <= midLeftY && midLeftY <= leftBat.getPosition().y + batWidth) && (leftBat.getPosition().x <= midLeftX && midLeftX <= leftBat.getPosition().x + batHeight))
		{
			ball_speedy = -ball_speedy;
		}*/

		if ((rightBat.getPosition().x <= midRightX && midRightX <= rightBat.getPosition().x + batWidth) && (rightBat.getPosition().y <= midRightY && midRightY <= rightBat.getPosition().y + batHeight))
		{

			ball_speedx = -ball_speedx;

		}
		if ((rightBat.getPosition().y <= midRightY && midRightY <= rightBat.getPosition().y + batWidth) && (rightBat.getPosition().x <= midRightX && midRightX <= rightBat.getPosition().x + batHeight))
		{

			ball_speedx = -ball_speedx;
		}


		/*if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBatSpeedy = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBatSpeedy = batSpeed;
		}
		leftBat.move(0, leftBatSpeedy);
		leftBatSpeedy = 0.f;*/
		ControlBat(leftBat, leftBatSpeedy, Keyboard::W, Keyboard::S);

		if (leftBat.getPosition().y <= 0 || leftBat.getPosition().y >= WINDOW_WIDTH)
		{
			leftBat.setPosition(batOffset - batWidth, 0);
		}
		if (leftBat.getPosition().y + 80 >= WINDOW_HEIGHT || leftBat.getPosition().y + 80 >= WINDOW_WIDTH)
		{
			leftBat.setPosition(batOffset- batWidth, WINDOW_HEIGHT - 80);
		}
		ControlBat(rightBat, rightBatSpeedy, Keyboard::Up, Keyboard::Down);
		/*if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rightBatSpeedy = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rightBatSpeedy = batSpeed;
		}
		rightBat.move(0, rightBatSpeedy);
		rightBatSpeedy = 0.f;*/
		if (rightBat.getPosition().y <= 0 || rightBat.getPosition().y >= WINDOW_WIDTH)
		{
			rightBat.setPosition(WINDOW_WIDTH - batOffset, 0);
		}
		if (rightBat.getPosition().y + 80 >= WINDOW_HEIGHT || rightBat.getPosition().y + 80 >= WINDOW_WIDTH)
		{
			rightBat.setPosition(WINDOW_WIDTH - batOffset, WINDOW_HEIGHT - 80);
		}



		//3 Отрисовка окна
		//3.1 Очистка окна
		window.clear(Color{ 135, 206, 250 });
		//3.2 Отрисовка объектов (В ПАМЯТИ!)
		/*window.draw(leftBat);
		window.draw(rightBat);
		window.draw(ball);
		window.draw(leftPlayerScoreText);
		window.draw(rightPlayerScoreText);*/
		drawAll(window,leftBat, rightBat, ball, leftPlayerScoreText, rightPlayerScoreText);
		//3.3 вывод на экран
		window.display();
	}

	return 0;
}
