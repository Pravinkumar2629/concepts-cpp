/*
 * Templates.cpp
 *
 *  Created on: Nov 27, 2020
 *      Author: pravinkumar
 */

#include "Templates.h"
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <any>

template<typename T>
T Max(T x, T y) {
	return x > y ? x : y;
}

template<typename T>
T Add(T x, T y) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	std::cout << typeid(T).name() << std::endl;
	return x + y;
}

template<typename T, typename T2 = std::vector<T>>
T2* CreateVector(T o) {
	auto ret = new T2();
	return ret;
}

template<typename T>
T ArraySum(T *arr, T size) {
	auto x = std::accumulate(arr, &arr[size - 1], 0);
	return x;
}

template<typename T, int size>
T MaxInArray(T (&arr)[size]) {
	std::sort(arr, &arr[size]);
	std::cout << "in Max n Arry" << std::endl;
	for (auto i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
	return arr[size - 1];
}
template<typename T, int size>
std::pair<T, T> MinAndMax(T (&arr)[size]) {
	std::sort(std::begin(arr), std::end(arr));
	std::cout << "Returing min and max" << std::endl;
	return std::make_pair(arr[0], arr[size - 1]);
}
template<typename T>
std::ostream& operator <<(std::ostream &out, std::pair<T, T> pair) {
	out << "first " << pair.first << " second " << pair.second << std::endl;
	return out;
}

//Explicit instantiation;
template std::ostream& operator <<(std::ostream&, std::pair<char, char>);
template std::ostream& operator <<(std::ostream&,
		std::pair<std::string, std::string>);
template std::ostream& operator <<(std::ostream &out, std::pair<int, int> pair);

//Explicit specialization;
template<> const char* Max<const char*>(const char *a, const char *b) {
	return strcmp(a, b) > 0 ? a : b;
}


void Templates::Run() {

	std::cout << "Templates::Run start" << std::endl;

	int (*addFunc)(int, int) = Add;
	addFunc(3, 4);
	//auto vector = CreateVector(8);
	//std::cout << "create vector " << typeid(vector).name() << std::endl;
	auto z = Max(3, 4);
	std::cout << " Z " << z << std::endl;
	auto x = Max<float>(3, 4.4f);
	std::cout << " x " << x << std::endl;

	int arr[] { 1, 2, 4, 3, 11, 5, 6, 7, 8, 9, 10 };

	char c_arr[] { 'a', 'c', 'b', 'd', 'f', 'e' };
	std::string s_arr[] { "pravin", "keerthiga", "kumar" };
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	ArraySum(arr, static_cast<int>(sizeof(arr) / sizeof(*arr)));

	std::cout << "aRrya sum " << ArraySum(arr, [&arr]() -> int {
		return *(&arr + 1) - arr;
	}()) << std::endl;
	//int size = static_cast<int>(*(&arr + 1) - arr);
	std::cout << "Max in Array " << MaxInArray(arr) << std::endl;
	std::cout << "Max in char Array " << MaxInArray(c_arr) << std::endl;
	std::cout << "Max in string Array " << MaxInArray(s_arr) << std::endl;
	std::cout << "Templates::Run end" << std::endl;

	std::cout << "Min And Max in Array "
			<< static_cast<std::pair<int, int>>(MinAndMax<int>(arr))
			<< std::endl;

	std::cout << "Min and Max in char Array "
			<< static_cast<std::pair<char, char>>(MinAndMax(c_arr))
			<< std::endl;

	const int length = sizeof(s_arr) / sizeof(s_arr[0]);
	std::cout << "Min And Max in string Array "
			<< static_cast<std::pair<std::string, std::string>>(MinAndMax<
					std::string>(s_arr)) << std::endl;
	std::cout << "Templates::Run end" << std::endl;

}

Templates::Templates() {
	std::cout << "Templates::Templates() " << std::endl;

}

Templates::~Templates() {
	std::cout << "~Templates::Templates() " << std::endl;
}
