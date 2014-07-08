#pragma once

#include "Director.h"

using namespace sf;
using namespace std;

class SelectScene: public SceneBase{
	private:

	public:
		SelectScene();
		~SelectScene();
		void update();
		void draw(RenderWindow &window);
};