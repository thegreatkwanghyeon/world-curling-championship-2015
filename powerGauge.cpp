#include "stdafx.h"
#include "powerGauge.h"

PowerGauge::PowerGauge() : argumentValue(0.0f), argumentMultiflier(1.8f){
	texGauge.loadFromFile("image/ui/gauge.png");
	spValue.setTexture(texGauge);
}

PowerGauge::PowerGauge(String path) : argumentValue(0.0f), argumentMultiflier(1.8f){
	texGauge.loadFromFile(path);
	spValue.setTexture(texGauge);
}
PowerGauge::~PowerGauge(){
}

void PowerGauge::update(){
	argumentValue += clock.getElapsedTime().asSeconds() * argumentMultiflier;
	//powerValue = (float)(sin(argumentValue) + 1) * 0.5f;
	powerValue = 0.5f;
	setTextureRect(&spValue, powerValue);
	clock.restart();
}

void PowerGauge::draw(RenderWindow &window){
	window.draw(spValue);
}

void PowerGauge::setTextureRect(Sprite *sprite, float argumentValue){
	IntRect tmpRect = sprite->getTextureRect();

	tmpRect.width = (int)(sprite->getTexture()->getSize().x * argumentValue);

	sprite->setTextureRect(tmpRect);
}

float PowerGauge::getValue(){
	return powerValue;
}