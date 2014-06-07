#pragma once

#include "Director.h"
#include <Box2D/Box2D.h>

using namespace sf;
using namespace std;

const float SCALE = 30.f;

class GameScene : public SceneBase{
	private:

		Texture groundTexture;
		Texture boxTexture;

		b2World* world;

		Vector2i mouse;

	public:
		GameScene();
		~GameScene();

		void createGround(const int &x, const int &y);
		void createBox(const int &x, const int &y);

		void update();
		void draw(RenderWindow &window);
};
