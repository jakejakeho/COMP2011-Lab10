/*
 * MediaArray.h
 *
 *  Created on: 30 Apr, 2017
 *      Author: Sathish
 */

#ifndef MEDIAARRAY_H_
#define MEDIAARRAY_H_

#include "Person.h"

typedef Person MediaReporter;

class MediaArray{

private:

	int numMedia;          // The current number of Media agents

	MediaReporter *fp;        // Pointer to dynamic array of Media agents

public:

	MediaArray(int n); // Constructor

	~MediaArray();     // Destructor

	int getnumMedia();     // Return the current number of Media Reporters

	void setnumMedia(int n); // Set the current number of Media Reporters

	void initialize(); // Initialize all Media Reporters to (NULL_POSITION, NULL_POSITION)

	MediaReporter* getMediaReporter(int n); // Return MediaReporter at location n (0 <= n < numMedia)


};





#endif /* MEDIAARRAY_H_ */
