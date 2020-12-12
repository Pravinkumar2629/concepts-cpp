/*
 * main.cpp
 *
 *  Created on: Nov 27, 2020
 *      Author: pravinkumar
 */
#include "Todo.h"
#include "Templates.h"
#include "ForwardingRefs.h"
#include "VariadicTemplates.h"
#include "ClassTemplates.hpp"
#include <memory>

void Run(std::unique_ptr<Todo> ptr) {
	//std::cout << "reference" << std::is_reference<Todo>(&ptr) << std::endl;
	std::cout << "Leaving main \n" << std::endl;
	ptr->Run();
	std::cout << "\nback to main " << std::endl;
}

int main() {
	//Run(std::move(std::unique_ptr<Templates> { new Templates() }));
	//Run(std::move(std::make_unique<Templates>()));
	//Run(std::make_unique<ForwardingRefs>());
	//Run(std::make_unique<VariadicTemplates>());
	//Run(std::unique_ptr<VariadicTemplates> { new VariadicTemplates() });
	Run(std::make_unique<ClassTemplates>());
}

//
//Create a factory method that creates an instance of some type T, initializes it with arguments and returns it.
//
//Here are some usage examples of the factory.
//
//    int *p1 = CreateObject<int>(5) ;
//
//    std::string *s = CreateObject<std::string>() ;//Default construction
//
//    Employee * emp = CreateObject<Employee>(
//    "Bob",    //Name
//    101,      //Id
//    1000) ;   //Salary
//
//    Contact *p = CreateObject<Contact>(
//    "Joey",                //Name
//    987654321,             //Phone number
//    "Boulevard Road, Sgr", //Address
//    "joey@poash.com") ;    //Email
//

