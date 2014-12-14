#include "stick.h"

Stick::Stick(int id, float x1, float y1, float x2, float y2)
{
	mID = id;
	mX1 = x1;
	mY1 = y1;
	mX2 = x2;
	mY2 = y2;
}

Stick::coord Stick::getLowLeft()
{
	int x, y = 0;

	if( mX1 <= mX2 )
	{
		x = mX1;
	}
	else
	{
		x = mX2;
	}

	if( mY1 <= mY2 )
	{
		y = mY1;
	}
	else
	{
		y = mY2;
	}

	coord lowLeft = {x,y};

	return lowLeft;
}

Stick::coord Stick::getUpRight()
{
	int x, y = 0;

	if( mX1 <= mX2 )
	{
		x = mX2;
	}
	else
	{
		x = mX1;
	}

	if( mY1 <= mY2 )
	{
		y = mY2;
	}
	else
	{
		y = mY1;
	}

	coord upRight = {x,y};

	return upRight;
}

float Stick::getAvgHeight()
{
	return (mY1 + mY2)/2;
}

int Stick::getID()
{
	return mID;
}