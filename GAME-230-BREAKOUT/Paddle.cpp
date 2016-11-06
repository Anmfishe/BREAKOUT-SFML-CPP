#include "Paddle.h"



Paddle::Paddle()
{
}


Paddle::Paddle(int sw, int sh) {
	screen_width = sw;
	screen_height = sh;
	paddle_width = sw / 10;
	paddle_height = paddle_width / 5;
	paddle.setSize(Vector2f(paddle_width, paddle_height));
	paddle.setPosition(Vector2f(sw / 2 - paddle_width / 2, sh - paddle_height));
}


Paddle::~Paddle()
{
}

void Paddle::update(float dt)
{
	Vector2f pos = paddle.getPosition();
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		pos.x -= speed * dt;
		if (pos.x < 0) pos.x = 0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		pos.x += speed * dt;
		if (pos.x > screen_width - paddle_width) {
			pos.x = screen_width - paddle_width;
		}
	}
	paddle.setPosition(pos);
}
