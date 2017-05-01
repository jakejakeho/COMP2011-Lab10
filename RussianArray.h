/*
 * RussianArray.h
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */

#ifndef RUSSIANARRAY_H_
#define RUSSIANARRAY_H_

#include "Person.h"

typedef Person RussianAgent;

class RussianArray{

private:

	int numRussian;          // the current number of Russian agents

	RussianAgent *fp;        // pointer to dynamic array of Russian agents

public:

	RussianArray(int n); 		// Constructor

	~RussianArray();         // Destructor

	int getnumRussian();     // Return the current number of Russian agents

	void setnumRussian(int n);  // Set current number of Russian agents

	void initialize();		// Initialize all Russian Agents to (NULL_POSITION, NULL_POSITION)

	RussianAgent* getRussianAgent(int n);  // Return Russian agent at position n (0 <= n < numRussian)

};



#endif /* RUSSIANARRAY_H_ */
