/*
 * Literals.h
 *
 *  Created on: Nov 22, 2020
 *      Author: pravinkumar
 */

#ifndef LITERALS_H_
#define LITERALS_H_

#include "Todo.h"

class Literals: public Todo {
public:
	Literals();
	virtual ~Literals();
	void Run() const override;
};

#endif /* LITERALS_H_ */
