/*
 * PersonPosition.h
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */

#ifndef PERSONPOSITION_H_
#define PERSONPOSITION_H_

class PersonPosition
{
private:

	int x, y;

public:

	PersonPosition();

	PersonPosition(int _x, int _y);

	void setX(int _x);

	void setY(int _y);

	int getX() const;

	int getY() const;
};

#endif /* PERSONPOSITION_H_ */
