#include "stdafx.h"
#include "Scoreboard.h"

Scoreboard::Scoreboard(ScoreManager &scoreList, String teamNameTop, String teamNameBottom){

	//Parameter initializing
	this->scoreList = &scoreList;
	top.txtTeamName.setString(teamNameTop);
	bottom.txtTeamName.setString(teamNameBottom);
	currentTurn = scoreList.getLSFE();
	currentEnd = 1;

	//Graphic processing
	top.texPanel.loadFromFile("image/ui/scoreboard.png");
	top.spPanel.setTexture(top.texPanel);
	bottom.texPanel.loadFromFile("image/ui/scoreboard.png");
	bottom.spPanel.setTexture(bottom.texPanel);
	texEndPanel.loadFromFile("image/ui/scoreboard.png");
	spEndPanel.setTexture(texEndPanel);

	top.spPanel.setPosition(0.0,0.0);
	bottom.spPanel.setPosition(0.0, bottom.spPanel.getTexture()->getSize().y);
	spEndPanel.setPosition(0.0, bottom.spPanel.getTexture()->getSize().y*2.0);

	texCursor.loadFromFile("image/ui/cursor.png");
	spCursor.setTexture(texCursor);


	//Text processing
	font.loadFromFile("font/italicNumber.ttf");
	top.txtScore.setFont(font);
	bottom.txtScore.setFont(font);
	top.txtTeamName.setFont(font);
	bottom.txtTeamName.setFont(font);
	top.txtScore.setCharacterSize(30);
	top.txtTeamName.setCharacterSize(20);
	bottom.txtScore.setCharacterSize(30);
	bottom.txtTeamName.setCharacterSize(20);
	txtCurrentEnd.setFont(font);
	txtCurrentEnd.setCharacterSize(20);
	txtCurrentEnd.setString("END " +to_string(currentEnd));

	top.txtTeamName.setPosition(
		top.spPanel.getPosition().x + top.txtTeamName.getLocalBounds().width/2,
		top.spPanel.getPosition().y + top.spPanel.getTexture()->getSize().y/2 - top.txtTeamName.getLocalBounds().height/1.25
	);

	bottom.txtTeamName.setPosition(
		bottom.spPanel.getPosition().x + bottom.txtTeamName.getLocalBounds().width/2,
		bottom.spPanel.getPosition().y + bottom.spPanel.getTexture()->getSize().y/2 - bottom.txtTeamName.getLocalBounds().height/1.25
	);

	txtCurrentEnd.setPosition(
		spEndPanel.getPosition().x +spEndPanel.getTexture()->getSize().x/2 - txtCurrentEnd.getLocalBounds().width/2,
		spEndPanel.getPosition().y +spEndPanel.getTexture()->getSize().y/2 - txtCurrentEnd.getLocalBounds().height/1.25
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
	txtCurrentEnd.setString("END " +to_string(currentEnd));

	top.txtScore.setPosition(
		top.spPanel.getPosition().x + top.spPanel.getTexture()->getSize().x - top.txtScore.getLocalBounds().width-15,
		top.spPanel.getPosition().y + top.spPanel.getTexture()->getSize().y/2 - top.txtScore.getLocalBounds().height/1.25
	);
	bottom.txtScore.setPosition(
		bottom.spPanel.getPosition().x + bottom.spPanel.getTexture()->getSize().x - bottom.txtScore.getLocalBounds().width-15,
		bottom.spPanel.getPosition().y + bottom.spPanel.getTexture()->getSize().y/2 - bottom.txtScore.getLocalBounds().height/1.25
	);

	if(currentTurn == ScoreManager::Team::Left)
		spCursor.setPosition(top.txtScore.getPosition().x-30, top.txtScore.getPosition().y+3);
	else if(currentTurn == ScoreManager::Team::Right)
		spCursor.setPosition(bottom.txtScore.getPosition().x-30, bottom.txtScore.getPosition().y+3);
	else
		spCursor.setPosition(0.0, 0.0);



}

void Scoreboard::draw(RenderWindow &window){

	window.draw(top.spPanel);
	window.draw(bottom.spPanel);
	window.draw(spEndPanel);
	window.draw(top.txtScore);
	window.draw(bottom.txtScore);
	window.draw(top.txtTeamName);
	window.draw(bottom.txtTeamName);
	window.draw(txtCurrentEnd);
	window.draw(spCursor);
}

void Scoreboard::nextTurn(){
	if(currentTurn == ScoreManager::Team::Left)
		currentTurn = ScoreManager::Team::Right;
	else if(currentTurn == ScoreManager::Team::Right)
		currentTurn = ScoreManager::Team::Left;
}

void Scoreboard::pushScoreAndGoNextEnd(int leftScore, int rightScore){
	scoreList->pushScore(leftScore, rightScore);
	currentEnd++;

	if(leftScore>rightScore)
		currentTurn = ScoreManager::Team::Left;
	else if(leftScore<rightScore)
		currentTurn = ScoreManager::Team::Right;
	else if(leftScore==rightScore){
		nextTurn();
	}

}