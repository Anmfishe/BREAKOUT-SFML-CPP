#pragma once
#include "GameObject.h"
#include "Paddle.h"
class Ball :
	public GameObject
{
public:
	Ball();
	Ball(int sw, int sh, int r, Paddle *p);
	~Ball();
	void update(float dt);
	void render(RenderWindow &w) {
		w.draw(ball);
	};
	void reverseX() {
		velocity.x *= -1;
	};
	void reverseY() {
		velocity.y *= -1;
	};
	void setPosition(float x, float y) {
		ball.setPosition(Vector2f(x, y));
	};
	int getRadius() {
		return radius;
	};
	const Vector2f getPosition() {
		return ball.getPosition();
	};
	
private:
	Vector2f velocity;
	CircleShape ball;
	Paddle * paddle;
	int screen_width;
	int screen_height;
	bool launching;
	int radius;
};

