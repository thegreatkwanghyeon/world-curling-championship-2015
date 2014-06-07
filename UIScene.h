#pragma once

#include "Director.h"
#include "arrow.h"
#include "powerGauge.h"

using namespace sf;
using namespace std;

class UIScene : public SceneBase{
	private:
		Arrow *arrow;
		PowerGauge *powerGauge;

	public:
		UIScene();
		~UIScene();
		void update();
		void draw(RenderWindow &window);
};
