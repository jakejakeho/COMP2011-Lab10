/*
 * Game.cpp
 *
 *  Created on: 2017¦~5¤ë1¤é
 *      Author: Jake
 */

#include "Game.h"
#include "lab10.h"

Game::Game()
{
	trump = NULL;
	russianArray = NULL;
	mediaArray = NULL;
	fbiArray = NULL;
	width = 0;
	height = 0;
	moveCount = 0;
	touchWithRussianAgentsCount = 0;
	level = 0;
	FBIHidingProbability = 0;
}

int Game::getHeight()
{
	return height;
}


