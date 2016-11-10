#include "Score.h"



Score::Score()
{
}

Score::Score(float &s, int sw, int sh)
{
	score = &s;
	prev_score = s;
	score_font.loadFromFile("font.TTF");
	score_obj.setFont(score_font);
	score_obj.setPosition(0, sh * .8);
	score_obj.setCharacterSize(24);
}


Score::~Score()
{
}

void Score::update(float dt)
{
	if (prev_score < *score) {
		prev_score += 0.1;
	}
	else {
		prev_score = *score;
	}
	ostringstream temp_s;
	temp_s << "Score: " << prev_score;
	score_obj.setString(temp_s.str());
}

void Score::render(RenderWindow & w)
{
	w.draw(score_obj);
}

void Score::increase_score()
{
	*score = *score + 100;
}
