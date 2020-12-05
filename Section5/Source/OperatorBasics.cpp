/*
 * OperatorBasics.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: pravinkumar
 */



#include "OperatorBasics.h"
#include "Integer.h"

Integer AddInt(Integer a, Integer b) {
	return a + b;
}

void OperatorBasics::Run() {
	std::cout << "void OperatorBasics::Run() start " << std::endl;
	Integer a(10);
	Integer b(12);
	Integer c = a + b;
	std::cout << "Sum c " << c.GetValue() << std::endl;
	Integer d = c - a;
	std::cout << "Sub d " << d.GetValue() << std::endl;
	std::cout << " ++d " << (++d).GetValue() << std::endl;
	std::cout << " d ++ " << (d++).GetValue() << std::endl;
	std::cout << c;
	if (d == c) {
		std::cout << " d & c are equal  " << std::endl;
	} else {
		std::cout << " d & c are NOT equal  " << std::endl;
	}

	Integer e = AddInt(a, b);


	std::cout << "void OperatorBasics::Run() end " << std::endl;
}

OperatorBasics::OperatorBasics() :
		OperatorBasics(0) {
	std::cout << "OperatorBasics::OperatorBasics()" << std::endl;
}
OperatorBasics::OperatorBasics(int value) {
	std::cout << "OperatorBasics::OperatorBasics(int)" << std::endl;
	m_iVar = value;
}
OperatorBasics::~OperatorBasics() {
	std::cout << "OperatorBasics::~OperatorBasics()" << std::endl;
}
