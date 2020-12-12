/*
 * ClassesAndObject.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: pravinkumar
 */
#include "ClassesAndObjects.h"
#include "Car.h"
#include "Point.h"
void ClassesAndObjects::Run() {

	/*
	 * const object won't allow to access non-const member functions;
	 * so only the functions that qualified with const can be accessed using the const object
	 * const modifier can be used on the functions which do not modify the state of the object;
	 *
	 * */
	std::cout << "ClassesandObjects Run" << std::endl;
	const Car *ob = new Car;
	std::cout << "ob->z" << ob->z << std::endl;
	std::cout << "ob->PrintData();" << std::endl;
	ob->PrintData();
	Point p = { 1, 2 };
	std::cout << "ob->DragTheCar(p, 2);" << std::endl;
	ob->DragTheCar(p, 2);



}
ClassesAndObjects::~ClassesAndObjects() {
	std::cout << "~ClassesandObjects" << std::endl;
}
