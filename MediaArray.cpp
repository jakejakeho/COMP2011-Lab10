/*
 * MediaArray.cpp
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */

#include "MediaArray.h"
#include "lab10.h"

MediaArray::~MediaArray()
{
	delete[] fp;
}

MediaArray::MediaArray(int n)
{
	fp = new MediaReporter[n];
	numMedia = n;
}


void MediaArray::initialize()
{
	for(int i = 0; i < numMedia; i++)
	{
		fp[i].setCoordinates(PersonPosition(NULL_POSITION, NULL_POSITION));
	}
}

int MediaArray::getnumMedia()
{
	return numMedia;
}

MediaReporter* MediaArray::getMediaReporter(int n)
{
	if(n <= numMedia - 1)
	{
		return &fp[n];
	}
	else
	{
		return 0;
	}
}

void MediaArray::setnumMedia(int n)
{
	numMedia = n;
}




