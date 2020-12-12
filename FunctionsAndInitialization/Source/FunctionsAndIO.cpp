/*
 * FunctionsAndIO.cpp
 *
 *  Created on: Oct 23, 2020
 *      Author: pravinkumar
 */

#include <FunctionsAndIO.h>
#include <initializer_list>
#include <iostream>

//Prototyping or declaration;
void DoSomething();

extern "C" void WhenYouDontWantOthersToChangeReference(const int &ref) {
	std::cout << "Do necessary stuffs " << ref << std::endl;
	//ref = 10;  // this is not possible when using const modifier;

}
#define Square(x) x*x;

inline long SquareInline(int x) {
	return x * x;
}

/*
 * inline functions won't get merged by compiler if,
 * 1. function is too large
 * 2. it is recursive
 * 3. functions invoked through pointers;
 * */
void InlineFunctions() {
	auto x = 10;
	x = Square(x)
	; // works perfectly;
	auto y = Square(x + 1)
	// works not correct - this will be pre-processed into x+1 * x+1;
	// which is expressions won't be eavaluated in macro;
	//to overcome this. we can use inline functions;

	auto z = SquareInline(x + 1);
}

inline int GetArraySize(int x[]) {
	return *(&x + 1) - x;
}

void Loops() {
	int x[] = { 1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 0 };
	for (auto i = 0; i < GetArraySize(x); i++) {
		x[i] += 1;
		//x[i] = 0;
		std::cout << "for loop " << x[i] << std::endl;
	}
	for (const auto &i : x) {
		//i += 1;  //Error  - Assignment of read-only reference;
		std::cout << "range based for loop with reference " << i << std::endl;
	}

	for (const auto &i : { 1, 3, 4, 5 }) {
		std::cout << "initializer list " << i;
	}
	int *begin = &x[0];
	int *end = &x[GetArraySize(x)];
	while (begin != end) {
		std::cout << "element " << *begin << std::endl;
	}
	
	int *begin2 = std::begin(x);
	int *end2 = std::end(x);
	while (begin2 != end2) {
		std::cout << "element 2 " << *begin << std::endl;
	}
	auto range = x;
	auto begin3 = std::begin(x);
	auto end3 = std::end(x);

	// in c++ 17 range need not to be of the same type ;
	// for example when iterating character arr  being is a character where end is a null;
	// for such cases; this support would be really helpful;

	for (; begin3 != end3; ++begin3) {
		auto val = *begin3;
		std::cout << "element on value * " << val;
	}

}
int Add(int a, int b) {
	return a + b;
}

extern "C" float Add(int a, float b) { //return type not considered  // To stop the name mangling
	return static_cast<float>(a + b);
}
int Add(int *a, int *b) {
	return *a + *b;
}
int Add(float a, int b) {
	return a + b;
}
int Add(const int *a, int *b) {
	return *a + *b;
}
int Add(const int *const a, const int *b) { // so const <type> * const <var> won't overload
	return *a + *b;
}

void OverLoadConcepts() {
	int a = 0;
	int b = 1;
	int x = Add(a, b);
}

void Swap(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}
void SwapUsingPointers(int *a, int *b) {
	if (a != nullptr && b != nullptr) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int referenceTypes() {
	std::cout << "reference types" << std::endl;
	int x = 10;
	int &ref = x;  // reference always needs to be initialized
	ref = 11;
	x = 12;
	std::cout << "value of x " << x << std::endl;
	int y = 122;
	Swap(x, y);
	//Swap(x, nullptr); can't pass a nullptr; that's an advantage;

	SwapUsingPointers(&x, nullptr);
	SwapUsingPointers(&x, &y);

	return 0;
}

int add(int *a, int *b) {
	int x { 0 };
	x = (*a + *b);
	return x;
}

void UseOfAutoKeyword(){
	auto x = 10;
	auto y = 10.0;
	auto k = 3.14f;
	auto z = referenceTypes();

	const auto var = 10;
	auto var2 = &var;
	auto var3 = var;
	auto var4 = {1,3,4,5,66,0};
	auto var5 { 5 }; // this is an error.
	auto var6 {0};

}

void DoSomething() {
	std::cout << "This is just to illustrate the behaviour of functions";
	int a = 5;
	int b = 10;
	auto c = add(&a, &b);
	const int PI = 3.1458;  // const is type safe than macros; preffered in c++;
	std::cout << "area of circle " << PI * a * a << "unused c" << c
			<< std::endl;
}

void FunctionsAndIO::Run() {
	DoSomething();
}

FunctionsAndIO::~FunctionsAndIO() {
	std::cout << "~FunctionsAndIO" << std::endl;
}

