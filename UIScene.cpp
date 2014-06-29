#include "stdafx.h"
#include "UIScene.h"
#include <random>

UIScene::UIScene(){
	random_device rd;
	mt19937 rEngine(rd()); 
	normal_distribution<> dist(0,50); 
	auto randX = dist(rEngine); 
	auto randY = dist(rEngine);

	arrow = new Arrow();
	powerGauge = new PowerGauge();
	button = new Button("image/ui/button.png", Vector2f(500.0,450.0));
	button->setText("next turn", 20);

	buttonEnd = new Button("image/ui/button.png", Vector2f(500.0, 530.0));
	buttonEnd->setText("next end", 20);

	scoreManager = new ScoreManager();
	scoreManager->setLSFE(ScoreManager::Team::Left);

	scoreboard = new Scoreboard(*scoreManager, "SSB", "BOT");

	font.loadFromFile("font/italicNumber.ttf");
	sweepingGauge = new SweepingGauge();
	sweepingRecord.setFont(font);
	sweepingRecord.setCharacterSize(20);
	sweepingRecord.setPosition(690.0, 390.0);
	sweepingRecord.setColor(Color(255, 0, 0, 255));

	minimap = new Minimap();
	minimap->pushStone(randX, randY, Minimap::Color::red);
	minimap->pushStone(randY/2.0, randX/3.0, Minimap::Color::yellow);
	minimap->pushStone(0.0, 0.0, Minimap::Color::red);
	minimap->pushStone(0.0, 0.0, Minimap::Color::yellow); //이건 지워질 예정
	minimap->removeStone(3);  //지움
	
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

float UIScene::getSpeed()
{
	return sweepingGauge->getSpeed();
}

void UIScene::nextTurn()
{
	scoreboard->nextTurn();
}

void UIScene::update(){
	arrow->update();
	powerGauge->update();
	button->update();
	buttonEnd->update();
	scoreboard->update();
	sweepingGauge->update();

	if(button->isClicked()){
		scoreboard->nextTurn();
	}

	if(buttonEnd->isClicked()){
		scoreboard->pushScoreAndGoNextEnd(1,0);
	}


	sweepingRecord.setString(to_string(sweepingGauge->getSpeed()));
}

void UIScene::draw(RenderWindow &window){
	
	arrow->draw(window); 
	powerGauge->draw(window);
	button->draw(window);
	buttonEnd->draw(window);
	scoreboard->draw(window);
	minimap->draw(window);
	window.draw(sweepingRecord) ;

	
}