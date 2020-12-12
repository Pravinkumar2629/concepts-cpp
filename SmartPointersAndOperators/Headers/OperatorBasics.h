/*
 * OperatorBasics.h
 *
 *  Created on: Oct 28, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_OPERATORBASICS_H_
#define HEADERS_OPERATORBASICS_H_
#include "callbase.h"

class OperatorBasics: public Todo {
private:
	int m_iVar;
public:
	OperatorBasics();
	OperatorBasics(int value);
	~OperatorBasics();

	void Run();

};



#endif /* HEADERS_OPERATORBASICS_H_ */
