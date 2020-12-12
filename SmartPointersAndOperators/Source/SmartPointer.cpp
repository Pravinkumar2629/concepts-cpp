/*
 * SmartPointer.cpp
 *
 *  Created on: Nov 13, 2020
 *      Author: pravinkumar
 */

#include "SmartPointer.h"

SmartIntPointer::SmartIntPointer() :
		SmartIntPointer(new Integer(0))
{
	std::cout << "SmartIntPointer::SmartIntPointer()" << std::endl;
}
SmartIntPointer::SmartIntPointer(int value) :
		SmartIntPointer(new Integer(value)) {
	std::cout << "SmartIntPointer::SmartIntPointer(int value)" << std::endl;
}
SmartIntPointer::SmartIntPointer(Integer *ob) :
		m_ptr(ob) {
	std::cout << "SmartIntPointer::SmartIntPointer(Integer *ob)" << std::endl;

}

SmartIntPointer::~SmartIntPointer() {
	delete m_ptr;
	std::cout << "~SmartIntPointer()" << std::endl;
}

Integer& SmartIntPointer::operator *() {
	return *m_ptr;
}
Integer* SmartIntPointer::operator ->() {
	return m_ptr;
}
