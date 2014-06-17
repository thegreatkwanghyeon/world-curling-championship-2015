#include "stdafx.h"
#include "ScoreManager.h"

ScoreManager::ScoreManager(){
}

ScoreManager::~ScoreManager(){
}

void ScoreManager::pushScore(int leftScore, int rightScore){
	scoreList.push_back(Score(leftScore, rightScore));
}

vector<ScoreManager::Score> ScoreManager::getScore(){
	return scoreList;
}

void ScoreManager::setLSFE(int team){
	if(team == Team::Left || team == Team::Right)
		lsfe = team;
}

int ScoreManager::getLSFE(){
	if(lsfe)
		return lsfe;
	else 
		return -1;
}