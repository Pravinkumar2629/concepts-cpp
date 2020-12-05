/*
 * VariadicTemplates.h
 *
 *  Created on: Nov 28, 2020
 *      Author: pravinkumar
 */

#ifndef VARIADICTEMPLATES_H_
#define VARIADICTEMPLATES_H_
#include "Todo.h"

class VariadicTemplates: public Todo {
public:
	VariadicTemplates();
	virtual ~VariadicTemplates();
	void Run() override;
};

#endif /* VARIADICTEMPLATES_H_ */
