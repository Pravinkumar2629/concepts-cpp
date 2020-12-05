/*
 * Lambda.cpp
 *
 *  Created on: Nov 29, 2020
 *      Author: pravinkumar
 */

#include "Lambda.h"
#include <fstream>

Lambda::Lambda() {

}

Lambda::~Lambda() {

}

namespace BasicFp {

	int CompareAsc(int&, int&);

	template<typename T>
	using Comparator2 = T (*)(T&, T&);

	template<typename T, int size, typename Comparator>
	void Sort(T (&arr)[size], Comparator comp) {

		for (int i = 0; i < size; ++i) {
			for (int j = i; j < size; ++j) {
				if (comp(arr[i], arr[j])) {
					std::swap(arr[i], arr[j]);
				}
			}
		}
	}
	int CompareAsc(int &x, int &y) {
		return x > y;
	}

	void FunctionPointer() {
		int arr[] { 2, 1, 4, 5, 3, 10, 7 };
		Write("before");
		for (auto x : arr) {
			std::cout << x << ' ';
		}
		//Sort<int, 7, Comparator2<int>>(arr, CompareAsc);
		Sort(arr, CompareAsc); //above will also work
		Write("After");
		for (auto x : arr) {
			std::cout << x << ' ';
		}
	}

	void Basics() {
		FunctionPointer();
	}
}

namespace FunctionObjects {
	struct CompareAscFO {
		bool operator ()(int x, int y) {
			return x > y;
		}
	};

	void SortWithFO() {
		std::cout << "arc " << sizeof(void*) << std::endl;
		int arr[] { 4, 5, 2, 3, 1, 9 };
		CompareAscFO comp;
		Write("\nBefore");
		for (auto x : arr) {
			std::cout << x;
		}
		BasicFp::Sort(arr, comp);
		Write("\nAfter");
		for (auto y : arr) {
			std::cout << y;
		}
	}

}

namespace LambdaEx {

	template<typename T>
	struct __UnNamed {
		T obj;
		__UnNamed(T ob) {
			obj = ob;
		}
		T operator ()(T x) {
			obj += x;
			return obj;
		}
	};

	class Product {
		std::string m_name;
		int price { };
	public:
		Product(std::string &n) :
				m_name(n), price(0) {

		}
		void AssignSomething(int price2) {
			int priceCalculated = price2 * 2;
			auto doit = [priceCalculated, this]() {
				price = priceCalculated;
				std::cout << "Price inside " << price << std::endl;
			};
			doit();
			std::cout << "Price outer " << price << std::endl;
		}
	};

	void Lambda() {
		int i = 11;
		auto fn = [i]() -> int {
			std::cout << "acquired i " << i << std::endl;
			return 0;
		};

		std::cout << "Function type id" << typeid(fn).name() << std::endl;

		fn();

		auto templatedLambda = [](auto x, auto y) noexcept {
			std::cout << " Lambda " << x + y;
			return x + y;
		};

		templatedLambda(4, 5);
		templatedLambda(4.5, 5.6);

		int offset = 20;

		auto fn3 = [offset](auto x) {
			x += offset;
		};
		int z = 3;

		fn3(z);

		auto fn4 = [offset](auto x) {
			offset += x;
		};

		//fn4(offset); // ERR - offset cannot be modified;
		//See the example struct
		//so above can be interpretted by the compiler as
		// Using __UnNamed struct;

		__UnNamed <int> f(3);

		f(4); // by default lambda uses const qualifier on the function;

		// so somehow the const should be removed;
		// which can be done using mutable keyword;

		auto fz = [offset](auto x) mutable {
			offset += x;
		};

		std::cout << "f " << f.obj << std::endl;
		fz(77);
		std::cout << "fz" << offset << std::endl; // mutable makes offset modifyable but only with in it's scope;
		// since this is just a copy, the affected value cannot be seen outside;

		//below makes it modifiable;

		auto fz25 = [&offset](auto x) {
			offset += x;
		};
		fz25(45);
		std::cout << "fz 25 offset modified " << offset << std::endl;

		auto apache160 = [&](auto x) {
			std::cout << "Captured all by ref" << ++offset << std::endl;
			fz25(46);
		};
		apache160(34);

		auto apache2004v = [=](auto x) {
			std::cout << "Captured all by value " << offset << std::endl;
		};
		apache2004v(3);
		//capture list can only capture the variables which is declared above it. not below

		//opposite is also possible;
		auto apache200 = [=, &offset](auto x) {
			std::cout << "Captured all by value " << offset << std::endl;
		};
		apache200(25);
		auto atExit =
				[]() {
					std::cout
							<< "At Exit should not captre any variables! otherwise it cannot generate a c style fp"
							<< std::endl;
				};
		atexit(atExit); // coverstion to basic fp

		//capture this ptr
		std::string s1 { "name goes here" };
		Product p { s1 };
		p.AssignSomething(1000);

		// generalized capture;
		// c++ 14 feature
		std::ofstream out { "file.txt" };
		//can be used like to capture the  unique pointer inside lambda
		auto generalizedCapture = [out= std::move(out)]() mutable {
			out << "File content to be written";
		};
		generalizedCapture();
	}
}

void Lambda::Run() {
	BasicFp::Basics();
	FunctionObjects::SortWithFO();
	LambdaEx::Lambda();
}

