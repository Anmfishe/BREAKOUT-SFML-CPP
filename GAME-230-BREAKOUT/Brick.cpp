#include "Brick.h"



Brick::Brick()
{
}


Brick::Brick(float x, float y, int sw, int sh, int l, Ball * b) {
	lives = l;
	ball = b;
	brick_width = sw / 10;
	brick_height = brick_width / 2;
	brick.setPosition(Vector2f(x, y));
	brick.setSize(Vector2f(brick_width, brick_height));
}


Brick::~Brick()
{
}

void Brick::update(float dt)
{
	Vector2f pos = brick.getPosition();
	Vector2f ballPos = ball->getPosition();
	int radius = ball->getRadius();
	if (ballPos.x + radius >= pos.x &&
		ballPos.x - radius <= pos.x &&
		ballPos.y >= pos.y &&
		ballPos.y <= pos.y + brick_height) {
		ball->setPosition(pos.x - radius, ballPos.y);
		lives--;
		ball->reverseX();
		
	}
	if (ballPos.x - radius <= pos.x + brick_width &&
		ballPos.x + radius >= pos.x + brick_width &&
		ballPos.y >= pos.y &&
		ballPos.y <= pos.y + brick_height) {
		ball->setPosition(pos.x + brick_width + radius, ballPos.y);
		lives--;
		ball->reverseX();
		
	}
	if (ballPos.y - radius <= pos.y + brick_height &&
		ballPos.y + radius >= pos.y + brick_height &&
		ballPos.x - radius >= pos.x &&
		ballPos.x + radius <= pos.x + brick_width) {
		ball->setPosition(ballPos.x, pos.y + brick_height + radius);
		ball->reverseY();
		lives--;
	}
	if (ballPos.y + radius >= pos.y &&
		ballPos.y - radius <= pos.y &&
		ballPos.x - radius >= pos.x &&
		ballPos.x + radius <= pos.x + brick_width) {
		ball->setPosition(ballPos.x, pos.y - radius);
		ball->reverseY();
		lives--;
		
	}
}
