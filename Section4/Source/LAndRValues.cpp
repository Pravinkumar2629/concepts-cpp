/*
 * LAndRValues.cpp
 *
 *  Created on: Oct 27, 2020
 *      Author: pravinkumar
 */



#include "LAndRValues.h"

LAndRValues::LAndRValues() :
		LAndRValues(0, 0) {
	std::cout << "LAndRValues()" << std::endl;
}
LAndRValues::LAndRValues(int x) :
		LAndRValues(x, 0) {
	std::cout << "LAndRValues(int)" << std::endl;
}
LAndRValues::LAndRValues(int x, int y) {
	m_intX = x;
	m_intY = y;
	std::cout << "LAndRValues(int,int)" << std::endl;
}
LAndRValues::~LAndRValues() {
	std::cout << "~LAndRValues()" << std::endl;
}

//returns R value
int Add(int a, int b) {
	return a + b;
}
//return L value
int& Modify(int &a) {
	a -= 2;
	return a;
}

void Print(int &x) {
	std::cout << "Print(int &) " << x << std::endl;
}
void Print(const int &x) {
	std::cout << "Print(const int &) " << x << std::endl;
}
void Print(int &&x) {
	std::cout << "Print(int &&) " << x << std::endl;
}


void Page2() {
	int &&r1 = 10;
	int &&r2 = Add(10, 2); //r - value bounds to a temporary returned by Add function - (return by value) - value is temporary;
	int x = 0;
	//int &&r3 = x; // Error cannot bind l -value to r-value;
	int &lValue = x; // l-value reference always binds to l values;
	const int &&r4 = 4; // this would work;

	int z = r1 + r2 + r4 + lValue;
	std::cout << " z value " << z << std::endl;

	Print(x);
	const int y = 10;
	Print(y);
	Print(3);

}


void LAndRValues::Run() {

	//r - values are temporary

	//varibles are L values -like x & y
	// values are R values - like 0 and 10;
	int x = 0;
	int y = 10;

	int z = 12;

	// r value won't persist after processing
	z = (x * y) + z;

	//below returns r values
	++x = 10;

	int add = Add(x, y);
	std::cout << "Add value " << add << std::endl;

	Modify(add) ++;
	//After modifying  (ie) add - 2 ++ ; add is 20 ; then 20 -2 ; then 18++;

	std
	::cout << "After modifying " << add << std::endl;

	Modify(add) = 5;

	std::cout << "After assiging to the modified value " << add << std::endl;
	Page2();
}




























