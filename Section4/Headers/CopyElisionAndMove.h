/*
 * CopyElisionAndMove.h
 *
 *  Created on: Oct 28, 2020
 *      Author: pravinkumar
 */

#ifndef HEADERS_COPYELISIONANDMOVE_H_
#define HEADERS_COPYELISIONANDMOVE_H_

#include "callbase.h"

/*
 *
 * FLAG  -fno-elide-constructors
 *
 *
 *
 * */

class CopyElisionAndMove: public Todo {
private:
	int *m_iPtr;
public:
	int *m_iPtr2;
	CopyElisionAndMove();
	CopyElisionAndMove(int value);
	CopyElisionAndMove(CopyElisionAndMove &ob);
	CopyElisionAndMove(CopyElisionAndMove &&ob);
	~CopyElisionAndMove();
	void Run();
};





#endif /* HEADERS_COPYELISIONANDMOVE_H_ */
