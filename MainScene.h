#pragma once

#include "Director.h"
#include "Button.h"
#include "SelectScene.h"

using namespace sf;
using namespace std;

class MainScene : public SceneBase{
	private:
		Texture texMainLogo;
		Sprite spMainLogo;
		Button *startButton;

	public:
		MainScene();
		~MainScene();
		void update();
		void draw(RenderWindow &window);
};