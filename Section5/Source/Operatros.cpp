/*
 * Operatros.cpp
 *
 *  Created on: Nov 13, 2020
 *      Author: pravinkumar
 */

#include "Operators.h"
#include "SmartPointer.h"
#include "memory"

Operators::Operators() {
	std::cout << "\n Operators() " << std::endl;
}
Operators::~Operators() {
	std::cout << "~Operators() " << std::endl;
}
void MoveUniquePtr(std::unique_ptr<Integer> ob) {
	std::cout << "void MoveUniquePtr(std::unique_ptr<Integer> *ob) "
			<< ob->GetValue()
			<< std::endl;
}
void SharedPtr(std::shared_ptr<Integer> ob) {
	std::cout << "void SharedPtr(std::unique_ptr<Integer> *ob) "
			<< ob->GetValue()
			<< std::endl;
}

void Operators::Run() {
	std::cout << "Operators::Run Start " << std::endl;
	SmartIntPointer ptr = new Integer(1);
	std::cout << "smart Int ptr;" << ptr->GetValue() << std::endl;

	//Unique ptr section
	std::cout << "Unique Ptr start " << std::endl;
	std::unique_ptr<Integer> uPtr(new Integer(11));
	//MoveUniquePtr(uPtr); //Error use of deleted function
	MoveUniquePtr(std::move(uPtr));
	std::cout << "Unique Ptr end " << std::endl;

	//Shared ptr section
	/*
	 * Shared pointer automatically uses an count for each instance created; (reference)
	 * when the reference count becomes zero, the resource will be deleted;
	 *
	 * */
	std::cout << "Shared Ptr start " << std::endl;
	std::shared_ptr<Integer> sPtr(new Integer(12));
	SharedPtr(sPtr);
	std::cout << "Shared Ptr end " << std::endl;


}

