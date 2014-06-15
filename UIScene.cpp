#include "stdafx.h"
#include "UIScene.h"

UIScene::UIScene(){
	arrow = new Arrow();
	powerGauge = new PowerGauge();
	button = new Button("image/ui/button.png", Vector2f(500.0,500.0));
	button->setText("gauge value", 5);
}
UIScene::~UIScene(){

}

void UIScene::update(){
	arrow->update();
	powerGauge->update();
	button->update();

	if(button->isClicked()){
		printf("%f\n",powerGauge->getValue());
	}

}

void UIScene::draw(RenderWindow &window){
	arrow->draw(window); 
	powerGauge->draw(window);
	button->draw(window);
}