#include "stdafx.h"
#include "UIScene.h"

UIScene::UIScene(){
	arrow = new Arrow();
	powerGauge = new PowerGauge();
	button = new Button("image/ui/button.png", Vector2f(500.0,500.0));
	button->setText("gauge value", 5);

	scoreManager = new ScoreManager();
	scoreManager->pushScore(1,0);
	scoreManager->pushScore(2,0);
	scoreManager->pushScore(0,5);

	scoreboard = new Scoreboard(*scoreManager, "SSB", "BOT");
	
}
UIScene::~UIScene(){

}

float UIScene::getDirection()
{
	return arrow->getDirection();
}

float UIScene::getPower()
{
	return powerGauge->getValue();
}

void UIScene::update(){
	arrow->update();
	powerGauge->update();
	button->update();
	scoreboard->update();

	if(button->isClicked()){
		printf("%f\n",powerGauge->getValue());
	}

}

void UIScene::draw(RenderWindow &window){
	arrow->draw(window); 
	powerGauge->draw(window);
	button->draw(window);
	scoreboard->draw(window);
}