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


	scoreManager = new ScoreManager();
	scoreManager->setLSFE(ScoreManager::Team::Left);

	scoreboard = new Scoreboard(*scoreManager, "CAN", "SWE");

	font.loadFromFile("font/italicNumber.ttf");
	sweepingGauge = new SweepingGauge();

	minimap = new Minimap();

	
}
UIScene::~UIScene(){

}

int UIScene::getCurrentEnd()
{
	return scoreboard->getCurrentEnd();
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

void UIScene::pushStone(float x, float y, int color)
{
	minimap->pushStone(x, y, color);
}

void UIScene::removeStone(int idx){
	minimap->removeStone(idx);
}

void UIScene::clearStone(){
	minimap->clearStone();
}

bool UIScene::pushScore(const int& left, const int& right)
{
	return scoreboard->pushScoreAndGoNextEnd(left, right);
}

int UIScene::getCurrentTurn()
{
	return scoreboard->getCurrentTurn();
}

void UIScene::update(){
	arrow->update();
	powerGauge->update();
	scoreboard->update();
	sweepingGauge->update();
}

void UIScene::draw(RenderWindow &window){
	
	arrow->draw(window); 
	powerGauge->draw(window);
	scoreboard->draw(window);
	minimap->draw(window);

	
}