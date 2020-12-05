/*
 * Pointers.cpp
 *
 *  Created on: Oct 24, 2020
 *      Author: pravinkumar
 */

#include "Pointers.h"

typedef void (*fpRunMe)(int, int);
namespace runme {
	void RunMe(int x, int y) {
		std::cout << "i am from RunMe" << std::endl;
	}
	void RunMe2(int x1, int y1) {
		std::cout << "i am from RunMe 2" << std::endl;
	}
	void RunMe3(int x2, int y2) {
		std::cout << "i am from RunMe 3" << std::endl;
	}
	namespace runner {
		void Run(int x, int y, fpRunMe fp) {
			fp(x, y);
		}
	}
}
// namespace basics;
namespace basics {
	void basic1() {

	}
	void basic2() {

	}
	void basic3() {

	}
}
/* this would also work*/

//void Run(int x, int y, void (*fp)(int, int)) {
//	fp(x, y);
//}

//void (*fp)(int, int, void (*)(int, int));
// Direct usage of fp is possible and fp can be assigned with a function reference;
typedef void (*fp)(int, int, void (*)(int, int));

void FunctionPointers() {
	int x = 1;
	int y = 2;
	using namespace runme::runner;
	fp fp1 = &Run; // & is optional
	fp1(x, y, runme::RunMe);
	fp1(x, y, runme::RunMe2);
	fp1(x, y, runme::RunMe3);
}

void BasicsOfPointers() {
	auto x { 101 };
	int y = 10;
	auto *ptr2 = &x;
	const int *const ptr = &x;
	//*ptr = 10; // Err  - Assignment of read Only location;
	//ptr = &y;  // Err - Assignment of read only pointer;
	//*ptr = 120; // Err  - Assignment of read Only location;
	std::cout << "Changing pointers x " << x << std::endl;
	std::cout << "Changing pointers y " << y << std::endl;

}

void Pointers::Run() {
	BasicsOfPointers();
	FunctionPointers();
}

