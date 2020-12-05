/*
 * basics.cpp
 *
 *  Created on: Oct 5, 2020
 *      Author: pravinkumar
 */

#include <iostream>

#include "Car.h"
#include "mixed.h"

int sum(int &x, int &y, int &z) {
	z -= 1;
	return x + y + z;
}

int swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
	return 0;
}
int autoPtr() {
	using namespace std;
	cout << "Hello world from basics application" << endl;
	auto a { 1 }, b { 2 }, c { 3 }; //Direct initialization
	auto x = sum(a, b, c);
	cout << "x after auto " << x << endl;
	cout << "c after sum call " << c << endl;
	auto *ptr = &c;
	swap(&x, ptr);
	cout << "after swap " << *ptr;
	return 0;
}

//A const object can be used to call method which doesnot changes the state of the object
//Logically,
// the object is constant - so all the properites of it are constants;
// method cannot be called if that changes the state of the object;
void ConstObjectProperties() {
	//Car ob;
	const Car ob(4);
	ob.PrintStatus();
	ob.PrintTotalObject();
	Car ob2(5);
	ob.PrintTotalObject();
	//ob.accerlarate();

}

int main() {
	using std::cout;
	using std::endl;
	Car c1;
	c1.accerlarate();
	allocateMemory();
	ConstObjectProperties();
	cout << "after allocating memory" << endl;
}

