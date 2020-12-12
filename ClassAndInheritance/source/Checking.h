/*
 * Checking.h
 *
 *  Created on: Nov 20, 2020
 *      Author: pravinkumar
 */

#ifndef SOURCE_CHECKING_H_
#define SOURCE_CHECKING_H_

#include "Account.h"

class Checking final: public Account {
public:
	using Account::Account;
	//Checking(const std::string &name, float balance);
	~Checking();

	void Withdraw(float amount);

};

#endif /* SOURCE_CHECKING_H_ */
