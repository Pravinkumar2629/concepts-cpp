/*
 * Account.h
 *
 *  Created on: Nov 20, 2020
 *      Author: pravinkumar
 */

#ifndef SOURCE_ACCOUNT_H_
#define SOURCE_ACCOUNT_H_
#include <iostream>
#include <string>


class Account {
private:
	std::string m_Name;
	long m_AccNumber;
	static int s_AccNumberGenerator;
protected:
	float m_Balance;
public:
	Account(const std::string &name, float balance);

	//Base class destructor should always have virtual destructor;
	virtual ~Account();
//	Account(const Account &other);
//	Account(Account &&other);
//	Account& operator=(const Account &other);
//	Account& operator=(Account &&other);

	//Getters and setters
	const std::string GetName() const;
	float GetBalance() const;
	long GetAccountNumber() const;

	virtual void AccumulateInterest();
	virtual void Withdraw(float amount);
	virtual void Deposit(float amount);
	virtual float GetInterestRate() const;


};

#endif /* SOURCE_ACCOUNT_H_ */
