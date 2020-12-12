/*
 * Car.cpp
 *
 *  Created on: Oct 26, 2020
 *      Author: pravinkumar
 */


#include "Car.h"

void JustDoSomething(const Car x) {
	std::cout << "Just having your car " << x.z << std::endl;
}
void Car::SetZ(int z) {
	this->z = z;
}
Car::Car(int x, int y) {
	//this.x = x;
	//this.y = y;
}
Car::~Car() {
	std::cout << "End of Car" << std::endl;
}

const int& Car::X() const {
	return x;
}
int& Car::X() {
	return x;
}

// const modifier should be used when the method is not modifying the state of the obect;
const float& Car::Y() const {
	return y;
}
float& Car::Y() {
	return y;
}

void Car::PrintData() const {
	std::cout << "x " << x << std::endl;
	std::cout << "y " << y << std::endl;

	// jsut doing something;
	JustDoSomething(*this); // You can pass the current object with ; *this;
}
void Car::DragTheCar(Point p, int speed) const {
	std::cout << "Moving to point x ,y " << p.x << " - " << p.y << "at speed "
			<< speed << std::endl;
}
