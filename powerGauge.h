#pragma once

using namespace sf;
using namespace std;

class PowerGauge{
	private:
		const float PI; //원주율
		const float argumentMultiflier; //파워게이지의 진행속도
		Texture texGauge;

		Sprite spCover;
		Sprite spValue;
		Sprite spBackground;

		float powerValue;	//실제 게이지의 값
		float argumentValue;//함수 인자로 들어가는 값

		Clock clock;

		//Member Methods
		void setTextureRect(Sprite *sprite, float argumentValue);


	public:
		PowerGauge();
		PowerGauge(String path);
		~PowerGauge();
		void update();
		void draw(RenderWindow &window);
		float getValue(); //0~1
};