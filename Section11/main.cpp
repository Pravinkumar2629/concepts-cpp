/*
 * main.cpp
 *
 *  Created on: Nov 30, 2020
 *      Author: pravinkumar
 */
#include "Base.h"
#include "STLContainers.h"

#include <memory>

void Run(std::unique_ptr<Base> ptr) {
	ptr->Run();
}

int main() {
	Run(std::make_unique<STLContainers>());
}


