#include "stdafx.h"
#include "SelectScene.h"


SelectScene::SelectScene(){
	mainIndicator = new TeamIndicator();
	mainIndicator->setLeft("Select Team");
	mainIndicator->setRight("Select Team");

	arrTeamName[0] = "Canada";  arrTeamName[4] = "Russia";
	arrTeamName[1] = "Denmark"; arrTeamName[5] = "Sweden";
	arrTeamName[2] = "Japan";   arrTeamName[6] = "Swiss";
	arrTeamName[3] = "Korea";   arrTeamName[7] = "Random";

	for(int i=0; i<8; i++){
		leftButtons[i] = new Button("image/ui/flags_big/"+arrTeamName[i]+".png", Vector2f((i/4)*128.0f, 128.0f*i+100.0f - (i/4)*512.0f));
		rightButtons[i] = new Button("image/ui/flags_big/"+arrTeamName[i]+".png", Vector2f((i/4)*128.0f + 540.0f, 128.0f*i+100.0f - (i/4)*512.0f));
	}
	continueButton = new Button("image/ui/button.png", Vector2f(300.0f, 500.0f));
	continueButton->setText("Continue", 20);
}

SelectScene::~SelectScene(){
}

void SelectScene::update(){
	random_device rd;
	mt19937 rEngine(rd()); 
	uniform_int_distribution<> dist(0,6); 

	mainIndicator->update();
	continueButton->update();

	for(int i=0; i<8; i++){
		leftButtons[i]->update();
		rightButtons[i]->update();

		if(leftButtons[i]->isClicked())
			if(i==7)
				mainIndicator->setLeft(arrTeamName[dist(rEngine)]);
			else
				mainIndicator->setLeft(arrTeamName[i]);
		if(rightButtons[i]->isClicked())
			if(i==7)
				mainIndicator->setRight(arrTeamName[dist(rEngine)]);
			else
				mainIndicator->setRight(arrTeamName[i]);
	}

	if(continueButton->isClicked() && mainIndicator->isValid()){
		Director::getInstance()->pushScene(new GameScene());
	}
	
}

void SelectScene::draw(RenderWindow &window){
	mainIndicator->draw(window);
	continueButton->draw(window);

	for(int i=0; i<8; i++){
		leftButtons[i]->draw(window);
		rightButtons[i]->draw(window);
	}
}