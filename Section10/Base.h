/*
 * Base.h
 *
 *  Created on: Nov 29, 2020
 *      Author: pravinkumar
 */

#ifndef BASE_H_
#define BASE_H_
#include <iostream>
#include <string>
#include <iterator>

inline void Write(std::string s) {
	std::cout << s << std::endl;
}

class Base {
public:
	Base();
	virtual ~Base();
	virtual void Run() = 0;
};

#endif /* BASE_H_ */
