#pragma once

using namespace sf;
using namespace std;

class PowerGauge{
	private:
		const float PI; //������
		const float argumentMultiflier; //�Ŀ��������� ����ӵ�
		Texture texGauge;

		Sprite spCover;
		Sprite spValue;
		Sprite spBackground;

		float powerValue;	//���� �������� ��
		float argumentValue;//�Լ� ���ڷ� ���� ��

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