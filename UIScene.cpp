#include "stdafx.h"
#include "UIScene.h"

UIScene::UIScene(){
	arrow = new Arrow();
	powerGauge = new PowerGauge();
	button = new Button("image/ui/button.png", Vector2f(500.0,450.0));
	button->setText("next turn", 20);
	buttonEnd = new Button("image/ui/button.png", Vector2f(500.0, 530.0));
	buttonEnd->setText("next end", 20);
	buttonClear = new Button("image/ui/button.png", Vector2f(500.0, 390.0));
	buttonClear->setText("Clear sweepGauge", 20);

	scoreManager = new ScoreManager();
	scoreManager->setLSFE(ScoreManager::Team::Left);

	scoreboard = new Scoreboard(*scoreManager, "SSB", "BOT");

	font.loadFromFile("font/italicNumber.ttf");
	sweepingGauge = new SweepingGauge();
	sweepingRecord.setFont(font);
	sweepingRecord.setCharacterSize(20);
	sweepingRecord.setPosition(690.0, 390.0);
	sweepingRecord.setColor(Color(255, 0, 0, 255));
	sweepingRecord.setString("sweep");
	
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
	buttonEnd->update();
	buttonClear->update();
	scoreboard->update();
	sweepingGauge->update();

	if(button->isClicked()){
		scoreboard->nextTurn();
	}

	if(buttonEnd->isClicked()){
		scoreboard->pushScoreAndGoNextEnd(1,0);
	}

	if(buttonClear->isClicked()){
		sweepingGauge->clearRecord();
	}

	sweepingRecord.setString(to_string(sweepingGauge->getSpeed()));
}

void UIScene::draw(RenderWindow &window){
	
	arrow->draw(window); 
	powerGauge->draw(window);
	button->draw(window);
	buttonEnd->draw(window);
	buttonClear->draw(window);
	scoreboard->draw(window);
	window.draw(sweepingRecord) ;

	
}