#pragma once

using namespace sf;
using namespace std;



class ScoreManager{
	private:
		
		typedef struct Score{

			Score(const int leftScore, const int rightScore) : leftScore(leftScore), rightScore(rightScore){}

			unsigned int leftScore;
			unsigned int rightScore;
		} Score;

		enum Team{
			Left,
			Right
		};
	
		vector<Score> scoreList;
		int lsfe; //Last Stone First End; � ���� ù���忡 �İ���Ҵ���?


	public:
		
		ScoreManager();
		~ScoreManager();
		void pushScore(int leftScore, int rightScore);
		vector<Score> getScore();
		void setLSFE(int team);
		int getLSFE();
		

};