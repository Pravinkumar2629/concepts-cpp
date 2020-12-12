/*
 * Savings.cpp
 *
 *  Created on: Nov 20, 2020
 *      Author: pravinkumar
 */

#include "Savings.h"

Savings::Savings(const std::string &name, float balance, float rate) :
		Account(name, balance), m_Rate(rate) {
}

Savings::~Savings() {
	// TODO Auto-generated destructor stub
}

void Savings::AccumulateInterest() {
	m_Balance += (m_Balance * m_Rate);
}
float Savings::GetInterestRate()
const
{
	return m_Rate;
}

float Savings::GetInterestRate(int l) const {
	return m_Rate;
}
