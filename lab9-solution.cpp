/*
 * lab9-solution.cpp
 *
 *  Created on: 25 Apr, 2017
 *      Author: Kenneth and Sathish
 */

#include "lab10.h"
#include <iostream>
#include <time.h>       /* time */

/**
 * @example unsignedIntToString(2011) return "2011"
 */
string unsignedIntToString(unsigned int i) {
	string str = "";
	if (i == 0) {
		return "0";
	}
	while (i > 0) {
		str = (char)((i % 10) + '0') + str;
		i /= 10;
	}
	return str;
}


// TODO: (Task 1) Complete the initializeGame function
/**
 * @brief Initialize the game with level (default 1)
 * with corresponding game parameters (width, height, level, etc.),
 * position of trump, russiaAgents, media and FBI
 */
bool initializeGame(Game* game, int width, int height, int level) {
	/** Make sure that the inputted width and height is sufficient for all person
	 * I.e., The game board at Level N must have enough space for
	 * Trump, N Russian Agents, N Media Reports and N FBI agents
	 * Reminder: What is width and height are both negative numbers
	 * If the space is not sufficient, return false.
	 */
	//	if (width * height < 3 * level + 1 || width < -1) {
	//		return false;
	//	}
	//
	//	// Initialize the game parameters (width, height, level, moveCount and touchWithRussianAgentsCount)
	//	game->width = width;
	//	game->height = height;
	//	game->level = level;
	//	game->moveCount = 0;
	//	game->touchWithRussianAgentsCount = 0;
	//	game->FBIHidingProbability = 0;
	//
	//
	//	// Initialize trump at the bottom-left corner
	//	game->trump.x = 0;
	//	game->trump.y = game->height - 1;
	//
	//
	//
	//	game->russianAgents = new PersonPosition*[level];
	//	game->FBI = new PersonPosition[level];
	//	game->media = new PersonPosition[level];
	//
	//	// Initialize ALL russianAgents, media and FBI to be of null position
	//	for (int i = 0; i < game->level; ++i) {
	//		game->russianAgents[i] = new PersonPosition;
	//		game->russianAgents[i]->x = NULL_POSITION;
	//		game->russianAgents[i]->y = NULL_POSITION;
	//		game->media[i].x = NULL_POSITION;
	//		game->media[i].y = NULL_POSITION;
	//		game->FBI[i].x = NULL_POSITION;
	//		game->FBI[i].y = NULL_POSITION;
	//	}
	//
	//	// Assign random position by calling generatePositionWithoutPerson(...)
	//	for (int i = 0; i < game->level; ++i) {
	//		*game->russianAgents[i] = generatePositionWithoutPerson(game);
	//		game->media[i] = generatePositionWithoutPerson(game);
	//		game->FBI[i] =  generatePositionWithoutPerson(game);
	//	}
	//
	//	for (int i = 0; i < MAX_COUNT; i++)
	//	    game->doubleAgents[i] = NULL;
	//
	//	return true;
}




// COMPLETED: (Task 2) Complete the isSamePosition function
/**
 * @brief Check whether the two given position are the same
 */
bool isSamePosition(const PersonPosition* A, const PersonPosition* B) {
	return A->getX() == B->getX() && A->getY() == B->getY();
}



// TODO: (Task 3) Complete the generatePositionWithoutPerson function
// (possibly using **recursion**)
PersonPosition generatePositionWithoutPerson(const Game* game) {
	//	// Pick a random position in the valid range
	//	PersonPosition randPosition = {rand() % game->width, rand() % game->height};
	//	bool isEmptyPosition = true;
	//
	//	// Check if randPosition overlap with trump
	//	if (isSamePosition(&randPosition, &game->trump)) {
	//		isEmptyPosition = false;
	//	}
	//
	//	// Check if randPosition overlap with others
	//	for (int i = 0; i < game->level; ++i) {
	//		if (isSamePosition(&randPosition, game->russianAgents[i])
	//		|| isSamePosition(&randPosition, &game->media[i])
	//		|| isSamePosition(&randPosition, &game->FBI[i])
	//		) {
	//			isEmptyPosition = false;
	//		}
	//	}
	//
	//	if (isEmptyPosition) {
	//		return randPosition;
	//	} else {
	//		// Recursive call to generate a random position again
	//		return generatePositionWithoutPerson(game);
	//	}
}



/**
 * @brief Output a string of a progress bar in "|||--" format
 */
string progressBar(int count, int total) {
	string result = "";
	for (int i = 0; i < total; i++)
		if (i <= count) result += "|"; else result += "-";
	return result;
	if (count > 0 && total > 0) {
		return "|" + progressBar(count - 1, total - 1);
	} else if (total > 0) {
		return "-" + progressBar(count - 1, total - 1);
	} else {
		return "";
	}
}

// TODO: (Task 4) Complete the printGameboard function
// MILESTONE 1: By finishing task 1-4 successfully,
// the program can initialize the game and print the game board details
// You may want to use unsignedIntToString(...)
/**
 * @brief Print the game board in detail
 */

string printGameboard(const Game* game) {
	//	string output = "";
	//	// Print the level
	//	output += "Level " + unsignedIntToString(game->level) + "\t\t";
	//	// Print the number of moves
	//	output += "Move: " + unsignedIntToString(game->moveCount) + "\t\t";
	//	// Print the progress bar of the move count that trump made contact with a Russian agent
	//	output += progressBar(game->touchWithRussianAgentsCount, TOUCH_COUNT_FOR_WINNING) + "\n";
	//	bool isFBIVisible[MAX_COUNT];
	//
	//	for (int i = 0; i < game->level; i++)
	//	    isFBIVisible[i] = (rand() >= game->FBIHidingProbability * RAND_MAX);
	//	for (int i = 0; i < game->height; ++i) {
	//		for (int j = 0; j < game->width; ++j) {
	//			// Output '.' if the position is empty
	//			string outputChar = ".";
	//			bool trumpHere = false;
	//		//	PersonPosition currentPos = {j, i};
	//			PersonPosition currentPos;
	//			currentPos.x = j; currentPos.y = i;
	//
	//			// If trump is at currentPos, the output character becomes 'T'
	//			// Set trumpHere to be true
	//			if (isSamePosition(&game->trump, &currentPos)) {
	//				trumpHere = true;
	//				outputChar = "T";
	//			}
	//			// Check all other people if they are at currentPos
	//			// Change the output character if so
	//
	//			// Precedence: 'T' < 'R' < 'M' < 'F'
	//			// E.g., if 'R' and 'F' are in the same position, show 'F' only
	//			for (int k = 0; k < game->level; ++k) {
	//				if (isSamePosition(&game->FBI[k], &currentPos) && isFBIVisible[k]) {
	//					outputChar = "F";
	//				} else if (isSamePosition(&game->media[k], &currentPos) && outputChar != "F") {
	//					outputChar = "M";
	//				} else if (isSamePosition(game->russianAgents[k], &currentPos)
	//					&& outputChar != "M" && outputChar != "F") {
	//					outputChar = "R";
	//				}
	//			}
	//			// The output character is bounded by '*' if trump is here
	//			if (!trumpHere) {
	//				output += " " + outputChar + " ";
	//			} else {
	//				output += "*" + outputChar + "*";
	//			}
	//
	//		}
	//		output += "\n";
	//	}
	//	output += "\n";
	//
	//	return output;
}


// COMPLETED: (Task 5) Complete the personMove function
/**
 * @brief Move a person with a given movement by 1 step
 * If the move is invalid (out of the game board), do not move then
 */
void personMove(Game* game, PersonPosition* pos, Movement move) {
	// Make a variable newPos to try and test if the position is valid first
		PersonPosition newPos = *pos;
		switch (move) {
		case Stay:
			return;
		case Up:
			newPos.setY(newPos.getY() - 1);
			break;
		case Down:
			newPos.setY(newPos.getY() + 1);
			break;
		case Left:
			newPos.setX(newPos.getX() - 1);
			break;
		case Right:
			newPos.setX(newPos.getX() + 1);
			break;
		}

		// Check if the new position is valid or not
		if (newPos.getX() >= 0 && newPos.getX() < game->getWidth() && newPos.getY() >= 0 && newPos.getY() < game->getHeight()) {
			// Valid position
			*pos = newPos;
		}
}



// COMPLETED: (Task 6) Complete the trumpMove function
/**
 * @brief Move trump based on the given input
 * ('w': Up, 's': Down, 'a': Left, 'd': Right, do not move otherwise)
 */
void trumpMove(Game* game, char input) {
	// To lower-case
	if (input >= 'A' && input <= 'Z') {input += 'a' - 'A';}
	// Move trump for each case
	switch (input) {
	case 'w':
		personMove(game, game->getTrump()->getCoordinates(), Up);
		break;
	case 's':
		personMove(game, game->getTrump()->getCoordinates(), Down);
		break;
	case 'a':
		personMove(game, game->getTrump()->getCoordinates(), Left);
		break;
	case 'd':
		personMove(game, game->getTrump()->getCoordinates(), Right);
		break;
	}

	// Increment the game move count
	game->setMoveCount(game->getMoveCount() + 1);
}



// TODO: (Task 7) Complete the wander function
/**
 * @brief The given person wanders (i.e, randomly moves)
 * Randomly choose Up, Down, Left, Right or Stay as the movement
 * and then move the person accordingly
 */
void wander(Game* game, PersonPosition* pos) {
	//	Movement movement = (Movement)(rand() % 5);
	//	personMove(game, pos, movement);
}



// TODO: (Task 8) Complete another wander function
/**
 * @brief ALL people (Russian agents, media reports and FBI) wander except trump
 * If the Manhattan distance between a Russian agent is <= 2, the agent will not move
 */
void wander(Game* game) {
	//	for (int i = 0; i < game->level; ++i) {
	//		if (calculateManhattanDistance(game->russianAgents[i], &game->trump) >= 3) {
	//			wander(game, game->russianAgents[i]);
	//		}
	//		wander(game, &game->media[i]);
	//		wander(game, &game->FBI[i]);
	//	}
}



// TODO: (Task 9) Complete calculateManhattanDistance function
/**
 * @brief Calculate the Manhattan distance between position A and B
 */
int calculateManhattanDistance(const PersonPosition* A, const PersonPosition* B) {
	//	return abs(A->x - B->x) + abs(A->y - B->y);
}



// TODO: (Task 10) Complete the gameCheck function
/**
 * @brief Check the game result
 */
GameResult gameCheck(Game* game) {
	//	bool isTouchWithRussianAgents = false;
	//	bool isTouchWithMediaOrFBI = false;
	//	bool isTouchWithDoubleAgent = false;
	//	// Check if trump touches others
	//	for (int i = 0; i < game->level; ++i) {
	//		if (isSamePosition(&game->trump, game->russianAgents[i])) {
	//			isTouchWithRussianAgents = true;
	//		}
	//		if (isSamePosition(&game->trump, &game->media[i])) {
	//			isTouchWithMediaOrFBI = true;
	//		}
	//		if (isSamePosition(&game->trump, &game->FBI[i])) {
	//			isTouchWithMediaOrFBI = true;
	//		}
	//		if (game->doubleAgents[i] != NULL && isSamePosition(&game->trump, game->doubleAgents[i])) {
	//			isTouchWithDoubleAgent = true;
	//		}
	//	}
	//	// Game over if you meet a double agent.
	//	if (isTouchWithDoubleAgent) {
	//	    return GameOver;
	//	}
	//
	//
	//	// Game over if touch with media or FBI while you are touching with Russian Agents
	//	if (isTouchWithMediaOrFBI && isTouchWithRussianAgents) {
	//		return GameOver;
	//	}
	//
	//	// Check if trump touches Russian Agents (increment or reset it accordingly)
	//	if (isTouchWithRussianAgents) {
	//		game->touchWithRussianAgentsCount++;
	//	} else {
	//		// Reset
	//		game->touchWithRussianAgentsCount = 0;
	//	}
	//
	//	// Stage clear if the touch count reaches TOUCH_COUNT_FOR_WINNING (i.e., 3)
	//	if (game->touchWithRussianAgentsCount >= TOUCH_COUNT_FOR_WINNING) {
	//		return GameStageClear;
	//	}
	//
	//
	//	// check if a FBI is contacting a russian agent alone
	//	for (int i = 0; i < game->level ; i++) {
	//	    PersonPosition p = game->FBI[i];
	//	    PersonPosition* agent = NULL;
	//	    for (int j = 0; j < game->level; j++) {
	//		if (isSamePosition(&p, game->russianAgents[j]))
	//		    agent = game->russianAgents[j];
	//	    }
	//	    if (agent == NULL)
	//		continue;
	//	    //check how many people in this cell
	//	    int people = 0;
	//	    for (int j = 0; j < game->level; j++) {
	//		if (isSamePosition(&p, &game->FBI[j]))
	//		    people++;
	//		if (isSamePosition(&p, &game->media[j]))
	//		    people++;
	//		if (isSamePosition(&p, game->russianAgents[j]))
	//		    people++;
	//		//no need to check trump as he will be caught earlier
	//	    }
	//	    if (people != 2) //they are not alone
	//		continue;
	//	    bool addedBefore = false;
	//	    int c;
	//	    for (c = 0; c < MAX_COUNT && game->doubleAgents[c] != NULL; c++) {
	//		if (game->doubleAgents[c] == agent) {  //added before
	//		    addedBefore = true;
	//		    break;
	//		}
	//	    }
	//	    if (!addedBefore) {
	//		game->doubleAgents[c] = agent;
	//	    }
	//
	//	}
	//
	//	return GameContinue;
}



// COMPLETED: (Task 11) Complete the levelUp function
/**
 * @brief Game level increased by 1
 */
void levelUp(Game* game) {
	// Increase the game level
	game->setLevel(game->getLevel() + 1);
	// Initialize the game again with the new level of the game board size of +1 in both width and height
	initializeGame(game, game->getWidth() + 1, game->getHeight() + 1, game->getLevel());

}

void cleanMemory(Game* game) {
	delete game->getTrump();
	delete game->getFBIArray();
	delete game->getRussianArray();
	delete game->getMediaArray();
}
