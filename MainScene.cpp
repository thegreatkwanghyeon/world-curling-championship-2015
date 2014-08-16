#include "stdafx.h"
#include "MainScene.h"

MainScene::MainScene(){
	texMainLogo.loadFromFile("image/logo.png");
	texBg.loadFromFile("image/ice.jpg");
	spMainLogo.setTexture(texMainLogo);
	spBg.setTexture(texBg);
	spMainLogo.setOrigin(Vector2f(texMainLogo.getSize().x / 2, texMainLogo.getSize().y / 2));
	spMainLogo.setPosition(400.0f, 200.0f);

	startButton = new Button("image/ui/button.png", Vector2f(300.0f, 400.0f));
	startButton->setText("New Game", 22);

}

MainScene::~MainScene(){

}

void MainScene::update(){
	startButton->update();

	if (startButton->isClicked()){
		Director::getInstance()->replaceScene(new SelectScene());
	}

}

void MainScene::draw(RenderWindow &window){
	window.draw(spBg);
	window.draw(spMainLogo);
	
	startButton->draw(window);

}