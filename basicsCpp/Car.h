/*
 * Car.h
 *
 *  Created on: Oct 7, 2020
 *      Author: pravinkumar
 */

#ifndef CAR_H_
#define CAR_H_

class Car {

private:
	int m_IFuel = 0;

public:
	//public member variables
	static int totalObject;

	//public member functions
	Car() = default;
	Car(int);
	~Car();
	int accerlarate();
	void PrintStatus() const;
	static void PrintTotalObject();
};

#endif /* CAR_H_ */

