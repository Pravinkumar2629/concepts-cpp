/*
 * Car.cpp
 *
 *  Created on: Oct 7, 2020
 *      Author: pravinkumar
 */

#include "Car.h"
#include <iostream>


Car::Car(int fuel) {
	m_IFuel = fuel;
	std::cout << "Car(int)" << std::endl;
	totalObject++;
}
int Car::accerlarate() {
	m_IFuel--;
	std::cout << "Acceralating " << std::endl;
	return 0;
}
void Car::PrintStatus() const {
	std::cout << "printing the status " << m_IFuel << std::endl;
}
void Car::PrintTotalObject() {
	std::cout << "Printing total number of objects " << totalObject
			<< std::endl;
}

int Car::totalObject = 0;

Car::~Car() {

}

