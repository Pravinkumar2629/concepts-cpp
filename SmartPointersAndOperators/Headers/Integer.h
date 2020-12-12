/*
 * Integer.h
 *
 *  Created on: Oct 28, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_INTEGER_H_
#define HEADERS_INTEGER_H_

#include "callbase.h"
//#include <utility>

class Integer {
private:
	int *m_iVar;
	int privateMember { 4 };
public:
	Integer();
	Integer(int);
	//Copy
	Integer(const Integer&);

	//Move
	Integer(Integer&&);

	//Copy assignment
	Integer& operator =(const Integer &ob);

	//Move Assignment
	Integer& operator =(Integer &&ob);
	~Integer();

	int GetValue() const;
	void SetValue(int val);

	Integer operator +(const Integer &b) const;
	// operator - has been overloaded as a global function which is availabe on integer.cpp;

	explicit operator int(); // As this may cause confusion;

	Integer& operator ++();
	Integer operator ++(int);
	bool operator ==(const Integer &b) const;
	friend std::ostream& operator <<(std::ostream&, const Integer&);
	friend class Friday;



};

//this is a friend of Integer; so this can access the private members of it;
class Friday {

};

// operator - has been overloaded as a global function which is availabe on integer.cpp;
Integer operator -(const Integer&, const Integer&);
std::istream& operator >>(std::istream&, Integer&);

#endif /* HEADERS_INTEGER_H_ */

