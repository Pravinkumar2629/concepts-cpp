/*
 * Enums.h
 *
 *  Created on: Nov 22, 2020
 *      Author: pravinkumar
 */

#ifndef ENUMS_H_
#define ENUMS_H_

#include "Todo.h"

class Enums: public Todo {
public:
	Enums();
	void Run() const override;
	~Enums();
};

#endif /* ENUMS_H_ */
