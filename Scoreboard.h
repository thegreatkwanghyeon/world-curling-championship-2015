#pragma once

#include "ScoreManager.h"

using namespace sf;
using namespace std;

class Scoreboard{
	private:

		typedef struct ScorePanel{
			//�� ���
			Texture texPanel;
			Sprite spPanel;

			//����
			Texture texFlag;
			Sprite spFlag;

			//�� �̸�
			Text txtTeamName;

			//����
			Text txtScore;
		} ScorePanel;


		ScoreManager *scoreList;
		ScorePanel top, bottom;

		Font font;

		



	public:
		Scoreboard(ScoreManager &scoreList, String teamNameTop, String teamNameBottom);
		~Scoreboard();
		void update();
		void draw(RenderWindow &window);

		

};