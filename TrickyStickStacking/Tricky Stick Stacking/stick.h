#ifndef STICK_H
#define STICK_H

class Stick
{
private:
	float mID;
	float mX1;
	float mY1;
	float mX2;
	float mY2;

public:
	struct coord
	{
		float x;
		float y;
	};
	Stick(int id, float x1, float y1, float x2, float y2);
	coord getLeft();
	coord getRight();
	coord getLowest();
	coord getHighest();
	float getAvgHeight();
	int getID();
};

#endif