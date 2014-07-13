#pragma once

#include "Director.h"
#include "arrow.h"
#include "powerGauge.h"
#include "Button.h"
#include "ScoreManager.h"
#include "Scoreboard.h"
#include "SweepingGauge.h"
#include "Minimap.h"

using namespace sf;
using namespace std;

class UIScene : public SceneBase{
	private:
		Arrow *arrow;
		PowerGauge *powerGauge;
		ScoreManager *scoreManager;
		Scoreboard *scoreboard;
		SweepingGauge *sweepingGauge;
		Minimap *minimap;


		Font font;

	public:
		UIScene();
		~UIScene();

		float getDirection();
		float getPower();
		float getSpeed();

		void pushStone(float x, float y, int color);//���� : 400, 7173
		void removeStone(int idx);
		void clearStone();

		bool pushScore(const int& left, const int& right);

		void nextTurn();

		void update();
		void draw(RenderWindow &window);
};
