/*
 * Person.h
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "PersonPosition.h"

class Person
{
private:

	PersonPosition coords;

public:

	Person();  // Constructor

	void setCoordinates(PersonPosition p);

	PersonPosition* getCoordinates();
};

#endif /* PERSON_H_ */
