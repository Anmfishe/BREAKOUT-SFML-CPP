#include "Ball.h"



Ball::Ball()
{
}


Ball::Ball(int sw, int sh, int r, Paddle * p) {
	paddle = p;
	screen_height = sh;
	screen_width = sw;
	radius = r;
	ball.setRadius(radius);
	ball.setOrigin(Vector2f(r, r));
	launching = true;
	velocity.x = 150;
	velocity.y = -150;
}


Ball::~Ball()
{
}

void Ball::update(float dt)
{
	Vector2f pos = ball.getPosition();
	if (Keyboard::isKeyPressed(Keyboard::Space)) launching = false;
	if (launching) {
		pos.x = paddle->getMidpoint().x;
		pos.y = paddle->getMidpoint().y - radius;
	}
	else {
		pos.x += velocity.x * dt;
		pos.y += velocity.y * dt;
		if (pos.x + radius >= screen_width) {
			pos.x = screen_width - radius;
			reverseX();
		}
		if (pos.x - radius <= 0) {
			pos.x = radius;
			reverseX();
		}
		if (pos.y - radius <= 0) {
			pos.y = radius;
			reverseY();
		}
		if (pos.y + radius >= screen_height) {
			launching = true;
		}
		Vector2f paddlePos = paddle->getPosition();
		if (!launching &&
			pos.x - radius >= paddlePos.x &&
			pos.x + radius <= paddlePos.x + paddle->getWidth() &&
			pos.y + radius >= paddlePos.y) {
			pos.y = paddlePos.y - radius;
			reverseY();
		}
	}
	ball.setPosition(pos);
}
