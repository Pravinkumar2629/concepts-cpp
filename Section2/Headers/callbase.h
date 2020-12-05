/*
 * callbase.h
 *
 *  Created on: Oct 23, 2020
 *      Author: pravinkumar
 */

#ifndef CALLBASE_H_
#define CALLBASE_H_
#include <iostream>

class Todo {
public:

	virtual void Run() = 0;
	virtual ~Todo() {
	}
	;
};

#endif /* CALLBASE_H_ */
