#pragma once


using namespace sf;
using namespace std;

class Arrow {
	private:
		const double PI; //ø¯¡÷¿≤

		Texture texArrow;
		Sprite spArrow;
		float direction;
		float additionalDirection;
		

	public:
		Arrow();
		Arrow(String path);
		~Arrow();
		void update();
		void draw(RenderWindow &window);
		void setReferencePoint(Vector2f point);
		float getDirection();
};