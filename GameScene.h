#pragma once

#include "Director.h"

using namespace sf;
using namespace std;

class GameScene : public SceneBase{
	private:

	public:
		GameScene();
		~GameScene();
		void update();
		void draw(RenderWindow &window);
};
