#include "stick.h"

Stick::Stick(int id, float x1, float y1, float x2, float y2)
{
	mID = id;
	mX1 = x1;
	mY1 = y1;
	mX2 = x2;
	mY2 = y2;
}

Stick::coord Stick::getLeft()
{
	coord left = {mX1, mY1};

	if( mX1 < mX2 )
	{
		return left;
	}
	else
	{
		left.x = mX2;
		left.y = mY2;

		return left;
	}
}

Stick::coord Stick::getRight()
{
	coord right = {mX1, mY1};

	if( mX1 > mX2 )
	{
		return right;
	}
	else
	{
		right.x = mX2;
		right.y = mY2;

		return right;
	}
}

Stick::coord Stick::getHighest()
{
	coord high = {mX1, mY1};

	if( mY1 > mY2 )
	{
		return high;
	}
	else
	{
		high.x = mX2;
		high.y = mY2;

		return high;
	}
}

Stick::coord Stick::getLowest()
{
	coord low = {mX1, mY1};

	if( mY1 < mY2 )
	{
		return low;
	}
	else
	{
		low.x = mX2;
		low.y = mY2;

		return low;
	}
}

float Stick::getAvgHeight()
{
	return (mY1 + mY2)/2;
}

int Stick::getID()
{
	return mID;
}