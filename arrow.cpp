#include "stdafx.h"
#include "arrow.h"

Arrow::Arrow() : additionalDirection(0), direction(0), PI(atan(1.0)*4){
	texArrow.loadFromFile("image/ui/arrow.png");
	spArrow.setTexture(texArrow);
	spArrow.setOrigin(spArrow.getLocalBounds().width/2, spArrow.getLocalBounds().height);
	spArrow.setPosition(300,300);
}

Arrow::Arrow(String path) : additionalDirection(0), direction(0), PI(atan(1.0)*4){
	texArrow.loadFromFile(path);
	spArrow.setTexture(texArrow);
	spArrow.setOrigin(spArrow.getLocalBounds().width/2, spArrow.getLocalBounds().height);
}

Arrow::~Arrow(){
}

void Arrow::update(){
	//setReferencePoint((Vector2f)sf::Mouse::getPosition());
	spArrow.setRotation(direction * 180 / PI + 90);

}

void Arrow::draw(RenderWindow &window){
	window.draw(spArrow);
	setReferencePoint((Vector2f)sf::Mouse::getPosition(window));
}

void Arrow::setReferencePoint(Vector2f point){
	//direction = atan2(point.y - spArrow.getPosition().y, point.x - spArrow.getPosition().x);
	direction = PI/-2;
}

float Arrow::getDirection(){
	return direction;
}