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

		
	
		vector<Score> scoreList;
		int lsfe; //Last Stone First End; 어떤 팀이 첫엔드에 후공잡았는지?

	public:
		
		enum Team{
			Left,
			Right
		};

		ScoreManager();
		~ScoreManager();
		void pushScore(int leftScore, int rightScore);
		vector<Score> getScore();
		void setLSFE(int team);
		int getLSFE();
		

};