/*
 * LAndRValues.h
 *
 *  Created on: Oct 27, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_LANDRVALUES_H_
#define HEADERS_LANDRVALUES_H_
#include "callbase.h"

class LAndRValues: public Todo {
private:
	int m_intX;
	int m_intY;
public:
	LAndRValues();
	LAndRValues(int, int);
	LAndRValues(int);
	~LAndRValues();

	void Run(); //override



};



#endif /* HEADERS_LANDRVALUES_H_ */
