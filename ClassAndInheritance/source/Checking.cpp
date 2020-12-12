/*
 * Checking.cpp
 *
 *  Created on: Nov 20, 2020
 *      Author: pravinkumar
 */

#include "Checking.h"

//Checking::Checking(const std::string &name, float balance) :
//		Account(name, balance) {
//	// TODO Auto-generated constructor stub
//
//}

Checking::~Checking() {
	// TODO Auto-generated destructor stub
}

void Checking::Withdraw(float amount) {
	if ((m_Balance - amount) >= 50.0f) {
		Account::Withdraw(amount);
	} else {
		std::cout << "Insufficient balance " << std::endl;
	}
}
