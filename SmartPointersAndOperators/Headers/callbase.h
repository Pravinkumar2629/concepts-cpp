/*
 * callbase.h
 *
 *  Created on: Oct 28, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_CALLBASE_H_
#define HEADERS_CALLBASE_H_

#include <iostream>

class Todo {
public:
	virtual void Run() = 0;
	virtual ~Todo() {
	}
	;
};

#endif /* HEADERS_CALLBASE_H_ */
