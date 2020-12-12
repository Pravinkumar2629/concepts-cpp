/*
 * Lambda.h
 *
 *  Created on: Nov 29, 2020
 *      Author: pravinkumar
 */

#ifndef LAMBDA_H_
#define LAMBDA_H_

#include "Base.h"

class Lambda: public Base {
public:
	Lambda();
	virtual ~Lambda();
	void Run() override;
};

#endif /* LAMBDA_H_ */
