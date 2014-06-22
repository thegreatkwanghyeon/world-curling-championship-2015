#pragma once

using namespace sf;
using namespace std;

class SweepingGauge{
	private:
		float sweepigSpeed;
		int sweepingCount;
		bool isPressed;

		Clock clock;
		

	public:
		SweepingGauge();
		~SweepingGauge();
		void update();
		void draw(RenderWindow &window);
		void clearRecord();
		float getSpeed();
};
