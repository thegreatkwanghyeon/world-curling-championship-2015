#include "stdafx.h"
#include "SweepingGauge.h"

SweepingGauge::SweepingGauge() : isPressed(false), sweepigSpeed(0.0f){
}

SweepingGauge::~SweepingGauge(){
}

void SweepingGauge::update(){
	if(Keyboard::isKeyPressed(Keyboard::Space) && isPressed==false){
		isPressed = true;
		listClock.push_back(new Clock());
		listClock.back()->restart();
	}else if(!Keyboard::isKeyPressed(Keyboard::Space)){
		isPressed = false;
	}

	if(!(listClock.empty()))
		if(listClock.front()->getElapsedTime().asSeconds()>1.0)
			listClock.pop_front();
}

void SweepingGauge::draw(RenderWindow &window){
}

float SweepingGauge::getSpeed(){
	return listClock.size();
}