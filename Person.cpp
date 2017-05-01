/*
 * Person.cpp
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */
#include "Person.h"

Person::Person()
{
	coords = PersonPosition();
}

void Person::setCoordinates(PersonPosition p)
{
	coords = p;
}

PersonPosition* Person::getCoordinates()
{
	return &coords;
}


