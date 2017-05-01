/*
 * lab10-main.cpp
 *
 *  Created on: 13 Apr, 2017
 *      Author: Kevin Wang, credit Kenneth & Sathish 
 */

#include "lab10.h"
#include <stdlib.h>     /* srand, rand, abs */
#include <string>
#include <iostream>
#include <time.h>       /* time */
#include <sstream>

#define IS_SAME_POSITION(__a,__b)		((bool)((__a)->getX() ==(__b)->getX() && (__a)->getY() == (__b)->getY()))

char getGameboardCharAt(string s, PersonPosition p) {
	stringstream ss(s);
	char row[99];
	ss.getline(row, 99);	// Clear the current line

	for (int i = 0; i <= p.getY(); ++i) {
		ss.getline(row, 99);
	}

	return row[p.getX() * 3 + 1];
}

void lab10ProgramCheck() {
	bool taskCheckWrong[11];
	fill_n(taskCheckWrong, 11, false);
	Game* g = new Game;

	const PersonPosition TEST_DIM[10] = {PersonPosition(2,5), PersonPosition(3,3), PersonPosition(6,5), PersonPosition(8,6), PersonPosition(4,4),
			PersonPosition(7,3), PersonPosition(25,10), PersonPosition(5, 5), PersonPosition(10, 10), PersonPosition(11,31)};

	// Task 1 check
	{

		for (int level = 1; level <= 10; ++level) {
			const int w = TEST_DIM[level-1].getX(), h = TEST_DIM[level-1].getY();

			const bool result = initializeGame(g, w, h, level);

			// Game parameter check
			if (!result || g->getWidth() != w || g->getHeight() != h
					|| g->getLevel() != level || g->getMoveCount() != 0 || g->getTouchWithRussianAgentsCount() != 0
					|| g->getTrump()->getCoordinates()->getX() != 0 || g->getTrump()->getCoordinates()->getY() != g->getHeight() - 1) {
				taskCheckWrong[0] = true;
			}
			cleanMemory(g);
		}

		bool result = initializeGame(g, 0, 0, 1);
		result = result || initializeGame(g, -10, -10, 2);
		result = result || initializeGame(g, 3, 3, 3);
		result = result || initializeGame(g, 5, 3, 5);
		result = result || initializeGame(g, 6, 4, 8);
		result = result || initializeGame(g, -4, -7, 9);
		result = result || initializeGame(g, 30, 1, 10);
		if (result)
			taskCheckWrong[0] = true;
	}
	cout << "Check Task 1" << endl;


	// Task 2 check
	{
		const PersonPosition positions[10] = {
				PersonPosition(0, 0), PersonPosition(6, 3), PersonPosition(2, 8), PersonPosition(11, 7), PersonPosition(4,0),
				PersonPosition(13, 0), PersonPosition(12, 7), PersonPosition(6, 7), PersonPosition(2, 5), PersonPosition(4, 9)};

		for (int i = 0; i < 10; ++i) {
			// Two same position
			if (!isSamePosition(&positions[i], &positions[i])) {
				taskCheckWrong[1] = true;
			}

			for (int j = i + 1; j < 10; ++j) {
				// Two different position
				if (isSamePosition(&positions[i], &positions[j])) {
					taskCheckWrong[1] = true;
				}
			}
		}
	}
	cout << "Check Task 2" << endl;

	if (!taskCheckWrong[0])
	{
		// Task 3 check
		{
			initializeGame(g, 6, 6, 10);
			bool isRandom = false;
			PersonPosition prevP = generatePositionWithoutPerson(g);
			for (int x = 0; x <= 100 && !taskCheckWrong[2]; ++x) {
				PersonPosition p = generatePositionWithoutPerson(g);
				// Test if the position is valid
				if (p.getX() < 0 || p.getX() >= g->getWidth() || p.getY() < 0 || p.getY() >= g->getHeight()) {
					taskCheckWrong[2] = true;
				}

				// Treat it to be random if two generated position are different
				if (!IS_SAME_POSITION(&prevP, &p)) {isRandom = true;}


				// Check if randPosition overlap with trump
				if (IS_SAME_POSITION(&p, g->getTrump()->getCoordinates())) {taskCheckWrong[2] = true;}

				// Check if randPosition overlap with others
				for (int i = 0; i < g->getLevel() && !taskCheckWrong[2]; ++i) {
					if (IS_SAME_POSITION(&p, g->getRussianArray()->getRussianAgent(i)->getCoordinates())
							|| IS_SAME_POSITION(&p, g->getMediaArray()->getMediaReporter(i)->getCoordinates())
							|| IS_SAME_POSITION(&p, g->getFBIArray()->getFBIAgent(i)->getCoordinates())
					) {
						taskCheckWrong[2] = true;
					}
				}
			}

			if (!isRandom) {
				taskCheckWrong[2] = true;
			}
		}

		cleanMemory(g);
		cout << "Check Task 3" << endl;

		// Task 4 check
		taskCheckWrong[3] = false;
		for (int level = 1; level <= 10 && !taskCheckWrong[3]; ++level) {
			const int w = TEST_DIM[level-1].getX(), h = TEST_DIM[level-1].getY();
			initializeGame(g, w, h, level);

			// Set some overlapping cases
			if (level == 3) {
				g->getRussianArray()->getRussianAgent(1)->setCoordinates(*g->getFBIArray()->getFBIAgent(2)->getCoordinates());
			} else if (level == 5) {
				g->getMediaArray()->getMediaReporter(2)->setCoordinates(*g->getRussianArray()->getRussianAgent(3)->getCoordinates());
			} else if (level == 8) {
				g->getMediaArray()->getMediaReporter(3)->setCoordinates(*g->getTrump()->getCoordinates());
				g->getRussianArray()->getRussianAgent(4)->setCoordinates(*g->getTrump()->getCoordinates());
			}
			else if (level == 10) {
				g->getFBIArray()->getFBIAgent(0)->setCoordinates(*g->getTrump()->getCoordinates());
				g->getMediaArray()->getMediaReporter(0)->setCoordinates(*g->getTrump()->getCoordinates());
				g->getRussianArray()->getRussianAgent(7)->setCoordinates(*g->getTrump()->getCoordinates());
			}
			g->setMoveCount(rand() % 100);
			int moveCount = g->getMoveCount();
			g->setTouchWithRussianAgentsCount(rand() % TOUCH_COUNT_FOR_WINNING);
			int touchCount = g->getTouchWithRussianAgentsCount();
			string output = printGameboard(g);
			stringstream ss(output);
			string tmpStr = "";
			int tmpInt = 0;
			ss >> tmpStr >> tmpInt;
			if (tmpStr != "Level" || tmpInt != level) {
				taskCheckWrong[3] = true;
				break;
			}

			ss >> tmpStr >> tmpInt;
			if (tmpStr != "Move:" || tmpInt != moveCount) {
				taskCheckWrong[3] = true;
				break;
			}

			ss >> tmpStr;
			if (tmpStr != progressBar(touchCount, TOUCH_COUNT_FOR_WINNING)) {
				taskCheckWrong[3] = true;
				break;
			}
			char row[99];
			ss.getline(row, 99);	// Clear the current line
			for (int i = 0; i < h && !taskCheckWrong[3]; ++i) {
				ss.getline(row, 99);

				for (int j = 0; j < w && !taskCheckWrong[3]; ++j) {
					char* cell = &row[j * 3];

					PersonPosition p = PersonPosition(j, i);
					bool isTrumpHere = false;
					char c = '.';	// Expected char
					char cIfNotF = '.';	// Expected char if 'F' is invisible


					if (IS_SAME_POSITION(&p, g->getTrump()->getCoordinates())) {
						isTrumpHere = true;
						c = cIfNotF = 'T';
					}
					for (int k = 0; k < g->getLevel(); ++k) {
						if (IS_SAME_POSITION(g->getFBIArray()->getFBIAgent(k)->getCoordinates(), &p)) {
							c = 'F';
						} else if (IS_SAME_POSITION(g->getMediaArray()->getMediaReporter(k)->getCoordinates(), &p) && c != 'F') {
							c = 'M';
						} else if (IS_SAME_POSITION(g->getRussianArray()->getRussianAgent(k)->getCoordinates(), &p)
								&& c != 'F' && c != 'M') {
							c = 'R';
						}

						if (IS_SAME_POSITION(g->getMediaArray()->getMediaReporter(k)->getCoordinates(), &p)) {
							cIfNotF = 'M';
						} else if (IS_SAME_POSITION(g->getRussianArray()->getRussianAgent(k)->getCoordinates(), &p)
								&& cIfNotF != 'M') {
							cIfNotF = 'R';
						}
					}
					if (isTrumpHere) {
						if (cell[0] != '*' || cell[2] != '*') {
							taskCheckWrong[3] = true;
							break;
						}
					}

					if (cell[1] != c && cell[1] != cIfNotF) {
						taskCheckWrong[3] = true;
						break;
					}
				}
			}
			cleanMemory(g);
		}
		cout << "Check Task 4 - Part 1" << endl;

		// Task 4 check Part 2
		{
			for (int i = 0; i <= 1 && !taskCheckWrong[3]; ++i) {
				initializeGame(g, 10, 10, 10);
				g->setFBIHidingProbability ((float)i);

				for (int level = 1; level <= 10 && !taskCheckWrong[3]; ++level) {
					wander(g);
					string output = printGameboard(g);
					char c = getGameboardCharAt(output, *g->getFBIArray()->getFBIAgent(level-1)->getCoordinates());
					//cout << c << "," ;
					if ((i == 0 && c != 'F') || (i == 1 && c == 'F')) {
						cout << "Task 4: Something is wrong with the FBI random hiding 1" << endl;
						taskCheckWrong[3] = true;
					}
				}
				cleanMemory(g);
			}

			const int testCount = 300;
			const float allownace = 0.25;
			for (float pTest = 0.25; pTest < 0.99; pTest += 0.25) {
				initializeGame(g, 10, 10, 10);
				g->setFBIHidingProbability ((float)pTest);
				int FBIHidingCount[10] = {0};

				for (int _ = 0; _ < testCount; ++_) {
					wander(g);
					string output = printGameboard(g);
					for (int level = 1; level <= 10 && !taskCheckWrong[3]; ++level) {
						char c = getGameboardCharAt(output, *g->getFBIArray()->getFBIAgent(level-1)->getCoordinates());
						if (c != 'F') {
							FBIHidingCount[level-1]++;
						}
					}
				}
				for (int level = 1; level <= 10 && !taskCheckWrong[3]; ++level) {
					//cout << (float)FBIHidingCount[level - 1] / testCount << ", ";
					float hidingRate = (float)FBIHidingCount[level - 1] / testCount;
					if (hidingRate < pTest - allownace / 2
							|| hidingRate > pTest + allownace / 2) {
						cout << "Task 4: Something is wrong with the FBI random hiding 2" << endl;
						taskCheckWrong[3] = true;
					}
				}
				cleanMemory(g);
			}


		}
		cout << "Check Task 4 - Part 2" << endl;

		// Task 5 check
		{
			const int w = rand() % 10 + 10, h = rand() % 10 + 10;
			initializeGame(g, w, h);
			PersonPosition p = PersonPosition(0,0);

			personMove(g, &p, Up);
			if (p.getX() != 0 || p.getY() != 0) {
				taskCheckWrong[4] = true;
			}
			personMove(g, &p, Left);
			if (p.getX() != 0 || p.getY() != 0) {
				taskCheckWrong[4] = true;
			}
			personMove(g, &p, Down);
			if (p.getX() != 0 || p.getY() != 1) {
				taskCheckWrong[4] = true;
			}
			personMove(g, &p, Right);
			if (p.getX() != 1 || p.getY() != 1) {
				taskCheckWrong[4] = true;
			}
			personMove(g, &p, Up);
			if (p.getX() != 1 || p.getY() != 0) {
				taskCheckWrong[4] = true;
			}
			personMove(g, &p, Left);
			if (p.getX() != 0 || p.getY() != 0) {
				taskCheckWrong[4] = true;
			}

			p.setX(g->getWidth() - 1);
			p.setY(g->getHeight() - 1);
			personMove(g, &p, Down);
			if (p.getX() != w - 1 || p.getY() != h - 1) {
				taskCheckWrong[4] = true;
			}
			personMove(g, &p, Right);
			if (p.getX() != w - 1 || p.getY() != h - 1) {
				taskCheckWrong[4] = true;
			}
			personMove(g, &p, Up);
			if (p.getX() != w - 1 || p.getY() != h - 2) {
				taskCheckWrong[4] = true;
			}
			personMove(g, &p, Left);
			if (p.getX() != w - 2 || p.getY() != h - 2) {
				taskCheckWrong[4] = true;
			}
			personMove(g, &p, Right);
			if (p.getX() != w - 1 || p.getY() != h - 2) {
				taskCheckWrong[4] = true;
			}
			personMove(g, &p, Down);
			if (p.getX() != w - 1 || p.getY() != h - 1) {
				taskCheckWrong[4] = true;
			}

			cleanMemory(g);
		}
		cout << "Check Task 5" << endl;

		// Task 6 check
		{
			const int w = rand() % 10 + 10, h = rand() % 10 + 10;
			initializeGame(g, w, h);
			trumpMove(g, 'x');
			if (g->getTrump()->getCoordinates()->getX() != 0 || g->getTrump()->getCoordinates()->getY() != h - 1) {
				taskCheckWrong[5] = true;
			}
			trumpMove(g, 'd');
			if (g->getTrump()->getCoordinates()->getX() != 1 || g->getTrump()->getCoordinates()->getY() != h - 1) {
				taskCheckWrong[5] = true;
			}
			trumpMove(g, 's');
			if (g->getTrump()->getCoordinates()->getX() != 1 || g->getTrump()->getCoordinates()->getY() != h - 1) {
				taskCheckWrong[5] = true;
			}
			trumpMove(g, 'w');
			if (g->getTrump()->getCoordinates()->getX() != 1 || g->getTrump()->getCoordinates()->getY() != h - 2) {
				taskCheckWrong[5] = true;
			}
			trumpMove(g, 'a');
			if (g->getTrump()->getCoordinates()->getX() != 0 || g->getTrump()->getCoordinates()->getY() != h - 2) {
				taskCheckWrong[5] = true;
			}
			trumpMove(g, 'a');
			if (g->getTrump()->getCoordinates()->getX() != 0 || g->getTrump()->getCoordinates()->getY() != h - 2) {
				taskCheckWrong[5] = true;
			}
			trumpMove(g, 's');
			if (g->getTrump()->getCoordinates()->getX() != 0 || g->getTrump()->getCoordinates()->getY() != h - 1) {
				taskCheckWrong[5] = true;
			}
			cleanMemory(g);
		}
		cout << "Check Task 6" << endl;
		// Task 7 check
		{
			const int w = rand() % 10 + 10, h = rand() % 10 + 10;
			initializeGame(g, w, h);
			PersonPosition p = PersonPosition(0, 0);
			PersonPosition prevP = PersonPosition(0, 0);
			int movementCount[5] = {0};
			fill_n(movementCount, 5, 0);
			for (int i = 0; i < 200 && !taskCheckWrong[6]; ++i) {
				wander(g, &p);
				if (p.getX() == prevP.getX() && p.getY() == prevP.getY()) {
					movementCount[Stay]++;
				} else if (p.getX() == prevP.getX() && p.getY() == prevP.getY() - 1) {
					movementCount[Up]++;
				} else if (p.getX() == prevP.getX() && p.getY() == prevP.getY() + 1) {
					movementCount[Down]++;
				} else if (p.getX() == prevP.getX() - 1 && p.getY() == prevP.getY()) {
					movementCount[Left]++;
				} else if (p.getX() == prevP.getX() + 1 && p.getY() == prevP.getY()) {
					movementCount[Right]++;
				} else {
					// Wander move than expected
					taskCheckWrong[6] = true;
					break;
				}
				prevP = p;
			}
			if (!movementCount[Stay] || !movementCount[Up] || !movementCount[Down] || !movementCount[Left] || !movementCount[Right]) {
				taskCheckWrong[6] = true;
			}
			cleanMemory(g);
		}
		cout << "Check Task 7" << endl;

		//Task 8 check
		{
			const int w = rand() % 10 + 10, h = rand() % 10 + 10;
			initializeGame(g, w, h, 10);
			PersonPosition ra[MAX_COUNT], m[MAX_COUNT], f[MAX_COUNT];
			for (int i = 0; i < 10; ++i) {
				ra[i] = *g->getRussianArray()->getRussianAgent(i)->getCoordinates();
				m[i] = *g->getMediaArray()->getMediaReporter(i)->getCoordinates();
				f[i] = *g->getFBIArray()->getFBIAgent(i)->getCoordinates();
			}
			bool raAllSame = true, mAllSame = true, fAllSame = true;

			for (int _ = 0; _ < 100; ++_) {
				wander(g);
				for (int i = 0; i < 10; ++i) {
					if (!IS_SAME_POSITION(&ra[i], g->getRussianArray()->getRussianAgent(i)->getCoordinates())) {
						raAllSame = false;
					}
					if (!IS_SAME_POSITION(&m[i], g->getMediaArray()->getMediaReporter(i)->getCoordinates())) {
						mAllSame = false;
					}
					if (!IS_SAME_POSITION(&f[i], g->getFBIArray()->getFBIAgent(i)->getCoordinates())) {
						fAllSame = false;
					}
				}
			}

			if (raAllSame || mAllSame || fAllSame) {
				taskCheckWrong[7] = true;
				cout<<"a"<<endl;
			}

			// Check if an RA stay when Trump is nearby
			const int TEST_X = 3, TEST_Y = 5;
			g->getRussianArray()->getRussianAgent(5)->setCoordinates(PersonPosition(TEST_X, TEST_Y));

			g->getTrump()->setCoordinates(PersonPosition(TEST_X -2, TEST_Y));
			for (int _ = 0; _ < 100; ++_) {
				wander(g);
				if (g->getRussianArray()->getRussianAgent(5)->getCoordinates()->getX() != TEST_X || g->getRussianArray()->getRussianAgent(5)->getCoordinates()->getY() != TEST_Y) {
					taskCheckWrong[7] = true;
				}
			}

			g->getTrump()->setCoordinates(PersonPosition(TEST_X - 1, TEST_Y + 1));
			for (int _ = 0; _ < 100; ++_) {
				wander(g);
				if (g->getRussianArray()->getRussianAgent(5)->getCoordinates()->getX() != TEST_X || g->getRussianArray()->getRussianAgent(5)->getCoordinates()->getY() != TEST_Y) {
					taskCheckWrong[7] = true;
				}
			}

			g->getTrump()->setCoordinates(PersonPosition(TEST_X, TEST_Y));
			for (int _ = 0; _ < 100; ++_) {
				wander(g);
				if (g->getRussianArray()->getRussianAgent(5)->getCoordinates()->getX() != TEST_X || g->getRussianArray()->getRussianAgent(5)->getCoordinates()->getY()!= TEST_Y) {
					taskCheckWrong[7] = true;
				}
			}


			// RA can move if Manhattan distance >= 2
			bool isRaMoved = false;
			g->getTrump()->setCoordinates(PersonPosition(TEST_X + 2, TEST_Y + 1));
			for (int _ = 0; _ < 100; ++_) {
				wander(g);
				if (g->getRussianArray()->getRussianAgent(5)->getCoordinates()->getX() != TEST_X || g->getRussianArray()->getRussianAgent(5)->getCoordinates()->getY() != TEST_Y) {
					isRaMoved = true;
				}
			}

			if (!isRaMoved) {
				taskCheckWrong[7] = true;
			}
			cleanMemory(g);
		}

		cout << "Check Task 8" << endl;
		// Task 9 check
		{
			PersonPosition a = PersonPosition(20, 11), b = PersonPosition(20, 11);
			if (calculateManhattanDistance(&a, &b) != 0) {
				taskCheckWrong[8] = true;
			}
			b.setX(21); b.setY(14);
			if (calculateManhattanDistance(&a, &b) != 4) {
				taskCheckWrong[8] = true;
			}
			b.setX(17); b.setY(16);
			if (calculateManhattanDistance(&a, &b) != 8) {
				taskCheckWrong[8] = true;
			}
			b.setX(50); b.setY(0);
			if (calculateManhattanDistance(&a, &b) != 41) {
				taskCheckWrong[8] = true;
			}
			b.setX(1); b.setY(1);
			if (calculateManhattanDistance(&a, &b) != 29) {
				taskCheckWrong[8] = true;
			}
		}
		cout << "Check Task 9" << endl;

		// Task 10 check
		{
			GameResult result;
			const int w = rand() % 10 + 10, h = rand() % 10 + 10;

			initializeGame(g, w, h, 4);
			PersonPosition RA = *g->getRussianArray()->getRussianAgent(2)->getCoordinates();
			g->getTrump()->setCoordinates(PersonPosition(RA.getX(), RA.getY()));

			result = gameCheck(g);
			if (g->getTouchWithRussianAgentsCount() != 1 || result != GameContinue) {
				taskCheckWrong[9] = true;
			}
			result = gameCheck(g);
			if (g->getTouchWithRussianAgentsCount() != 2 || result != GameContinue) {
				taskCheckWrong[9] = true;
			}
			// Trump moves away
			g->getTrump()->setCoordinates(PersonPosition(RA.getX() - 1, g->getTrump()->getCoordinates()->getY()));
			result = gameCheck(g);
			if (g->getTouchWithRussianAgentsCount() != 0 || result != GameContinue) {
				taskCheckWrong[9] = true;
			}

			// Contact again
			g->getTrump()->setCoordinates(PersonPosition(RA.getX(), g->getTrump()->getCoordinates()->getY()));
			result = gameCheck(g);
			if (g->getTouchWithRussianAgentsCount() != 1 || result != GameContinue) {
				taskCheckWrong[9] = true;
			}
			result = gameCheck(g);
			if (g->getTouchWithRussianAgentsCount() != 2 || result != GameContinue) {
				taskCheckWrong[9] = true;
			}
			// Game over
			g->getFBIArray()->getFBIAgent(3)->setCoordinates(PersonPosition(RA.getX(), RA.getY()));

			result = gameCheck(g);
			if (result != GameOver) {
				taskCheckWrong[9] = true;
			}
			cleanMemory(g);

			initializeGame(g, w, h, 6);
			RA = *g->getRussianArray()->getRussianAgent(4)->getCoordinates();
			g->getTrump()->setCoordinates(PersonPosition(RA.getX(), RA.getY()));

			for (int i = 1; i < TOUCH_COUNT_FOR_WINNING; ++i) {
				result = gameCheck(g);
				if (g->getTouchWithRussianAgentsCount() != i || result != GameContinue) {
					taskCheckWrong[9] = true;
				}
			}
			// Game win
			result = gameCheck(g);
			if (result != GameStageClear) {
				taskCheckWrong[9] = true;
			}
			cleanMemory(g);

		}
		cout << "Check Task 10" << endl;

		// Task 11 check
		initializeGame(g, 5, 8, 4);
		cleanMemory(g);
		levelUp(g);
		if (g->getLevel() != 5) {
			taskCheckWrong[10] = true;
		}
		cleanMemory(g);
		cout << "Check Task 11" << endl;


		//Check double Agent
		initializeGame(g, 5, 5, 3);
		g->getRussianArray()->getRussianAgent(1)->setCoordinates(*g->getFBIArray()->getFBIAgent(2)->getCoordinates());
		if (gameCheck(g) == GameOver)
			cout << "Error! This only turns to double agent" << endl;
		g->getTrump()->setCoordinates(*g->getFBIArray()->getFBIAgent(2)->getCoordinates());
		if (gameCheck(g) != GameOver)
			cout << "FBI and a double agent is meeting trump, should gameover" << endl;
		g->getFBIArray()->getFBIAgent(2)->setCoordinates(*g->getFBIArray()->getFBIAgent(1)->getCoordinates());
		if (gameCheck(g) != GameOver)
			cout << "A double agent is meeting trump, should gameover" << endl;
		g->getRussianArray()->getRussianAgent(2)->setCoordinates(*g->getFBIArray()->getFBIAgent(2)->getCoordinates());  //two FBI here, should not turn double agent
		g->getFBIArray()->getFBIAgent(2)->setCoordinates(*g->getMediaArray()->getMediaReporter(0)->getCoordinates());
		g->getFBIArray()->getFBIAgent(1)->setCoordinates(*g->getMediaArray()->getMediaReporter(0)->getCoordinates());
		g->getTrump()->setCoordinates(*g->getRussianArray()->getRussianAgent(2)->getCoordinates()); //not turning double agent.
		if (gameCheck(g) == GameOver)
			cout << "Two FBI meeting one russianAgent, this will not turn him into double agent" << endl;

		cleanMemory(g);

		cout << "Check Double Agent Feature" << endl;
	}

	// Output warning
	for (int i = 0; i < 11; ++i) {
		if (taskCheckWrong[i]) {
			cout << "Warning: Task " << (i+1) << " is incomplete or incorrect" << endl;
		}
	}

	if (taskCheckWrong[0]) {
		cout << "Warning: Task 3 onward can be checked when task 1 is completed" << endl;
	}

	cout << endl << endl;

	delete g;
}

/** DO NOT MODIFY THE MAIN PROGRAM **/
int main() {
	srand(time(NULL));
	rand();
	cout << "Begin lab10ProgramCheck()" << endl;
	lab10ProgramCheck();
	cout << "Finish lab10ProgramCheck()" << endl;
	Game* game = new Game();

	int width, height;
	char input = '\0';

	height = 5;
	width = 5;
	float difficulty = game->getFBIHidingProbability();
	do {
		cout << "Input the difficulty (0.0 - 1.0): ";
		cin >>difficulty;
	} while (difficulty < 0.0 || difficulty > 1.0);

	do {
		cout << "Input the dimension of the game board (width and height): ";
		cin >> width >> height;
		if (!initializeGame(game, width, height))
			cleanMemory(game);
		else
			break;
	} while(true);

	game->setFBIHidingProbability(difficulty);

	GameResult gameResult = GameContinue;

	while (input != 'q' && gameResult == GameContinue) {
		gameResult = gameCheck(game);
		cout << printGameboard(game);
		if (gameResult == GameStageClear) {
			cout << "Great! Information exchange completed without being caught!!" << endl;
			if (game->getLevel() < LEVEL_TO_WIN) {
				cout << "Prepare to clean memory, calling cleanMemory.. input any character to proceed... " << endl;
				cin >> input;
				cleanMemory(game);
				levelUp(game);
				cout << "LEVEL UP! Input any character to proceed... " << endl;
				cin >> input;
				gameResult = GameContinue;
			}
			continue;
		} else if (gameResult == GameOver) {
			continue;
		}
		// Ask for the next move
		cout << "What is your move (w/s/a/d, stay otherwise)? ";
		cin >> input;
		trumpMove(game, input);
		wander(game);
		cout << endl;
	};

	// Ending messages
	if (gameResult == GameStageClear) {
		cout << "CONGRATULATIONS PRESIDENT TRUMP! America is ready to be made great again!" << endl;
	} else if (gameResult == GameOver) {
		cout << "GAME OVER -  Hillary wins and your future is very uncertain.." << endl;
	}
	cout << "Prepare to clean memory, press any key to proceed" << endl;
	cin >> input;

	cleanMemory(game);
	delete game;
	return 0;
}





