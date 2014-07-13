#pragma once

#include "Director.h"
#include "TeamIndicator.h"
#include "Button.h"
#include "GameScene.h"

using namespace sf;
using namespace std;

class SelectScene: public SceneBase{
	private:
		TeamIndicator *mainIndicator;
		String arrTeamName[8];
		Button *leftButtons[8];
		Button *rightButtons[8];
		Button *continueButton;

	public:
		SelectScene();
		~SelectScene();
		void update();
		void draw(RenderWindow &window);
};