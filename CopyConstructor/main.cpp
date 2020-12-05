/*
 * main.cpp
 *
 *  Created on: Oct 8, 2020
 *      Author: pravinkumar
 */

#include "Integer.h"
#include <iostream>

// To avoid the shallow copy.. we use custom copy constructor to avoid problems;
void HowCopyWorks() {
	int *ptr = new int(10);
	//Shallow copy -- as the addres of the pointer is getting copied to another pointer
	int *ptr2 = ptr;
	//Deep copy -- as the new memory is created with value at the pointer;
	int *ptr3 = new int(*ptr);
	// we should prefer deep copy in most cases;
}

//third case when object is passed
void PrintIntger(Integer i) {
	std::cout << "Printing integer " << i.GetValue();
}
Integer Add(Integer iOne, Integer iTwo) {
	return Integer((iOne.GetValue() + iTwo.GetValue())); // second case when an integer is returned
}

int main() {
	Integer iOne(0);
	Integer iTwo(iOne); //First case when it is assigned to another obejct;

	//copy of the object is create in 3 scenarios
	// when it si passed to a method;
	// when it returned from a method;
	// when we manually assign to a object;
	//customer synthesizes a copy constuctor in all the above cases;
}

