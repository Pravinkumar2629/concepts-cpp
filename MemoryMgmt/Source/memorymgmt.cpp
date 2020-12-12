/*
 * memorymgmt.cpp
 *
 *  Created on: Oct 24, 2020
 *      Author: pravinkumar
 */

#include "memorymgmt.h"
#include "string.h"
/*
 *
 * stack - used for local variables and func calls;
 * heap - for dynamic memory  allocation;
 * data section - for global and static data;
 *
 *All the memory is taken from the process address space;
 *
 *dynamic memory allocation is for allocating heap memory;
 *
 *
 * */

void TwoDArray() {
	int ptrArr[2][3] = { { 1, 2, 4 }, { 5, 6, 7 } };
	int *p1 = new int[5];
	int *p2 = new int[3];

	int **pData = new int*[2];
	//do you understand why we do that ?
	// int* will specify that it is array type and second will indirectly specify that it an array and with size;
	// so two d array ;

	pData[0] = p1; // x with length of 5
	pData[1] = p2; // y with length of 3

	pData[0][2] = 2; // this will give you the access of x1,y3
	delete[] p1; // reverse order de-allocation;
	delete[] p2;
	delete[] pData;
}

void NewKeyword() {
	int *p = new int; // new calls the constructor  & and throws exception if fails
	*p = 7;
	delete p; // this will now point to the invalid memory address;
	p = nullptr; // need to do this after deleting the memory;

}
void NewArrays() {
	int *pArr = new int[5];
	for (int i = 0; i < 5; i++) {
		pArr[i] = i;
	}
	std::cout << "New arrays init" << pArr;
	delete[] pArr; // Need to specify [] to delete the entire array;
	pArr = nullptr;
	int *pArr2 = new int[5] { 0, 1, 2, 3, 4 };
	std::cout << "New arrays" << pArr2;
	delete[] pArr2;
	pArr2 = nullptr;
}
void NewStrings() {
	char *pStr = new char[10 + 1]; // count for the null termination charaction when declaring;
	strcpy(pStr, "Helloworld");
	std::cout << pStr;
	delete[] pStr;
	pStr = nullptr;
}

void Add(int x, int y) {
	std::cout << " From add " << x << " " << y << std::endl;
}
fpCallback GetFunc(const FuncRegistry *reg, const char *key) {
	if (strcmp(reg->key, key) == 0) {
		return reg->func;
	}
	return 0;
}

void Run() {
	FuncRegistry *fReg = (FuncRegistry*) malloc(sizeof(FuncRegistry));
	if (fReg != NULL) {
		strcpy(fReg->key, "hello");
		fReg->func = Add;
		fpCallback cb = GetFunc(fReg, fReg->key);
		int x = 1;
		int y = 2;
		cb(x, y);
		free(fReg);
		fReg = NULL;
	}
	FuncRegistry *fReg2 = (FuncRegistry*) calloc(1, sizeof(FuncRegistry));
	std::cout << " Printing after calloc" << std::endl;
	if (fReg2 != NULL) {
		free(fReg2);
		fReg2 = NULL;
	}
	realloc(fReg2, 19 * sizeof(FuncRegistry));
	if (fReg2 != NULL) {
		free(fReg2);
		fReg2 = NULL;
	}
}

