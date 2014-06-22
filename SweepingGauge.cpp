#include "stdafx.h"
#include "SweepingGauge.h"

SweepingGauge::SweepingGauge() : isPressed(false), sweepigSpeed(0.0f), sweepingCount(0){
}

SweepingGauge::~SweepingGauge(){
}

void SweepingGauge::update(){
	if(Keyboard::isKeyPressed(Keyboard::Space) && isPressed==false){
		isPressed = true;
		sweepingCount++;
		if(sweepingCount == 1){
			clock.restart();
		}
	}else if(!Keyboard::isKeyPressed(Keyboard::Space)){
		isPressed = false;
	}

	//printf("%.2f\n", (float)sweepingCount/clock.getElapsedTime().asSeconds());
}

void SweepingGauge::draw(RenderWindow &window){
}

void SweepingGauge::clearRecord(){
	sweepingCount = 0;
}

float SweepingGauge::getSpeed(){
	return (float)sweepingCount/clock.getElapsedTime().asSeconds();
}