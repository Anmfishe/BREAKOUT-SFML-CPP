#pragma once
#include "GameObject.h"
#include "Ball.h"
class Brick :
	public GameObject
{
public:
	Brick();
	Brick(float x, float y, int sw, int sh, int l, Ball * b);
	~Brick();
	void update(float dt);
	void render(RenderWindow &w) {
		w.draw(brick);
	};
	void lower_life() {
		lives--;
	};
	int getLives() {
		return lives;
	};
	void setTexture(Texture & t) {
		brick.setTexture(&t);
	}
private:
	Ball * ball;
	RectangleShape brick;
	int brick_width;
	int brick_height;
	int lives;
	
};

