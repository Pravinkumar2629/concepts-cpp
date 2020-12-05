/*
 * Integer.h
 *
 *  Created on: Nov 27, 2020
 *      Author: pravinkumar
 */

#ifndef INTEGER_H_
#define INTEGER_H_

#include <iostream>

class Integer {
	int *m_IPtr;
public:
	Integer();
	virtual ~Integer();

	Integer(int value);


	Integer(const Integer &other);
	Integer(Integer &&right);

	Integer& operator =(const Integer &other);
	Integer& operator =(Integer &&right);

	int operator +(const Integer &right);
	int operator +(int &right);
	friend std::ostream& operator <<(std::ostream &out, const Integer &ob);
};

#endif /* INTEGER_H_ */
