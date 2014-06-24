#pragma once

#include "Director.h"
#include <Box2D/Box2D.h>
#include "UIScene.h"

using namespace sf;
using namespace std;

const float SCALE = 30.f;
const float STONE_DIAMETER = 1.7f;//ÇÈ¼¿
const float SPEED = 30.f;//¼Óµµ

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
