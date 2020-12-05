/*
 * StaticMembers.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: pravinkumar
 */

#include "StaticMembers.h"

int StaticMembers::objCount;

StaticMembers::StaticMembers() {
	objCount++;
}
StaticMembers::~StaticMembers() {
	std::cout << "~StaticMembers" << std::endl;
}

void StaticMembers::Run(void) {
	std::cout << "Just Running" << std::endl;
}

void StaticMembers::PrintObjCount() {
	std::cout << "0bj count " << objCount << std::endl;
}
