/*
 * main.cpp
 *
 *  Created on: Nov 20, 2020
 *      Author: pravinkumar
 */


#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Transact.h"
void Run(void) {
	Account acc("Amutha", 100.5f);
	std::cout << "Welcome! " << acc.GetName() << "\nYour initial balance is : "
			<< acc.GetBalance() << std::endl;
	acc.Deposit(200);
	acc.Withdraw(2000);
	std::cout << "closing balance is " << acc.GetBalance() << std::endl;

	Savings acc1("Pravin", 2000.5f, 11.4f);
	std::cout << "\n\nWelcome! " << acc1.GetName()
			<< "\nYour initial balance is : " << acc1.GetBalance() << std::endl;
	acc1.Deposit(200);
	acc1.Withdraw(2000);
	std::cout << "closing balance is " << acc1.GetBalance() << std::endl;

	Checking acc2("Dhanabal", 150.5f);
	std::cout << "\n\nWelcome! " << acc2.GetName()
			<< "\nYour initial balance is : " << acc2.GetBalance() << std::endl;
	acc2.Deposit(200);
	acc2.Withdraw(250);
	std::cout << "closing balance is " << acc2.GetBalance() << std::endl;

	Transact(&acc2);
}
int main() {
	//Run();

	//size of the class varies if it has virtual keyword;
	//becuase vtable & vptr will take 4 bytes(32)bits as per the architecture
	std::cout << "Size of Account " << sizeof(Account) << std::endl;


	return 0;
}
