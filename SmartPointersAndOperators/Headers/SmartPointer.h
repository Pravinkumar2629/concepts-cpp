/*
 * SmartPointer.h
 *
 *  Created on: Nov 13, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_SMARTPOINTER_H_
#define HEADERS_SMARTPOINTER_H_


#include "Integer.h"

class SmartIntPointer {
private:
	Integer *m_ptr;
public:

	SmartIntPointer();
	SmartIntPointer(int);
	SmartIntPointer(Integer*);
	~SmartIntPointer();
	Integer* operator ->();
	Integer& operator *();
};


#endif /* HEADERS_SMARTPOINTER_H_ */
