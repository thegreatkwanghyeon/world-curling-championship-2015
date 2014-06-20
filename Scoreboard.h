#pragma once

#include "ScoreManager.h"

using namespace sf;
using namespace std;

class Scoreboard{
	private:

		typedef struct ScorePanel{
			//µÞ ¹è°æ
			Texture texPanel;
			Sprite spPanel;

			//±¹±â
			Texture texFlag;
			Sprite spFlag;

			//ÆÀ ÀÌ¸§
			Text txtTeamName;

			//Á¡¼ö
			Text txtScore;
		} ScorePanel;

		Texture texCursor;
		Sprite spCursor;
		Texture texEndPanel;
		Sprite spEndPanel;

		Text txtCurrentEnd;

		ScoreManager *scoreList;
		ScorePanel top, bottom;

		Font font;

		int lsfe;
		int currentTurn;
		int currentEnd;

		



	public:
		Scoreboard(ScoreManager &scoreList, String teamNameTop, String teamNameBottom);
		~Scoreboard();
		void update();
		void draw(RenderWindow &window);
		void nextTurn();
		void pushScoreAndGoNextEnd(int leftScore, int rightScore);

		

};