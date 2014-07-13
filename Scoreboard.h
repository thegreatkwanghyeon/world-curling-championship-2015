#pragma once

#include "ScoreManager.h"

using namespace sf;
using namespace std;

class Scoreboard{
	private:

		typedef struct ScorePanel{
			//µﬁ πË∞Ê
			Texture texPanel;
			Sprite spPanel;

			//±π±‚
			Texture texFlag;
			Sprite spFlag;

			//∆¿ ¿Ã∏ß
			Text txtTeamName;

			//¡°ºˆ
			Text txtScore;

			//≥≤¿∫ µπ∏Ê¿Ã
			Texture texStone;
			Sprite spStone;
			vector<Sprite> vecStone;
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
		bool pushScoreAndGoNextEnd(int leftScore, int rightScore);
		int getCurrentTurn();

		

};