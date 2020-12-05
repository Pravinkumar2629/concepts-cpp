/*
 * StaticMembers.h
 *
 *  Created on: Oct 26, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_STATICMEMBERS_H_
#define HEADERS_STATICMEMBERS_H_

#include "callbase.h"

class StaticMembers: public Todo {
private:
	int x { 0 };
	static int objCount;
public:
	StaticMembers();
	void Run();
	static void PrintObjCount();
	~StaticMembers();
};

#endif /* HEADERS_STATICMEMBERS_H_ */
