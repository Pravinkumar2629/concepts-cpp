/*
 * Integer.cpp
 *
 *  Created on: Nov 27, 2020
 *      Author: pravinkumar
 */

#include "Integer.h"
#include <iostream>

Integer::Integer() :
		m_IPtr(new int(0)) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
Integer::Integer(int value) :
		m_IPtr(new int(value)) {
	std::cout << __PRETTY_FUNCTION__ << " = " << value << std::endl;
	std::cout << __PRETTY_FUNCTION__ << " OBJ At " << this << std::endl;
}
Integer::Integer(const Integer &other) {
	std::cout << "**COPYING " << std::endl;
	m_IPtr = new int(*other.m_IPtr);
	std::cout << __PRETTY_FUNCTION__ << std::endl;

}
Integer::Integer(Integer &&other) {
	std::cout << "**MOVING OBJ " << std::endl;
	std::cout << "**Ptr before  " << m_IPtr << std::endl;
	std::cout << "**Ptr before OTHER " << other.m_IPtr << std::endl;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	m_IPtr = other.m_IPtr;
	std::cout << "**Ptr after  " << m_IPtr << std::endl;
	other.m_IPtr = nullptr;
	std::cout << "Returing from **Move constructor Integer "  <<std::endl;
}

Integer& Integer::operator =(const Integer &right) {
	std::cout << "**Copy Assignment " << std::endl;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (this != &right) {
		delete m_IPtr;
		m_IPtr = new int(*right.m_IPtr);
	}
	return *this;
}


Integer& Integer::operator =(Integer &&right) {
	std::cout << "**Move Assignment " << std::endl;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	if (this != &right) {
		delete m_IPtr;
		m_IPtr = right.m_IPtr;
		right.m_IPtr = nullptr;
	}
	return *this;
}

int Integer::operator +(const Integer &right) {
	return *m_IPtr + *(right.m_IPtr);
}
int Integer::operator +(int &right) {
	return *m_IPtr + right;
}
std::ostream& operator <<(std::ostream &out, const Integer &ob) {
	out << "Integer value " << *ob.m_IPtr;
	return out;
}


Integer::~Integer() {
	delete m_IPtr;
	m_IPtr = nullptr;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

