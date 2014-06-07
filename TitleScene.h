#pragma once

#include "Director.h"

using namespace sf;
using namespace std;

class TitleScene : public SceneBase{
	private:

	public:
		TitleScene();
		~TitleScene();
		void update();
		void draw(RenderWindow &window);
};
