/*
 * Account.cpp
 *
 *  Created on: Nov 20, 2020
 *      Author: pravinkumar
 */

#include "Account.h"

int Account::s_AccNumberGenerator = 0;

Account::~Account() {
	// TODO Auto-generated destructor stub
}

Account::Account(const std::string &name, float balance) :
		m_Name(name), m_Balance(balance) {
	m_AccNumber = s_AccNumberGenerator++;
}

const std::string Account::GetName() const {
	return m_Name;
}

float Account::GetBalance() const {
	return m_Balance;
}

long Account::GetAccountNumber() const {
	return m_AccNumber;
}

void Account::AccumulateInterest() {
}

void Account::Withdraw(float amount) {
	if (m_Balance >= amount) {
		m_Balance -= amount;
	} else {
		std::cout << "Insufficient balance for this withdrawal" << std::endl;
	}
}

void Account::Deposit(float amount) {
	m_Balance += amount;
	std::cout << "Desposit success! new balance is : " << m_Balance
			<< std::endl;
}

float Account::GetInterestRate() const {
	return 0.0f;
}
//
////copy constructor
//Account::Account(const Account &other) {
//	m_AccNumber = other.GetAccountNumber();
//	m_Balance = other.GetBalance();
//	m_Name = other.GetName();
//}
////move constructor
//Account::Account(Account &&other) {
//	// TODO Auto-generated constructor stub
//
//}
////copy assignment
//Account& Account::operator=(const Account &other) {
//	// TODO Auto-generated method stub
//
//}
////move assignment
//Account& Account::operator=(Account &&other) {
//	// TODO Auto-generated method stub
//
//}

