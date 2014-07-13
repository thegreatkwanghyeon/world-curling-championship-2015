#include "stdafx.h"
#include "Scoreboard.h"
#include "Global.h"

Scoreboard::Scoreboard(ScoreManager &scoreList, String teamNameTop, String teamNameBottom){

	//Parameter initializing
	this->scoreList = &scoreList;
	top.txtTeamName.setString(globalTeamNameLeft);
	bottom.txtTeamName.setString(globalTeamNameRight);
	currentTurn = scoreList.getLSFE();
	currentEnd = 1;

	//Graphic processing
	top.texPanel.loadFromFile("image/ui/scoreboard.png");
	top.spPanel.setTexture(top.texPanel);
	top.texStone.loadFromFile("image/ui/redstone.png");
	top.spStone.setTexture(top.texStone);
	bottom.texPanel.loadFromFile("image/ui/scoreboard.png");
	bottom.spPanel.setTexture(bottom.texPanel);
	bottom.texStone.loadFromFile("image/ui/yellowstone.png");
	bottom.spStone.setTexture(bottom.texStone);
	texEndPanel.loadFromFile("image/ui/scoreboard.png");
	spEndPanel.setTexture(texEndPanel);
	
	//flag
	top.texFlag.loadFromFile("image/ui/flags/"+globalTeamNameLeft+".png");
	top.spFlag.setTexture(top.texFlag);
	bottom.texFlag.loadFromFile("image/ui/flags/"+globalTeamNameRight+".png");
	bottom.spFlag.setTexture(bottom.texFlag);





	top.spPanel.setPosition(0.0,0.0);
	bottom.spPanel.setPosition(0.0, top.spPanel.getPosition().y + bottom.spPanel.getTexture()->getSize().y);
	spEndPanel.setPosition(0.0, top.spPanel.getPosition().y + bottom.spPanel.getTexture()->getSize().y*2.0);

	for(int i=0; i<8; i++){
		top.vecStone.push_back(top.spStone);
		top.vecStone.at(i).setPosition(top.texPanel.getSize().x + i*top.vecStone.at(i).getTexture()->getSize().x, 
										top.texPanel.getSize().y/2 - top.vecStone.at(i).getTexture()->getSize().y/2);
		bottom.vecStone.push_back(bottom.spStone);
		bottom.vecStone.at(i).setPosition(bottom.texPanel.getSize().x + i*bottom.vecStone.at(i).getTexture()->getSize().x, 
										bottom.texPanel.getSize().y/2 - bottom.vecStone.at(i).getTexture()->getSize().y/2 + bottom.spPanel.getTexture()->getSize().y);
	}

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




}

void Scoreboard::draw(RenderWindow &window){
	
	top.spPanel.setPosition(window.mapPixelToCoords(Vector2i(0, 0)));
	bottom.spPanel.setPosition(0.0, top.spPanel.getPosition().y + bottom.spPanel.getTexture()->getSize().y);
	spEndPanel.setPosition(0.0, top.spPanel.getPosition().y + bottom.spPanel.getTexture()->getSize().y*2.0);
	top.spFlag.setPosition(0.0f,top.spPanel.getPosition().y );
	bottom.spFlag.setPosition(0.0f,top.spPanel.getTexture()->getSize().y + top.spPanel.getPosition().y );

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

	top.txtScore.setPosition(
		top.spPanel.getPosition().x + top.spPanel.getTexture()->getSize().x - top.txtScore.getLocalBounds().width-15,
		top.spPanel.getPosition().y + top.spPanel.getTexture()->getSize().y/2 - top.txtScore.getLocalBounds().height/1.25
	);
	bottom.txtScore.setPosition(
		bottom.spPanel.getPosition().x + bottom.spPanel.getTexture()->getSize().x - bottom.txtScore.getLocalBounds().width-15,
		bottom.spPanel.getPosition().y + bottom.spPanel.getTexture()->getSize().y/2 - bottom.txtScore.getLocalBounds().height/1.25
	);

	for(auto& stone: top.vecStone)
		stone.setPosition(top.spPanel.getPosition().x + top.texPanel.getSize().x + (&stone-&top.vecStone[0])*stone.getTexture()->getSize().x, 
										top.spPanel.getPosition().y +top.texPanel.getSize().y/2 - stone.getTexture()->getSize().y/2);
	for(auto& stone: bottom.vecStone)
		stone.setPosition(bottom.spPanel.getPosition().x + bottom.texPanel.getSize().x + (&stone-&bottom.vecStone[0])*stone.getTexture()->getSize().x, 
										top.spPanel.getPosition().y + bottom.texPanel.getSize().y/2 - stone.getTexture()->getSize().y/2 + bottom.spPanel.getTexture()->getSize().y);



	if(currentTurn == ScoreManager::Team::Left)
		spCursor.setPosition(top.txtScore.getPosition().x-30, top.txtScore.getPosition().y+3);
	else if(currentTurn == ScoreManager::Team::Right)
		spCursor.setPosition(bottom.txtScore.getPosition().x-30, bottom.txtScore.getPosition().y+3);
	else
		spCursor.setPosition(0.0, 0.0);


	window.draw(top.spPanel);
	window.draw(bottom.spPanel);
	window.draw(top.spFlag);
	window.draw(bottom.spFlag);
	window.draw(spEndPanel);
	window.draw(top.txtScore);
	window.draw(bottom.txtScore);
	window.draw(top.txtTeamName);
	window.draw(bottom.txtTeamName);
	window.draw(txtCurrentEnd);
	window.draw(spCursor);

	for(auto stone: top.vecStone){
		window.draw(stone);
	}
	for(auto stone: bottom.vecStone){
		window.draw(stone);
	}	
}

void Scoreboard::nextTurn(){
	if(currentTurn == ScoreManager::Team::Left){
		currentTurn = ScoreManager::Team::Right;
		top.vecStone.pop_back();
	}
	else if(currentTurn == ScoreManager::Team::Right){
		currentTurn = ScoreManager::Team::Left;
		bottom.vecStone.pop_back();
	}
}

int Scoreboard::getCurrentTurn()
{
	return currentTurn;
}

bool Scoreboard::pushScoreAndGoNextEnd(int leftScore, int rightScore){
	if(!top.vecStone.empty() || !bottom.vecStone.empty()){
		printf("Can't go to next end\n");
		return false;
	}

	scoreList->pushScore(leftScore, rightScore);
	currentEnd++;

	if(leftScore>rightScore)
		currentTurn = ScoreManager::Team::Left;
	else if(leftScore<rightScore)
		currentTurn = ScoreManager::Team::Right;
	else if(leftScore==rightScore){
		nextTurn();
	}

	for(int i=0; i<8; i++){
		//top.vecStone.clear();
		top.vecStone.push_back(top.spStone);
		top.vecStone.at(i).setPosition(top.texPanel.getSize().x + i*top.vecStone.at(i).getTexture()->getSize().x, 
										top.texPanel.getSize().y/2 - top.vecStone.at(i).getTexture()->getSize().y/2);
		//bottom.vecStone.clear();
		bottom.vecStone.push_back(bottom.spStone);
		bottom.vecStone.at(i).setPosition(bottom.texPanel.getSize().x + i*bottom.vecStone.at(i).getTexture()->getSize().x, 
										bottom.texPanel.getSize().y/2 - bottom.vecStone.at(i).getTexture()->getSize().y/2 + bottom.spPanel.getTexture()->getSize().y);
	}
}