#pragma once
#include "GameObject.h"
class Paddle :
	public GameObject
{
public:
	Paddle();
	Paddle(int sw, int sh);
	~Paddle();
	void update(float dt);
	void render(RenderWindow &w) {
		w.draw(paddle);
	}
	Vector2f getMidpoint() {
		return Vector2f(paddle.getPosition().x + paddle_width / 2, paddle.getPosition().y);
	}
	const Vector2f getPosition() {
		return paddle.getPosition();
	}
	int getWidth() {
		return paddle_width;
	}
private:
	int paddle_width;
	int paddle_height;
	int screen_width;
	int screen_height;
	RectangleShape paddle;
	float speed = 150;
};

