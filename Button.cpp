#include "stdafx.h"
#include "Button.h"

Button::Button(const String path, const Vector2f position = Vector2f(0,0)){
	texButton.loadFromFile(path);
	spButton.setTexture(texButton);

	spButton.setPosition(this->position = position);
	buttonRect = Rect<float>(position, (Vector2f)texButton.getSize());

	font.loadFromFile("font/italicNumber.ttf");
}

Button::~Button(){
}

void Button::update(){
	if(Mouse::isButtonPressed(Mouse::Button::Left) ){
		if(buttonRect.contains(mousePosition)){
			spButton.setColor(Color(240,240,240,255));
			clicked=true;
		}
	}else{
		spButton.setColor(Color(255,255,255,255));
		clicked = false;
	}
}

void Button::draw(RenderWindow &window){
	mousePosition = move(Vector2f((float)Mouse::getPosition(window).x, (float)Mouse::getPosition(window).y));
	window.draw(spButton);
	window.draw(name);
}
void Button::setText(const String name, const int characterSize = 14){
	(this->name).setString(name);
	(this->name).setFont(font);
	(this->name).setCharacterSize(characterSize);
	(this->name).setPosition(
		position.x + texButton.getSize().x/2 - (this->name).getLocalBounds().width/2,
		position.y + texButton.getSize().y/2 - (this->name).getLocalBounds().height*1.25
		);
	
}

Vector2f Button::getPosition(){
	return position;
}

bool Button::isClicked(){
	return clicked;
}