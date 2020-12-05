/*
 * Savings.h
 *
 *  Created on: Nov 20, 2020
 *      Author: pravinkumar
 */

#ifndef SOURCE_SAVINGS_H_
#define SOURCE_SAVINGS_H_

#include "Account.h"

class Savings: public Account {
private:
	float m_Rate;
public:
	Savings(const std::string &name, float balance, float rate);
	~Savings();

	void AccumulateInterest();
	float GetInterestRate() const;

	float GetInterestRate(int l) const;
};

#endif /* SOURCE_SAVINGS_H_ */
