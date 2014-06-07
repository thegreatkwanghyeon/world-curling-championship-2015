#pragma once

class SceneBase{
	private:

	public:

		SceneBase();

		virtual ~SceneBase();

		virtual void update()=0;
		virtual void draw(sf::RenderWindow& window)=0;
		virtual int changeScene();

};
