/*
 * CopyElisionAndMove.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: pravinkumar
 */

#include "CopyElisionAndMove.h"

CopyElisionAndMove AddMethodInElision(int a, int b) {
	CopyElisionAndMove temp(a + b);
	return temp;
}

void Print(CopyElisionAndMove ob) {
	std::cout << "Print (CopyElisionAndMove) - " << std::endl;
	std::cout << ob.m_iPtr2 << std::endl;
}

void CopyElisionAndMove::Run(void) {

	std::cout << "\n CopyElisionAndMove::Run Start" << std::endl;

	//if no elision flag enabled you will see another move  constructor call;
	// becuase when there is no elision; the below statement will be compiled as CopyElisionAndMove ob = CopyElisionAndMove(1)
	// so there would be on constructor call and another move constructor call to move the temporary into the ob;
	CopyElisionAndMove ob = 1;


	std::cout << "CopyElisionAndMove::Run After** Creating ob = 1" << std::endl;

	CopyElisionAndMove ob2 = AddMethodInElision(3, 4);
	std::cout << "CopyElisionAndMove::Run After** AddMethodInElision(3, 4);"
			<< std::endl;

	Print(static_cast<CopyElisionAndMove&&>(ob2));
	// above & below are logically same. but the below shows the intention of
	// the programmer clearly. below is preffered;
	Print(std::move(ob2));
	//When yo dont want the state of ob2 after calling Print function;
	// you can move the state using std::move();
	// this helps you in management of memory;
	//instead of copying the state of ob2 to Print function;
	// we're moving, which makes it faster;
	std::cout << "CopyElisionAndMove::Run End \n" << std::endl;
}















CopyElisionAndMove::CopyElisionAndMove() :
		CopyElisionAndMove(0) {
	std::cout << "CopyElisionAndMove::CopyElisionAndMove()" << std::endl;
}

CopyElisionAndMove::CopyElisionAndMove(int value) {
	std::cout << "CopyElisionAndMove::CopyElisionAndMove(int value)"
			<< std::endl;
	m_iPtr = new int(value);
	m_iPtr2 = new int(value);
}
//Copy Constructor
CopyElisionAndMove::CopyElisionAndMove(CopyElisionAndMove &ob) {
	std::cout
			<< "CopyElisionAndMove::CopyElisionAndMove(CopyElisionAndMove &ob)"
			<< std::endl;
	m_iPtr = new int(*ob.m_iPtr);
	m_iPtr2 = new int(*ob.m_iPtr);
}

//Move Constructor
CopyElisionAndMove::CopyElisionAndMove(CopyElisionAndMove &&ob) {
	std::cout
			<< "CopyElisionAndMove::CopyElisionAndMove(CopyElisionAndMove &&ob)"
			<< std::endl;
	m_iPtr = ob.m_iPtr;
	ob.m_iPtr = nullptr;
	m_iPtr2 = ob.m_iPtr2;
	ob.m_iPtr2 = nullptr;
}

CopyElisionAndMove::~CopyElisionAndMove() {
	std::cout << "~CopyElisionAndMove()" << std::endl;
}













