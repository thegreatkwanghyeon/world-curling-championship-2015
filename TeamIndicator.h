#pragma once

using namespace sf;
using namespace std;

class TeamIndicator{
	private:
		typedef struct teamBoard{
			Sprite spTeamboard;
			String strTeamName;
		} teamBoard;
		Texture texTeamboard;
		


	public:
		TeamIndicator();
		~TeamIndicator();
		void update();
		void draw(RenderWindow &window);
};