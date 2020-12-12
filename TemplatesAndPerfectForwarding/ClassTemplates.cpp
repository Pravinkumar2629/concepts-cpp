/*
 * ClassTemplates.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: pravinkumar
 */

#include "ClassTemplates.hpp"
#include <vector>

template<typename T, int size>
class Stack {
	T m_Buffer[size] { };
	int m_Top { -1 };
public:

	Stack() = default;
	Stack(const Stack&);

	T PopV2();
	static Stack Create();
	int Top() const {
		return m_Top;
	}
	void Push(T item) {
		m_Buffer[++m_Top] = item;
	}
	T Pop() {
		return m_Buffer[m_Top--];
	}
	int IsEmpty() const {
		return m_Top == -1;
	}
};
template<typename T, int size>
Stack<T, size>::Stack(const Stack &ob) {
	m_Top = ob.m_Top;
	for (int i = 0; i <= m_Top; ++i) {
		m_Buffer[i] = ob.m_Buffer[i];
	}
}


template<typename T, int size>
T Stack<T, size>::PopV2() {
	return m_Buffer[m_Top--];
}
template<typename T, int size>
Stack<T, size> Stack<T, size>::Create() {
	return Stack<T, size>();
}

void UseStack() {
	std::cout << "Stack item start " << std::endl;
	auto s = Stack<int, 16>::Create();
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);

	auto s2(s);
	s2.Push(5);
	while (!s.IsEmpty()) {
		std::cout << "Stack item " << s.Pop() << std::endl;
	}
	std::cout << "Stack item start 2**" << std::endl;
	while (!s2.IsEmpty()) {
		std::cout << "Stack item " << s2.Pop() << std::endl;
	}
}

template<typename T, int columns>
class PrettyPrinter {
	T *m_Data;
public:
	PrettyPrinter(T *data) :
			m_Data(data) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~PrettyPrinter() {
		m_Data = nullptr;
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	T* GetData() {
		return m_Data;
	}

	void Print() {
		std::cout << "Data { " << *m_Data << " } " << std::endl;
	}
};

//Explicit specilization;
template<>
class PrettyPrinter<char*, 20> {
	char *m_Data;
public:
	PrettyPrinter(char *data) :
			m_Data(data) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~PrettyPrinter() {
		m_Data = nullptr;
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	char* GetData() {
		return m_Data;
	}

	void Print() {
		std::cout << "Data { " << m_Data << " } " << std::endl;
	}
};
template<>
void PrettyPrinter<std::vector<int>, 20>::Print() {
	std::cout << "Printing vecotr data { ";
	for (const auto &x : *m_Data) {
		std::cout << x;
	}
	std::cout << " } " << std::endl;
}
template<>
void PrettyPrinter<std::vector<std::vector<int>>, 30>::Print() {
	std::cout << "Printing vecotr data 30 { ";
	for (const auto &x : *m_Data) {

		std::cout << "\n{";
		for (const auto y : x) {
			std::cout << y;
		}
		std::cout << "} ";
	}
	std::cout << "\n} " << std::endl;
}

template<>
void PrettyPrinter<std::vector<std::vector<int>>, 20>::Print() {
	std::cout << "Printing vecotr data - 20 { ";
	for (const auto &x : *m_Data) {
		std::cout << "{";
		for (const auto y : x) {
			std::cout << y;
		}
		std::cout << "} ";
	}
	std::cout << " } " << std::endl;
}
void JustCheckingRefsOnVector(std::vector<int> &v) {
	std::cout << "****";
	for (const auto x : v) {
		std::cout << x;
	}
	std::cout << "***" << std::endl;
}

template<typename T>
class SmartPointer {
	T *ptr;
public:
	SmartPointer(T *obj) :
			ptr(obj) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	T* operator *() {
		return ptr;
	}
	T& operator ->() {
		return *ptr;
	}
	~SmartPointer() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		delete ptr;
	}
};

//Partial specialization;
template<typename T>
class SmartPointer<T[]> {
	T *ptr;
public:
	SmartPointer(T *obj) :
			ptr(obj) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	T operator[](int index) {
		return ptr[index];
	}
	~SmartPointer() {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		delete[] ptr;
	}
};

int add(int x, int y) {
	return x + y;
}

template<typename T>
T Divide(T x, T y) {
	static_assert(std::is_integral<T>::value==false, "Cannot use  integers on Divide");
	if (std::is_integral<T>::value == false) {
		return x / y;
	} else {
		std::cout << "Division needs floating point values " << std::endl;
		return x;
	}
}
template<typename T>
void RemoveRefCheck(T &&c) {
	std::cout << "is ref type " << std::is_reference<T>::value << std::endl;
	std::cout << "is ref type After removing "
			<< std::is_reference<typename std::remove_reference<T>::type>::value
			<< std::endl;
}


typedef int (*ArithmeticFn)(int, int);
using ArithmeticFnAlias = int (*)(int ,int);
typedef std::vector<std::string> Names3;

template<typename T>
using Names = std::vector<T>;

//template<typename T>
//typedef std::vector<T> Names2; //error: template declaration of ‘typedef’

void UseTypeDefsAndAlias() {
	//Names2<std::string> names; typedef not supports templatizing
	Names<std::string> namess; //where alias supports
}

void TypeTraits() {
	int i = 0;
	std::cout << std::boolalpha << "is integer "
			<< std::is_integral<int>::value
			<< std::endl;
	Divide(4.3f, 3.4f);
	RemoveRefCheck(2);
	RemoveRefCheck (i);
}

void UsePrinter() {
	int data = 3;
	PrettyPrinter<int, 20> p { &data };
	p.Print();
	int *ptr = p.GetData();
	std::cout << "from main " << *ptr << std::endl;

	char cdata[] { "Hello world" };
	PrettyPrinter<char*, 20> p2 { cdata };
	p2.Print();
	char *ptr2 = p2.GetData();
	std::cout << "from main char data - " << ptr2 << std::endl;

	std::vector<int> v { 1, 2, 3, 4, 5, 6 };
	PrettyPrinter<std::vector<int>, 20> vptr { &v };
	//Pretty printer class is oaky for an vector type, / except the print function
	//So we just have to explicitly specialize print function than the entire class like we did for char*
	vptr.Print();
	std::vector<std::vector<int>> vv { { 1, 2, 3 }, { 6, 5, 4 } };
	PrettyPrinter<std::vector<std::vector<int>>, 20> vvptr { &vv };
	vvptr.Print();
	PrettyPrinter<std::vector<std::vector<int>>, 30> vvvptr { &vv };
	vvvptr.Print();
	JustCheckingRefsOnVector(v);

}


void ClassTemplates::Run() {
	std::cout << " Arc " << sizeof(void*) << std::endl;
	//UseStack();
	//UsePrinter();
	TypeTraits();
	std::cout << "back to " << __PRETTY_FUNCTION__ << std::endl;
}

ClassTemplates::ClassTemplates() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ClassTemplates::~ClassTemplates() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
