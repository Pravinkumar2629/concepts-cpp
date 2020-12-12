/*
 * Integer.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: pravinkumar
 */

#include "Integer.h"

std::istream& operator >>(std::istream &in, Integer &ob) {
	int x;
	in >> x;
	ob.SetValue(x);
	return in;
}

//this funciton is defined as a friend of Integer class;
std::ostream& operator <<(std::ostream &out, const Integer &ob) {
	out << ob.GetValue() << " friend " << ob.privateMember << std::endl;
	return out;
}


Integer Integer::operator +(const Integer &ob) const {
	int val = *m_iVar + *(ob.m_iVar);
	return Integer(val);
}
Integer operator -(const Integer &a, const Integer &b) {
	int val = (a.GetValue() + b.GetValue());
	return val;
}

Integer& Integer::operator ++() {
	++(*m_iVar);
	return *this;
}
Integer Integer::operator ++(int) {
	Integer temp(*this);
	(*m_iVar)++;
	return temp;
}

Integer::operator int() {
	return *m_iVar;
}

bool Integer::operator ==(const Integer &b) const {
	return *m_iVar == *(b.m_iVar);
}

Integer::Integer() :
		Integer(0) {
	std::cout << "Integer::Integer() : Integer(0) **Delegated" << std::endl;
}
Integer::Integer(int value) {
	m_iVar = new int(value);
	std::cout << "Integer::Integer(int)" << std::endl;
}

//Copy constructor
Integer::Integer(const Integer &ob) {
	std::cout << "Integer::Integer(const Integer &) **Copying" << std::endl;
	m_iVar = ob.m_iVar;
}
//Move constructor
Integer::Integer(Integer &&rOb) {
	std::cout << "Integer::Integer(const Integer &&) **Moving" << std::endl;
	m_iVar = rOb.m_iVar;
	rOb.m_iVar = nullptr;
}

//Copy assignment
Integer& Integer::operator =(const Integer &ob) {
	std::cout
			<< "Integer& Integer::operator =(const Integer &ob) ** Copy assignment"
			<< std::endl;
	if (this != &ob) {
		delete m_iVar;
		m_iVar = new int(*(ob.m_iVar));
	}
	return *this;
}
//Move assignment
Integer& Integer::operator =(Integer &&ob) {
	std::cout << "Integer& Integer::operator =(Integer &&ob)** Move assignment"
			<< std::endl;
	if (this != &ob) {
		delete m_iVar;
		m_iVar = ob.m_iVar;
	}
	return *this;
}

Integer::~Integer() {
//delete m_iVar;
	m_iVar = nullptr;
	std::cout << "Integer::~Integer() " << std::endl;
}

int Integer::GetValue() const {
	return *m_iVar;
}

void Integer::SetValue(int val) {
*m_iVar = val;
}
