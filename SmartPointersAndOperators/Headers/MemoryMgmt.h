/*
 * MemoryMgmt.h
 *
 *  Created on: Nov 19, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_MEMORYMGMT_H_
#define HEADERS_MEMORYMGMT_H_

#include <callbase.h>

class MemoryMgmt: public Todo {
private:
	int m_iVar { 0 };
public:
	MemoryMgmt();
	~MemoryMgmt();
	MemoryMgmt(const MemoryMgmt &other);
	MemoryMgmt(MemoryMgmt &&other);
	MemoryMgmt& operator=(const MemoryMgmt &other);
	MemoryMgmt& operator=(MemoryMgmt &&other);

	void Run();
};

#endif /* HEADERS_MEMORYMGMT_H_ */
