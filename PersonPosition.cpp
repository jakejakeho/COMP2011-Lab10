/*
 * PersonPosition.cpp
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */

#include "PersonPosition.h"

PersonPosition::PersonPosition()
{
	x  = 0;
	y =  0;
}

PersonPosition::PersonPosition(int _x, int _y)
{
	x = _x;
	y = _y;
}

void PersonPosition::setX(int _x)
{
	x = _x;
}

void PersonPosition::setY(int _y)
{
	y = _y;
}

int PersonPosition::getX() const
{
	return x;
}

int PersonPosition::getY() const
{
	return y;
}



