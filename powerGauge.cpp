#include "stdafx.h"
#include "powerGauge.h"

PowerGauge::PowerGauge() : argumentValue(0.0f), argumentMultiflier(1.8f), PI(atan(1.0)*4){
	texGauge.loadFromFile("image/ui/gauge.png");
	spValue.setTexture(texGauge);
	spValue.setPosition(0.0, 550.0);
}

PowerGauge::PowerGauge(String path) : argumentValue(0.0f), argumentMultiflier(1.8f), PI(atan(1.0)*4){
	texGauge.loadFromFile(path);
	spValue.setTexture(texGauge);
}
PowerGauge::~PowerGauge(){
}

void PowerGauge::update(){
	argumentValue += clock.getElapsedTime().asSeconds() * argumentMultiflier;

	if(argumentValue >=4*PI){
		argumentValue -= 4*PI;
	}


	if(argumentValue>=2*PI){
		powerValue = (float)((cos(argumentValue)+1)/8.f + 0.5);
	}else{
		powerValue = (float)((-cos(argumentValue)+3)/4.f + 0.25);
	}

	/*
		powerValue의 그래프 : http://goo.gl/Lo30P6
		powerValue의 최대최소 : 0.5~1.25

		argumentValue 의 최대최소 : 0~4π
	*/



	
	if(argumentValue <= PI)
		setTextureRect(&spValue, argumentValue/(2*PI) + 0.5);
	else if(PI<argumentValue && argumentValue<=3*PI)
		setTextureRect(&spValue, -(argumentValue/(2*PI))+1.5);
	else if(3*PI < argumentValue) 
		setTextureRect(&spValue, argumentValue/(2*PI) -1.5);

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