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

int Game::getHeight() const
{
	return height;
}

int Game::getWidth() const
{
	return width;
}

int Game::getLevel() const
{
	return level;
}

float Game::getFBIHidingProbability() const
{
	return FBIHidingProbability;
}

int Game::getMoveCount() const
{
	return moveCount;
}

int Game::getTouchWithRussianAgentsCount() const
{
	return touchWithRussianAgentsCount;
}

Trump* Game::getTrump() const
{
	return trump;
}

RussianArray* Game::getRussianArray() const
{
	return russianArray;
}

MediaArray* Game::getMediaArray() const
{
	return mediaArray;
}

FBIArray* Game::getFBIArray() const
{
	return fbiArray;
}

PersonPosition* Game::getDoubleAgentAtIndex(int index)
{
	return doubleAgents[index];
}

void Game::setDoubleAgentAtIndex(int index, PersonPosition* p)
{
	doubleAgents[index] = p;
}

void Game::setWidth(int width)
{
	this->width = width;
}

void Game::setHeight(int height)
{
	this->height = height;
}

void Game::setMoveCount(int moveCount)
{
	this->moveCount = moveCount;
}

void Game::setTouchWithRussianAgentsCount(int value)
{
	this->touchWithRussianAgentsCount = value;
}

void Game::setLevel(int level)
{
	this->level = level;
}

void Game::setFBIHidingProbability(float prob)
{
	this->FBIHidingProbability = prob;
}

void Game::setTrump(Trump* t)
{
	this->trump = t;
}

void Game::setRussianArray(RussianArray * r)
{
	this->russianArray = r;
}

void Game::setMediaArray(MediaArray *m)
{
	this->mediaArray = m;
}

void Game::setFBIArray(FBIArray* f)
{
	this->fbiArray = f;
}
