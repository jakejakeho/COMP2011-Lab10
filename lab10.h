/*
 * lab10.h
 *
 *  Created on: 30 Mar, 2017
 *      Author: Kenneth Au
 */

#include <stdlib.h>     /* srand, rand, abs */
#include <string>

#include "PersonPosition.h"
#include "Game.h"

class Game;

#ifndef LAB10_H_
#define LAB10_H_

#define MAX_COUNT 					10
#define	NULL_POSITION				-1
#define TOUCH_COUNT_FOR_WINNING		5
#define	LEVEL_TO_WIN				10

using namespace std;

enum Movement {
	Stay = 0, Up, Down, Left, Right
};

enum GameResult {
	GameOver = -1, GameContinue = 0, GameStageClear = 1
};

string unsignedIntToString(unsigned int i);
bool initializeGame(Game* game, int width, int height,int level = 1);
PersonPosition generatePositionWithoutPerson(const Game* game);
bool isSamePosition(const PersonPosition* A, const PersonPosition* B);
string progressBar(int count, int total);
string printGameboard(const Game* game);
void personMove(Game* game, PersonPosition* pos, Movement move);
void trumpMove(Game* game, char input);
void wander(Game* game, PersonPosition* pos);
void wander(Game* game);
int calculateManhattanDistance(const PersonPosition* A, const PersonPosition* B);
GameResult gameCheck(Game* game);
void levelUp(Game* game);
void cleanMemory(Game* game);

#endif /* LAB8_H_ */
