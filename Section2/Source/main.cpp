/*
 * main.cpp
 *
 *  Created on: Oct 23, 2020
 *      Author: pravinkumar
 */

//this is for dump view;
//objdump -x FunctionsAndIO.o
// below is for map file;
//-Map=output.map

#include "FunctionsAndIO.h"
#include "Pointers.h"

void onEndOfProgram() {
	std::cout << "End of the Program " << std::endl;
}

int main() {
	atexit(onEndOfProgram);
	Todo *d = new FunctionsAndIO();
	d->Run();
	d = new Pointers();
	d->Run();
}

