#include "stdafx.h"
#include "UIScene.h"

UIScene::UIScene(){
	arrow = new Arrow();
	powerGauge = new PowerGauge();
	button = new Button("image/ui/button.png", Vector2f(500.0,450.0));
	button->setText("next turn", 5);
	buttonEnd = new Button("image/ui/button.png", Vector2f(500.0, 530.0));
	buttonEnd->setText("next end", 5);

	scoreManager = new ScoreManager();
	scoreManager->setLSFE(ScoreManager::Team::Left);

	scoreboard = new Scoreboard(*scoreManager, "SSB", "BOT");
	
}
UIScene::~UIScene(){

}

void UIScene::update(){
	arrow->update();
	powerGauge->update();
	button->update();
	buttonEnd->update();
	scoreboard->update();

	if(button->isClicked()){
		scoreboard->nextTurn();
	}

	if(buttonEnd->isClicked()){
		scoreboard->pushScoreAndGoNextEnd(1,0);
	}





}

void UIScene::draw(RenderWindow &window){
	arrow->draw(window); 
	powerGauge->draw(window);
	button->draw(window);
	buttonEnd->draw(window);
	scoreboard->draw(window);
}