/*
 * Todo.h
 *
 *  Created on: Nov 27, 2020
 *      Author: pravinkumar
 */

#ifndef TODO_H_
#define TODO_H_
#include <iostream>
class Todo {
public:
	Todo();
	virtual ~Todo();

	virtual void Run() = 0;
};

#endif /* TODO_H_ */
