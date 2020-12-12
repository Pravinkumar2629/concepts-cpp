/*
 * main.cpp
 *
 *  Created on: Nov 29, 2020
 *      Author: pravinkumar
 */

#include <memory>
#include "Lambda.h"
#include "Base.h"

void Run(std::unique_ptr<Base> ptr) {
	ptr->Run();
}

// 32 bit compilation requirements; and have to enable or pass -m32 flag to compiler and linker
//sudo apt-get install g++-multilib
//sudo apt-get install libc6-dev-i386

int main() {
	Run(std::make_unique<Lambda>());
}


