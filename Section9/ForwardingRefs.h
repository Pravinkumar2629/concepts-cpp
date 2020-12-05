/*
 * ForwardingRefs.h
 *
 *  Created on: Nov 27, 2020
 *      Author: pravinkumar
 */

#ifndef FORWARDINGREFS_H_
#define FORWARDINGREFS_H_

#include "Todo.h"

class ForwardingRefs: public Todo {
public:
	ForwardingRefs();
	virtual ~ForwardingRefs();
	void Run() override;
};

#endif /* FORWARDINGREFS_H_ */
