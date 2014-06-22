#pragma once

using namespace sf;
using namespace std;

class Minimap{
	private:

		const Vector2f mapCoord;

		typedef struct stone{
			float x;
			float y;
			float distance;
			Sprite spStone;

			stone(float x, float y, Texture &texStone, Vector2f mapCoord){
				this->spStone.setTexture(texStone);
				this->spStone.setOrigin(texStone.getSize().x/2, texStone.getSize().y/2);
				spStone.setPosition(
						mapCoord.x + 100.0 + x,
						mapCoord.y + 100.0 + y
				);
			}
		}stone;

		Texture texMap;
		Sprite spMap;

		Texture texRedStone;
		Texture texYellowStone;

		vector<stone> vecStones;




	public:
		enum Color{
			red,
			yellow
		};

		Minimap();
		~Minimap();
		void update();
		void draw(RenderWindow &window);
		void pushStone(float x, float y, int color);
		void removeStone(int idx);
		void clearStone();
};