#pragma once

#include "SceneBase.h"

class Director{
	private:

		static Director* pInstance;

		std::vector<SceneBase*> sceneList;

		Director();
		~Director();

	public:
		static Director* getInstance();

		static void freeInstance();

		void pushScene(SceneBase* scene);

		void popScene();

		void replaceScene(SceneBase* scene);

		void update();

		void draw(sf::RenderWindow& window);

		void setNewScene();
};
