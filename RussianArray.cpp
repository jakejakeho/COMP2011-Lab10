/*
 * RussianArray.cpp
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */

#include "RussianArray.h"
#include "lab10.h"

RussianArray::RussianArray(int n)
{
	fp = new RussianAgent[n];
	numRussian = n;
}

RussianArray::~RussianArray()
{
	delete[] fp;
}

void RussianArray::initialize()
{
	for(int i = 0; i < numRussian; i++)
	{
		fp[i].setCoordinates(PersonPosition(NULL_POSITION, NULL_POSITION));
	}
}

RussianAgent* RussianArray::getRussianAgent(int n)
{
	// cout << n << " " << numRussian;
	if(n <= numRussian - 1)
	{
		return &fp[n];
	}
	else
	{
		return 0;
	}
}

void RussianArray::setnumRussian(int n)
{
	numRussian = n;
}

int RussianArray::getnumRussian()
{
	return numRussian;
}




