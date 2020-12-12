/*
 * Constructors.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: pravinkumar
 */

#include "Constructors.h"

Constructors::Constructors(int value) :
		Constructors(value, '\0') {
	std::cout << "Constructors(int) " << std::endl;

}
Constructors::Constructors(int value, char c) :
		Constructors(value, c, 0.0) {
	std::cout << "Constructors(int value, char c)" << std::endl;
}
Constructors::Constructors(int value, char c, float f) :
		Constructors(value, c, f, 0.0) {
	std::cout << "Constructors(int value, char c, float f)" << std::endl;
}
Constructors::Constructors(int value, char c, float f, double d) {
	std::cout << " \n Constructors(int value, char c, float f , double d)"
			<< std::endl;
	m_intPtr = new int(value);
	m_cPtr = new char(c);
	m_fPtr = new float(f);
	m_dPtr = new double(d);
}

Constructors::Constructors() :
		Constructors(0) {
	std::cout << "Constructors() " << std::endl;
}
Constructors::~Constructors() {
	std::cout << "~ Releasing resource ~Constructors() " << std::endl;
	delete m_intPtr;
	delete m_cPtr;
	delete m_fPtr;
	delete m_dPtr;
}

Constructors::Constructors(const Constructors &ob) {
	std::cout << "Constructors(&Constructors) " << std::endl;
	m_intPtr = new int(*ob.m_intPtr);
	m_cPtr = new char(*ob.m_cPtr);
	m_fPtr = new float(*ob.m_fPtr);
	m_dPtr = new double(*ob.m_dPtr);
}

/*
 *
 * when moving we're stealing the resources of temporary object;
 * */
Constructors::Constructors(Constructors &&ob) {
	std::cout << "Constructors(&&Constructors) R value reference" << std::endl;
	m_intPtr = ob.m_intPtr;
	m_cPtr = ob.m_cPtr;
	m_fPtr = ob.m_fPtr;
	m_dPtr = ob.m_dPtr;

	//we have assign nullptr to its resources; so that it's destructor
	//does not fail to release it's resources;
	ob.m_intPtr = nullptr;
	ob.m_cPtr = nullptr;
	ob.m_fPtr = nullptr;
	ob.m_dPtr = nullptr;
}


void Constructors::SetValue(int x) {
	*m_intPtr = x;
}

Constructors doSomething(Constructors ob) {
	std::cout << "doing something with constructors ob " << ob.Val()
			<< std::endl;
	return ob;
}

const int& Constructors::Val() const {
	return *m_intPtr;
}

Constructors Add(Constructors a, Constructors b) {
	std::cout << "Constructor add a & b for temporary r value reference; "
			<< std::endl;
	Constructors temp;
	std::cout << "After Constructors temp;" << std::endl;
	temp.SetValue(a.Val() + b.Val());
	std::cout << "After temp.SetValue(a.Val() + b.Val());" << std::endl;
	return temp;
}

void Constructors::Run() {
	std::cout << "STart of Constructors RUN " << std::endl;
	Constructors ob(4);
	std::cout << "After Constructors ob(4);" << std::endl;
	Constructors ob2(ob);
	std::cout << "After Constructors ob2(ob);" << std::endl;
	ob.SetValue(5);
	std::cout << "After Constructors ob.SetValue(5)" << std::endl;
	Constructors ob5(Add(ob, ob2));
	std::cout << "\n After Constructors Add" << std::endl;
	//ob.SetValue(5.6f);  Error - Use of deleted function;

	doSomething(ob2);
	// one copy constructor call
	// one move constructor call - as it is returning r value

	std::cout << "After Constructors Do Somehting \n" << std::endl;

	std::cout << "End of Constructors " << std::endl;
}


