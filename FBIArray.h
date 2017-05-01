/*
 * FBIArray.h
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */

#ifndef FBIARRAY_H_
#define FBIARRAY_H_

#include "Person.h"

typedef Person FBIAgent;

class FBIArray
{
private:

	int numFBI;          // The current number of FBI agents

	FBIAgent *fp;        // Pointer to dynamic array of FBI agents

public:

	FBIArray(int n); // Constructor

	~FBIArray();         // Destructor

	int getnumFBI();     // Return the current number of FBI agents

	void setnumFBI(int n); // Set number of FBI Agents

	void initialize(); // Initialize all agents to (NULL POSITION, NULL POSITION)

	FBIAgent* getFBIAgent(int n); // Get pointer to n-th FBI agent (0 <= n < numFBI)

};





#endif /* FBIARRAY_H_ */
