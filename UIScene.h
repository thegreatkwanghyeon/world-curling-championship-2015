#pragma once

#include "Director.h"
#include "arrow.h"
#include "powerGauge.h"
#include "Button.h"
#include "ScoreManager.h"
#include "Scoreboard.h"
#include "SweepingGauge.h"

using namespace sf;
using namespace std;

class UIScene : public SceneBase{
	private:
		Arrow *arrow;
		PowerGauge *powerGauge;
		Button *button;
		Button *buttonEnd;
		Button *buttonClear;
		ScoreManager *scoreManager;
		Scoreboard *scoreboard;
		SweepingGauge *sweepingGauge;

		Font font;
		Text sweepingRecord;

	public:
		UIScene();
		~UIScene();

		float getDirection();
		float getPower();

		void update();
		void draw(RenderWindow &window);
};
