/*
 * Templates.h
 *
 *  Created on: Nov 27, 2020
 *      Author: pravinkumar
 */

#ifndef TEMPLATES_H_
#define TEMPLATES_H_
#include "Todo.h"

class Templates: public Todo {
public:
	Templates();
	virtual ~Templates();
	void Run() override;
};

#endif /* TEMPLATES_H_ */
