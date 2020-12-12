/*
 * main.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: pravinkumar
 */
#include "callbase.h"
#include "ClassesAndObjects.h"
#include "StaticMembers.h"
#include "Constructors.h"
#include "LAndRValues.h"
#include "CopyElisionAndMove.h"
int main() {
	Todo *obj = nullptr;
	if (0) {

		/*
		 *
		 * ClassesAndObjects class has
		 * 1. Just Classes and objects
		 * 2. Structures;
		 *
		 * */
		std::cout << std::endl;
		obj = new ClassesAndObjects();
		obj->Run();
		delete obj;
		obj = nullptr;

		/*
		 *
		 * StaticMembers class has
		 * 1. Static member variable
		 * 2. Static member functions
		 *
		 * */
		std::cout << std::endl;
		StaticMembers::PrintObjCount();
		obj = new StaticMembers();
		obj->Run();
		StaticMembers::PrintObjCount();
		delete obj;
		obj = nullptr;

		/*
		 *
		 * Constructor class has
		 * 1. Copy constructor;
		 * 2. Delegating constructor
		 * 3. Deleted functions
		 * 4. Default definition using default keyword - applicable for constructors, destructor.
		 * 5. Getter syntax
		 *
		 * */

		std::cout << std::endl;
		obj = new Constructors();
		obj->Run();
		std::cout << "End of Constructors::Run" << std::endl;
		delete obj;
		obj = nullptr;

		/*
		 *
		 * LAndRValues class has
		 * 1. L and R values explained;
		 * 2. R value references
		 * 3. overloaded functions on R & L values;
		 * */
		std::cout << std::endl;
		obj = new LAndRValues();
		obj->Run();
		delete obj;
		obj = nullptr;

		/*
		 *
		 * CopyElisionAndMove class has
		 * 1. Copy Elision;
		 * 2. Move sematics;
		 * */
		std::cout << std::endl;
		obj = new CopyElisionAndMove();
		obj->Run();
		delete obj;
		obj = nullptr;
	}
	/*
	 *
	 * CopyElisionAndMove class has
	 * 1. Copy Elision;
	 * 2. Move sematics;
	 * */
	std::cout << std::endl;
	obj = new CopyElisionAndMove();
	obj->Run();
	delete obj;
	obj = nullptr;

}

