/*
 * Constructors.h
 *
 *  Created on: Oct 26, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_CONSTRUCTORS_H_
#define HEADERS_CONSTRUCTORS_H_

#include "callbase.h"

/*
 * Since, our class may acquire resource. this may lead into some issues.
 * So Always,
 * Remember the rule of five when creating class and object;
 * 1.Destructor
 * 2.Copy constructor
 * 3.Copy assignment operator
 * 4.Move constructor
 * 5.Move assignment operator
 *
 * */

//*******************************************************Rule of 5


class Constructors: public Todo {
	int *m_intPtr;
	char *m_cPtr;
	float *m_fPtr;
	double *m_dPtr;
public:
	//Constructors() = default; //Can be used to denote that a default constructor need to be generated;
	Constructors();
	Constructors(int value);
	Constructors(int value, char c); //Delegating constructors;
	Constructors(int value, char c, float f);
	Constructors(int value, char c, float f, double d);

	//Copy Constructor;
	Constructors(const Constructors &ob);
	//Constructors(const Constructors &ob) = delete; //Can be used to denote that a copy constructors has to be deleted;

	//Move constructor;
	Constructors(Constructors &&ob);
	const int& Val() const;
	void SetValue(int x);
	void SetValue(float) = delete;
	void Run();

	~Constructors();
};

#endif /* HEADERS_CONSTRUCTORS_H_ */
