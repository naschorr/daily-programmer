#include <iostream>
#include <vector>
#include <conio.h>

#include "stick.h"

using namespace std;

void sortForRemoval(vector<Stick*>& vector)
{
	for( int n=0; n<vector.size(); n++ )
	{
		for( int i=1; i<vector.size(); i++ )
		{
			float slope = (vector[i-1]->getHighest().y - vector[i-1]->getLowest().y)/(vector[i-1]->getHighest().x - vector[i-1]->getLowest().x);
			float nextSlope = (vector[i]->getHighest().y - vector[i-1]->getLowest().y)/(vector[i]->getHighest().x - vector[i-1]->getLowest().x);

			if( nextSlope > slope )
			{
				Stick* temp = vector[i];
				vector.erase(vector.begin()+i);
				vector.insert(vector.begin()+i-1, temp);

			}
		}
	}
}

void reverseVector(vector<Stick*>& vector)
{
	Stick* swap;
	int length = vector.size();

	for( int i=0; i<length/2; i++ )
	{
		swap = vector[length - 1 - i];
		vector[length - 1 - i] = vector[i];
		vector[i] = swap;
	}
}

void insertionSortAvgHeight(vector<Stick*>& vector)
{
	int index;
	Stick* value;

	for( int i=1; i<vector.size(); i++ )
	{
		value = vector[i];
		index = i - 1;

		while( index >= 0 && vector[index]->getAvgHeight() >= value->getAvgHeight() )
		{
			vector[index + 1] = vector[index];
			index--;
		}

		vector[index + 1] = value;
	}
}

vector<Stick*> orderSticks(vector<Stick*> sticks)
{
	insertionSortAvgHeight(sticks);
	reverseVector(sticks);
	sortForRemoval(sticks);

	return sticks;
}

int main()
{
	vector<Stick*> sticks;

	/*
	sticks.push_back(new Stick(1,0,3,4,5));
	sticks.push_back(new Stick(2,2,3,8,1));
	sticks.push_back(new Stick(3,4,0,5,1));
	sticks.push_back(new Stick(4,1,3,4.2,1));
	*/

	sticks.push_back(new Stick(1,1,6,12,6));
	sticks.push_back(new Stick(2,1,7,1,15));
	sticks.push_back(new Stick(3,11,1,13,10));
	sticks.push_back(new Stick(4,14,10,15,6));
	sticks.push_back(new Stick(5,15,2,15,5));
	sticks.push_back(new Stick(6,12,1,14,11));

	vector<Stick*> orderedSticks = orderSticks(sticks);

	for( int i=0; i<orderedSticks.size(); i++ )
	{
		cout << orderedSticks[i]->getID() << ", ";
	}

	cout << endl;

	_getch();

	return 0;
}