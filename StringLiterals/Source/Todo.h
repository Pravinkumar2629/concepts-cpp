/*
 * Todo.h
 *
 *  Created on: Nov 22, 2020
 *      Author: pravinkumar
 */

#ifndef TODO_H_
#define TODO_H_
#include <iostream>

class Todo {
public:
	Todo();
	virtual void Run() const = 0;
	virtual ~Todo();
};

#endif /* TODO_H_ */
