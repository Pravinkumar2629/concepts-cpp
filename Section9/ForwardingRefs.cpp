/*
 * ForwardingRefs.cpp
 *
 *  Created on: Nov 27, 2020
 *      Author: pravinkumar
 */

#include "ForwardingRefs.h"
#include "Integer.h"
class Employee {
	Integer m_Integer;
	std::string name;
public:
	template <typename T1,typename T2>
	Employee(T1 &&name, T2 &&id) :
			m_Integer(std::forward<T2>(id)), name(std::forward<T1>(name))
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

ForwardingRefs::ForwardingRefs() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ForwardingRefs::~ForwardingRefs() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void ForwardingRefs::Run() {
	int value = 100;
	Employee e { "Pravin", 200 };
	std::string s = "Keerthiga";
	Employee e1 { s, value };
}
