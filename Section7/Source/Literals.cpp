/*
 * Literals.cpp
 *
 *  Created on: Nov 22, 2020
 *      Author: pravinkumar
 */

#include "Literals.h"

class Distance {
	long double kms;
public:
	Distance(long double km) :
			kms(km) {
		
	}
	void Print() {
		std::cout << "Printing distance " << kms << std::endl;
	}
};

Distance operator"" _mi(long double miles) {
	return Distance { miles * 1.6 };
}

Literals::Literals() {
	// TODO Auto-generated constructor stub

}

void Literals::Run() const {
	Distance d { 3.1_mi };
	d.Print();
}

Literals::~Literals() {
	// TODO Auto-generated destructor stub
}

