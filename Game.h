/*
 * Game.h
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */

#ifndef GAME_H_
#define GAME_H_

#include "lab10.h"
#include "PersonPosition.h"
#include "RussianArray.h"
#include "MediaArray.h"
#include "FBIArray.h"
#include "Person.h"
#define MAX_COUNT 					10
#define	NULL_POSITION				-1
#define TOUCH_COUNT_FOR_WINNING		5
#define	LEVEL_TO_WIN				10

typedef Person Trump;

class Game
{
private:
	Trump* trump;

	RussianArray* russianArray;

	MediaArray* mediaArray;

	FBIArray* fbiArray;

	int width, height;

	int moveCount, touchWithRussianAgentsCount;

	int level;

	float FBIHidingProbability;

	PersonPosition *doubleAgents[MAX_COUNT];

public:
	Game(); // Constructor

	int getHeight() const;

	int getWidth() const;

	int getLevel() const;

	float getFBIHidingProbability() const;

	int getMoveCount() const;

	int getTouchWithRussianAgentsCount() const;

	Trump* getTrump() const;

	RussianArray* getRussianArray() const;

	MediaArray* getMediaArray() const;

	FBIArray* getFBIArray() const;

	PersonPosition* getDoubleAgentAtIndex(int index);	// Get coordinates of double agent at index

	void setDoubleAgentAtIndex(int index, PersonPosition* p); // Set coordinates of double agent at position index to p

	void setWidth(int width);

	void setHeight(int height);

	void setMoveCount(int moveCount);

	void setTouchWithRussianAgentsCount(int value);

	void setLevel(int level);

	void setFBIHidingProbability(float prob);

	void setTrump(Trump* t);

	void setRussianArray(RussianArray * r);

	void setMediaArray(MediaArray * m);

	void setFBIArray(FBIArray * f);

};

#endif /* GAME_H_ */
