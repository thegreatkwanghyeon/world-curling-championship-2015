#include "stdafx.h"
#include "Scoreboard.h"

Scoreboard::Scoreboard(ScoreManager &scoreList, String teamNameTop, String teamNameBottom){

	//Parameter initializing
	this->scoreList = &scoreList;
	top.txtTeamName.setString(teamNameTop);
	bottom.txtTeamName.setString(teamNameBottom);

	//Graphic processing
	top.texPanel.loadFromFile("image/ui/scoreboard.png");
	top.spPanel.setTexture(top.texPanel);
	bottom.texPanel.loadFromFile("image/ui/scoreboard.png");
	bottom.spPanel.setTexture(bottom.texPanel);

	top.spPanel.setPosition(0.0,0.0);
	bottom.spPanel.setPosition(0.0, bottom.spPanel.getTexture()->getSize().y);

	//Text processing
	font.loadFromFile("font/italicNumber.ttf");
	top.txtScore.setFont(font);
	bottom.txtScore.setFont(font);
	top.txtTeamName.setFont(font);
	bottom.txtTeamName.setFont(font);
	top.txtTeamName.setCharacterSize(20);
	bottom.txtTeamName.setCharacterSize(20);

	top.txtTeamName.setPosition(
		top.spPanel.getPosition().x + top.txtTeamName.getLocalBounds().width/2,
		top.spPanel.getPosition().y + top.spPanel.getTexture()->getSize().y/2 - top.txtTeamName.getLocalBounds().height/1.25
	);

	bottom.txtTeamName.setPosition(
		bottom.spPanel.getPosition().x + bottom.txtTeamName.getLocalBounds().width/2,
		bottom.spPanel.getPosition().y + bottom.spPanel.getTexture()->getSize().y/2 - bottom.txtTeamName.getLocalBounds().height/1.25
	);


}

Scoreboard::~Scoreboard(){
}

void Scoreboard::update(){
	int topTotal = 0;
	int bottomTotal = 0;


	for(auto score: scoreList->getScore()){
		topTotal += score.leftScore;
		bottomTotal += score.rightScore;
	}

	top.txtScore.setString(to_string(topTotal));
	bottom.txtScore.setString(to_string(bottomTotal));

	top.txtScore.setPosition(
		top.spPanel.getPosition().x + top.spPanel.getTexture()->getSize().x - top.txtScore.getLocalBounds().width*2,
		top.spPanel.getPosition().y + top.spPanel.getTexture()->getSize().y/2 - top.txtScore.getLocalBounds().height/1.25
	);
	bottom.txtScore.setPosition(
		bottom.spPanel.getPosition().x + bottom.spPanel.getTexture()->getSize().x - bottom.txtScore.getLocalBounds().width*2,
		bottom.spPanel.getPosition().y + bottom.spPanel.getTexture()->getSize().y/2 - bottom.txtScore.getLocalBounds().height/1.25
	);
}

void Scoreboard::draw(RenderWindow &window){

	window.draw(top.spPanel);
	window.draw(bottom.spPanel);
	window.draw(top.txtScore);
	window.draw(bottom.txtScore);
	window.draw(top.txtTeamName);
	window.draw(bottom.txtTeamName);
}