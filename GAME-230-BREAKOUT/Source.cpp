#include "GameObject.h"
#include "Brick.h"
#include "Paddle.h"
#include "Ball.h"


const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;
void update_state(float dt);
void render_frame();


vector<GameObject*> SceneGraph;

RenderWindow window;
Texture t1, t2, t3, t4;
vector<Texture> texts;


int main()
{
	
	
	window.create(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Put something clever here");
	Paddle * paddle = new Paddle(SCREEN_WIDTH, SCREEN_HEIGHT);
	Ball * ball = new Ball(SCREEN_WIDTH, SCREEN_HEIGHT, 10, paddle);
	t1.loadFromFile("tex1.png");
	t2.loadFromFile("tex2.png");
	t3.loadFromFile("tex3.png");
	texts.push_back(t4);
	texts.push_back(t3);
	texts.push_back(t2);
	texts.push_back(t1);
	int k;
	for (float i = SCREEN_HEIGHT * .1, k = 2; i < SCREEN_HEIGHT * .3; i += SCREEN_HEIGHT * .1, k--) {
		for (float j = SCREEN_WIDTH * .1; j < SCREEN_WIDTH * .9; j += SCREEN_WIDTH * .1) {
			Brick *b = new Brick(j, i, SCREEN_WIDTH, SCREEN_HEIGHT, k, ball);
			SceneGraph.push_back(b);
		}
	}
	SceneGraph.push_back(paddle);
	SceneGraph.push_back(ball);

	Clock clock;

	while (window.isOpen())
	{
		Event  event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float dt = clock.restart().asSeconds();

		update_state(dt);
		render_frame();
		window.display();
	}

	return 0;
}

void update_state(float dt)
{
	for (auto i = SceneGraph.begin(); i != SceneGraph.end(); ++i) {
		(*i)->update(dt);
	}
	for (auto i = SceneGraph.begin(); i != SceneGraph.end(); ++i) {
		if (auto j = dynamic_cast<Brick*>(*i)) {
			if (j->getLives() <= 0) {
				delete j;
				SceneGraph.erase(i);
				break;
			}
			else {
				j->setTexture(texts[j->getLives()]);
			}
		}
	}
}

void render_frame()
{
	window.clear(Color(0, 0, 255));
	for (auto i = SceneGraph.begin(); i != SceneGraph.end(); ++i) {
		(*i)->render(window);
	}
}
