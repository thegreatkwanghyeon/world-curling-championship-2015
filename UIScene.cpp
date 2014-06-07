#include "stdafx.h"
#include "UIScene.h"

UIScene::UIScene(){
	arrow = new Arrow();
	powerGauge = new PowerGauge();
}
UIScene::~UIScene(){

}

void UIScene::update(){
	arrow->update();
	powerGauge->update();
}

void UIScene::draw(RenderWindow &window){
	arrow->draw(window); 
	powerGauge->draw(window);
}