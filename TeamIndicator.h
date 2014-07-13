#pragma once

using namespace sf;
using namespace std;

class TeamIndicator{
	private:
		typedef struct teamBoard{
			Sprite spTeamboard;
			Text txtTeamName;
		} teamBoard;

		Texture texTeamboard;
		Font font;

		teamBoard left, right;

		String arrTeamName[8];
		


	public:
		TeamIndicator();
		~TeamIndicator();
		void update();
		void draw(RenderWindow &window);
		void setLeft(String name);
		void setRight(String name);
		bool isValid();
};