#pragma once

using namespace sf;
using namespace std;

#include <functional>

class Button {
	private:
		Texture texButton;
		Sprite spButton;

		Font font;
		Text name;

		Rect<float> buttonRect;
		Vector2f position;
		Vector2f mousePosition;

		bool clicked;

	public:
		
		Button(const String path, const Vector2f position);
		~Button();
		void update();
		void draw(RenderWindow &window);
		void setText(const String name, const int characterSize);
		
		Vector2f getPosition();
		bool isClicked();
};

