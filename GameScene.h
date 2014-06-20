#pragma once

#include "Director.h"
#include <Box2D/Box2D.h>
#include "UIScene.h"

using namespace sf;
using namespace std;

const float SCALE = 30.f;
const float SPEED = 100.f;

class GameScene : public SceneBase{
	private:

		Texture stoneTexture;

		b2World* world;

		Vector2i mouse;

		UIScene* uiScene;

		b2Body* lastStone;

		bool applyImpulse;

	public:
		GameScene();
		~GameScene();

		void createStone(const int &x, const int &y);

		void update();
		void draw(RenderWindow &window);
};
