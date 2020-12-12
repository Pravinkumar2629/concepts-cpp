/*
 * callbase.h
 *
 *  Created on: Oct 24, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_CALLBASE_H_
#define HEADERS_CALLBASE_H_

#include <iostream>

typedef void (*fpCallback)(int, int);

struct FuncRegistry {
	char key[64];
	fpCallback func;
};

#endif /* HEADERS_CALLBASE_H_ */
