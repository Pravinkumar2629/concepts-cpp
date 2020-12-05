/*
 * Strings.h
 *
 *  Created on: Nov 22, 2020
 *      Author: pravinkumar
 */

#ifndef STRINGS_H_
#define STRINGS_H_

#include "Todo.h"

class Strings: public Todo {
public:
	Strings();
	void Run() const override;
	~Strings();
};

#endif /* STRINGS_H_ */
