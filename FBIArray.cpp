/*
 * FBIArray.cpp
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */

#include "FBIArray.h"
#include "lab10.h"
#define NULL_POSITION -1
FBIArray::FBIArray(int n)
{
	fp = new FBIAgent[n];
	numFBI = n;
}

FBIArray::~FBIArray()
{
	delete[] fp;
}

int FBIArray::getnumFBI()
{
	return numFBI;
}

void FBIArray::initialize()
{
	for(int i = 0; i < numFBI; i++)
	{
		fp[i].setCoordinates(PersonPosition(NULL_POSITION, NULL_POSITION));
	}
}

FBIAgent* FBIArray::getFBIAgent(int n)
{
	if(n <= numFBI - 1)
	{
		return &fp[n];
	}
	else
	{
		return 0;
	}
}

void FBIArray::setnumFBI(int n)
{
	numFBI = n;
}




