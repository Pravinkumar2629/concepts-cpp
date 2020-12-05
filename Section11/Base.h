/*
 * Base.h
 *
 *  Created on: Nov 30, 2020
 *      Author: pravinkumar
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>

class Base {
public:
	virtual ~Base();
	virtual void Run() = 0;
};

#endif /* BASE_H_ */
