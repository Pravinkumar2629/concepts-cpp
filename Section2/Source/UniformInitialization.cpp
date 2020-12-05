/*
 * UniformInitialization.cpp
 *
 *  Created on: Oct 24, 2020
 *      Author: pravinkumar
 */

#include "UniformInitialization.h"

void InitializationBasics() {
	//Before c++ 11;
	int a; // un - initialized variable;
	int a1 = 0;  // copy initialization -- whenever assignment operator is used;

	std::string b; // default constructor is called; no need to initialize;

	std::string c{"Hello world"} ; //Direct initialization;
	int a2(0); //Direct initialization;

	char c1[3]; // uninitialized;
	char c2[4] = {'\0'};
	char c3[8] = {'a', 'b', 'c', 'd'}; // Aggregate initialization;
	char c4[8] = {"abcd"};



	//now Uniform Initialization;
	int i {}; //value initialization;
	int i1 {5}; // Direct initialization;

	char ee[5]{};
	char ee2[]{"hello"};

	int *p1 = new int{};
	int *p2 = new int{5};

	char *p3 = new char[7]{};
	char *p4 = new char[8]{};

	float f {};
	int i4 {f};
}

/*
 * 1. Forces initialization;
 * 2. Supported for array types
 * 3. Prevents narrowing conversions;
 * 4. Uniform syntax for all;
 *
 * */


void UniformInitialization::Run() {
	InitializationBasics();
}

UniformInitialization::~UniformInitialization() {
	std::cout << "~UniformInitialization" << std::endl;
}
