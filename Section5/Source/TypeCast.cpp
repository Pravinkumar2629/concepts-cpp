/*
 * TypeCast.cpp
 *
 *  Created on: Nov 13, 2020
 *      Author: pravinkumar
 */


#include "TypeCast.h"
#include "Integer.h"

void BasicCasts(void) {
	int a = 7, b = 2;
	float x = a / b;
	//will print 3;
	std::cout << "x " << x << std::endl;
	float f = (float) a / b;
	//will print 3.5;
	std::cout << "f " << f << std::endl;

	float f1 = static_cast<float>(a) / b; // c++ style casting; should be preffered;
	char *c = (char*) &x; // should not prefferent if not intentional;
	//char *c1 = static_cast<char*>(&x); // Error -- error: invalid static_cast from type ‘float*’ to type ‘char*’
	char *c2 = reinterpret_cast<char*>(&x);

	//advantage of reinterpret cast -.
	const int i = 1;
	//int *p = &i;  // Error  invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
	int *p = (int*) &i; // is working BUT should not do. as constant value cannot be pointed like this;

	//below is the correct one. it should throw error;
	//int *p2 = reinterpret_cast<int*>(&i); //error: reinterpret_cast from type ‘const int*’ to type ‘int*’ casts away qualifiers
	int *p3 = const_cast<int*>(&i); // this is correct;

}
void CastWillHappenIfYouUseMewithPrimitiveInteger(Integer a) {

}
void CastWillHappenIfYouUseMewithPrimitiveIntegerConst(const Integer &a) {
	//a.SetValue(7);  passing ‘const Integer’ as ‘this’ argument discards qualifiers [-fpermissive]
}
void ConstructorCasts(void) {
	Integer a { 5 };
	Integer b = 7;
	CastWillHappenIfYouUseMewithPrimitiveInteger(7);
	std::cout << "v CastWillHappenIfYouUseMewithPrimitiveIntegerConst start "
			<< std::endl;
	CastWillHappenIfYouUseMewithPrimitiveIntegerConst(8);
	std::cout << "v CastWillHappenIfYouUseMewithPrimitiveIntegerConst end "
			<< std::endl;
}

void CustomToPrimitive() {
	Integer a { 5 };
	int x = 0;
	x = static_cast<int>(a); // custom to primitive should always use htis format to avoid confusions; marking the conversion operator as explicit
	//will avoid implicit type conversion;
	std::cout << "value of x after custom to primitive " << x << std::endl;
}
void InitializationVsAssignment(void) {
	std::cout << "void InitializationVsAssignment(void){ start" << std::endl;
	Integer a;
	a = 10;

	std::cout << "after assignment " << std::endl;
	Integer b { 10 };
	std::cout << "void InitializationVsAssignment(void){ end" << std::endl;
}



void Types::Run() {
	std::cout << "Types::Run start" << std::endl;
	BasicCasts();
	ConstructorCasts();
	CustomToPrimitive();
	InitializationVsAssignment();
}

