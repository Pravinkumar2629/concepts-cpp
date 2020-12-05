/*
 * Car.h
 *
 *  Created on: Oct 26, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_CAR_H_
#define HEADERS_CAR_H_

#include "callbase.h"
#include "Point.h"


class Car {
private:
	int x { 0 }; // non-static data member initializers;
	float y { 0 };
	int arr[4] { 1, 2, 3, 4 };
	char *p = new char;
	
public:
	int z { 0 }; // this is just for the illustration; dont' use public fields;
	
	Car() {
		//you may initialize the default values here; but this may lead to code duplication;
	}
	Car(int x, int y);
	
	const int& X() const;
	int& X();
//	auto X() && -> auto&& {
//		return std::move(x);
//	}
//	;

	//int&& X();
	const float& Y() const;
	float& Y();

	void SetZ(int);
	void DragTheCar(Point p, int speed) const;
	void PrintData() const;
	~Car();
};

#endif /* HEADERS_CAR_H_ */
