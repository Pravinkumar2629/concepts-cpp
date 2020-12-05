/*
 * Transact.cpp
 *
 *  Created on: Nov 20, 2020
 *      Author: pravinkumar
 */
#include "Transact.h"

void Transact(Account *pAccount) {
	std::cout << "Transact" << std::endl;
	std::cout << "Transact Initial balance " << pAccount->GetBalance()
			<< std::endl;
	pAccount->Withdraw(100);
	pAccount->Deposit(200);
	pAccount->AccumulateInterest();
	std::cout << "Transact Interest " << pAccount->GetInterestRate()
			<< std::endl;
	std::cout << "Transact Closing balance " << pAccount->GetBalance()
			<< std::endl;
	std::cout << "Transact end" << std::endl;

}

