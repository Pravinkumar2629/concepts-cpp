/*
 * ClassTemplates.hpp
 *
 *  Created on: Nov 28, 2020
 *      Author: pravinkumar
 */

#ifndef CLASSTEMPLATES_HPP_
#define CLASSTEMPLATES_HPP_

#include "Todo.h"

class ClassTemplates: public Todo {
public:
	ClassTemplates();
	virtual ~ClassTemplates();

	void Run() override;
};

#endif /* CLASSTEMPLATES_HPP_ */
