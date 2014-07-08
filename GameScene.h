#pragma once

#include "Director.h"
#include <Box2D/Box2D.h>
#include "UIScene.h"

using namespace sf;
using namespace std;

const float SCALE = 30.f;
const float STONE_DIAMETER = 1.7f;//ÇÈ¼¿
const float SPEED = 34.5f;//¼Óµµ

class GameScene : public SceneBase{
	private:

		Texture redStoneTexture;
		Texture yellowStoneTexture;
		Texture groundTexture;

		Sprite groundSprite;

		b2World* world;

		Vector2i mouse;

		UIScene* uiScene;

		b2Body* lastStone;

		bool applyImpulse;

		float linearDamping;
		
		bool turn;
		bool moveView;
		float viewMovingSpeed;

	public:
		GameScene();
		~GameScene();

		void createStone(const int &x, const int &y, const int &color);

		void update();
		void draw(RenderWindow &window);
};
