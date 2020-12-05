/*
 * VariadicTemplates.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: pravinkumar
 */

#include "VariadicTemplates.h"
#include "Integer.h"

VariadicTemplates::VariadicTemplates() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;

}

VariadicTemplates::~VariadicTemplates() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}



// ... called elipses;
// Template parameter pack

double Sum() {
	return 0;
}

template<typename T, typename ...Params>
double Sum(T &&a, Params &&...args) {
	int x = sizeof...(args);
	int y = sizeof...(Params);
	return a + Sum(std::forward<Params>(args)...);
}
template <typename T, typename ...Params>
T* CreateObject(Params ...args) {
	return new T(std::forward<Params>(args)...);
}


// c++ 20 not allowing to turn off copy elision;
Integer WhyNotMoving(Integer ob) {
	Integer a { 2 };
	Integer b { 3 };
	b = a;
	std::cout << "copy assignment expected* - value of b " << b << std::endl;
	Integer c(a);
	std::cout << "copy expected* - value of b " << b << std::endl;
	a = Integer(5);
	std::cout << "move expected* - value of a  " << a << std::endl;
	return Integer { 111 };
}
class Employee {
public:
	std::string s { };
	char c { };
	int id { };
	Employee() = default;
	Employee(std::string name, char tag, int id) :
			s(name), c(tag), id(id) {
		std::cout << "Calling Employee" << std::endl;
	}
};

void Create() {
	auto i = CreateObject<int>(1);
	auto s = CreateObject<std::string>("String name ");
	auto s2 = CreateObject<std::string>("");
	auto i2 = CreateObject<Integer>(100);
	auto e = CreateObject<Employee>("Pravin", 'D', 1818);
	std::cout << "End of Create " << std::endl;
}
void VariadicTemplates::Run() {
	int sum = Sum(1, 2.3, 5.4, 1);
	std::cout << "Sum " << sum << std::endl;
	auto sum2 = Sum(100, sum, Integer { 1 });
	std::cout << "Sum2 " << sum2 << std::endl;
	auto ret = WhyNotMoving(Integer { 10 });
	std::cout << "RET " << ret << std::endl;
	Create();
}

