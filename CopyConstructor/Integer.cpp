/*
 * Integer.cpp
 *
 *  Created on: Oct 8, 2020
 *      Author: pravinkumar
 */

#include "Integer.h"
#include <iostream>

Integer::Integer() {
	m_intVar = new int(0);
	std::cout << "Integer() " << std::endl;
}

Integer::Integer(int value) {
	m_intVar = new int(value);
	std::cout << "Integer(value) " << std::endl;
}

Integer::Integer(const Integer &iOb) {
	// the reference is used to stop the loop of copy constructors
	//Becuase if we use value type here that will cause the creation of another copy constructor
	// and goes in a loop
	std::cout << "copy constructor invoked" << std::endl;
	m_intVar = new int(iOb.GetValue());
}
//Integer& operator = (const Integer &iOb){
//	return new Integer(iOb.GetValue());
//}


void Integer::SetValue(int value) {
	*m_intVar = value;
}

int Integer::GetValue()const {
	return *m_intVar;
}

Integer::~Integer() {
	delete m_intVar;
	std::cout << "~Integer" << std::endl;
}
