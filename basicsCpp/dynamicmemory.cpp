/*
 * dynamicmemory.cpp
 *
 *  Created on: Oct 7, 2020
 *      Author: pravinkumar
 */


#include <cstdlib>
#include <iostream>
#include <cstring>
#include "mixed.h"
struct Person
{
    int height;
    int weight;
    char name[10];
};

int allocateMemory()
{
    //wont initialize and void * will casted automatically in C.
    //but in c++ we need to do a manual type cast;
    Person *person = (Person *)malloc(sizeof(Person));
    //number of members in c alloc must be passed
    Person *personTwo = (Person *)calloc(1, sizeof(Person));
    person->height=20;
    strcpy(person->name,"viky");
    //personOne Will not be initialized // and persontwo would have been
    std::cout << "person obj" << person->name << std::endl;
    free(person);
    std::cout << "person two obj" << personTwo->name << "just name" << person->name << std::endl;
    return 0;
}

