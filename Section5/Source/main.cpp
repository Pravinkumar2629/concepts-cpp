/*
 * main.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: pravinkumar
 */

#include "callbase.h"
#include "OperatorBasics.h"
#include "Operators.h"
#include "TypeCast.h"
#include "MemoryMgmt.h"

void Run(Todo *ptr) {

	std::cout << "leaving  main" << std::endl;
	ptr->Run();
	std::cout << "back to  main" << std::endl;
	delete ptr;
	ptr = nullptr;

}

//Going to cover section 6 (memory management) & 7 (c++ goodies) here.

int main() {
	/*
	 *
	 * class has
	 * 1. Operator overloading; operators[ *, +, -, ++, ==, =, >>, << etc;]
	 * 2. Smart poitner basics;
	 * 3. type conversions;
	 *
	 *
	 *
	 *  dot (.) , sizeof, ternary and some casting operators cannot be overloaded;
	 * */
	//Run(new OperatorBasics());
	//Run(new Operators());
	//Run(new Types());
	Run(new MemoryMgmt());
}
