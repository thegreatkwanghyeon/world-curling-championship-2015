#pragma once

#include "Director.h"
#include "arrow.h"
#include "powerGauge.h"
#include "Button.h"

using namespace sf;
using namespace std;

class UIScene : public SceneBase{
	private:
		Arrow *arrow;
		PowerGauge *powerGauge;
		Button *button;

	public:
		UIScene();
		~UIScene();
		void update();
		void draw(RenderWindow &window);
};
