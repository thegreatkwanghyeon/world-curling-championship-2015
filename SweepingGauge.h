#pragma once

using namespace sf;
using namespace std;

class SweepingGauge{
	private:
		float sweepigSpeed;
		bool isPressed;
		list<Clock*> listClock;
		

	public:
		SweepingGauge();
		~SweepingGauge();
		void update();
		void draw(RenderWindow &window);
		float getSpeed();
};
