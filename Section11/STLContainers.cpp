/*
 * STLContainers.cpp
 *
 *  Created on: Nov 30, 2020
 *      Author: pravinkumar
 */

#include "STLContainers.h"

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <functional>

STLContainers::~STLContainers() {
	std::cout << "STLContainers::~STLContainers() " << std::endl;
}

void Test(int *arr) {
	std::cout << "Just testing if we could pass std::array to static c array "
			<< std::endl;
}

//use set if you want to search quickly
void StdSetAndMultiset() {
	/*
	 * implemeted as binary tree
	 * elements are stored in sorted order; <&>
	 * values act as a key; when searching / deleting; uses this value to find the position;
	 * Fast search;
	 * No random access;
	 * Elements cannot be modified directly;
	 * */

	std::set<int> _set { 1, 7, 3, 6, 5, 2, 0 };
	_set.insert(4);
	_set.insert(9);
	_set.insert(9); // set will not allow duplicate;

	_set.erase(5); // erases the value 5 ?? NOT THE INDEX;
	_set.erase(_set.begin());
	
	
	 /**
	 *  Returns a read-only (constant) iterator that points to the first
	 *  element in the %set.  Iteration is done in ascending order according
	 *  to the keys.
	 */
	auto itr = _set.begin();
	while (itr != _set.end()) {
		std::cout << "Printing set elements " << *itr++ << std::endl;
	}

	auto itr = _set.find(6);
	if (itr != _set.end()) {
		std::cout << "Found element in set " << *itr << std::endl;
	}
	
	std::multiset<int, std::greater<int>> _multiset { 1, 3, 4, 5, 6, 62, 12, 20,
			47 };
	_multiset.insert(47);
	_multiset.insert(47);
	_multiset.insert(47); //_multiset allow duplicates;

	//if you want to find multiple occurances in multiset; then use equal_range function;

	auto pair_found = _multiset.equal_range(47);
	while (pair_found.first != pair_found.second) {
		std::cout << "Element found " << pair_found.first++ << std::endl;
	}
}


void StdList() {
	/*
	 * List is implemented as two way linked list
	 * efficient for insertion/deletion anywhere in the list;
	 * Does NOT provide random access;
	 * */

	std::list<int> l { 1, 2, 3, 4 };
	for (int i = 0; i < 20; ++i) {
		std::cout << " and size of list is " << l.size() << std::endl;
		l.push_back(i + 5);
	}
	for (auto x : l) {
		std::cout << "Printing list elements " << x << std::endl;
	}

	auto itr = l.begin();
	l.insert(itr, 100);
	l.erase(++itr);
	std::cout << "Printing AGAIN" << std::endl;
	for (auto x : l) {
		std::cout << "Printing list elements " << x << std::endl;
	}
}

void StdForwardList() {
	/*
	 * one way linked list;
	 * does not provide random access;
	 * small memeory foot print
	 * good for insertion and deletion;
	 * does not provide support for size;
	 * inserts at front ; uses push_front()
	 **
	 * */

	std::forward_list<int> fl;
	for (int i = 0; i < 10; ++i)
		fl.push_front(i);
	auto itr = fl.begin();
	fl.insert_after(itr, 1002);
	fl.erase_after(fl.before_begin());
	for (auto item : fl) {
		std::cout << "Printing Forward list items " << item << std::endl;
	}
}
void StdDeque() {
	/*
	 * Deque is the short form double ended queue;
	 * Efficient for addition and removal at the ends;
	 * Not good for insertion and deletion;
	 * Provides random access;
	 * Grows automatically;
	 * */
	std::deque<int> deq { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; ++i) {
		deq.push_back(i + 6);
	}
	for (int i = 0; i < 5; ++i) {
		deq.push_front(i);
	}
	auto itr = deq.begin();
	loop: if (itr != deq.end()) {
		std::cout << "Printing elements from deque " << *itr++ << std::endl; // never forgot to increment the iterator
		goto loop;
	}
	std::cout << "Just left the Deque loop " << std::endl;

	deq.pop_back(); // shoudl remove 10;
	deq.pop_front(); //should remove 4; as index starts from 0 the last element would be 4 in front;
	//deq.erase(deq.end()); //DANGEROUS Code; deq.end() iterator points to a unknown address(beyond the deque's last element)
	// so should not directly access end() iterator; or de-reference
	deq.erase(deq.end() - 1); // erases the last element; //shoudl erase 9
	std::cout << "Should be 8 " << deq.back() << std::endl; // retrieves the last element // right side (back);
	std::cout << "clearing all the elements form dequeu " << std::endl;
	deq.clear(); //clears all the elements
}

void StdVector() {
	/*
	 * std::vector behaves like a dynamic array - grows automatically;
	 * so no need to worry about the size;
	 * Provides random access;
	 * Not good for insertion and deletion at random position;
	 * Good for addition and removal at the end;
	 * *
	 * */
	std::vector<int> v { 1, 2, 3, 4, 5 };
	for (int i = 0; i < 15; ++i) {
		v.push_back(i);
		std::cout << "size of vector is " << v.size() << " and last item is "
				<< v.back() << "front item is " << v[i] << std::endl;
	}

	//Provides subscript operator;
	v[3] = 99;
	auto itr = v.begin();
	while (itr != v.end()) {
		std::cout << "Printing element using itr " << *itr++;
	}
	//we can use foreach on it too;

	for (auto x : v) {
		std::cout << "Print element using foreach " << x;
	}
	std::cout << "Reoving the vector elements " << std::endl;
	while (v.size() != 0) {
		v.pop_back();
	}
}

void StdArray() {
	/*
	 * std::array cannot grow
	 * supports old c style static array ( function data())
	 * provides size() function to retrieve the size of the array
	 * support for std::begin() and std::end;
	 * which in turns tell us that iterator are also supported;
	 * *
	 * */
	std::array<int, 5> arr { 1, 2, 3, 4, 5 };
	for (long unsigned int i = 0; i <= arr.size(); ++i) {
		arr[i] = i;
	}
	auto itr = arr.begin();
	loop: if (itr != arr.end()) {
		std::cout << "iterator in st:;array " << *itr++ << std::endl;
		goto loop;
	} else {
		std::cout << "Left the goto loop " << std::endl;
	}
	for (auto x : arr) {
		std::cout << "Printing x" << x << std::endl;
	}
	Test(arr.data());
}

void SequenceContainers() {
	StdArray();
	StdVector();
	StdDeque();
	StdList();
	StdForwardList();
}

void AssociativeContainers() {
	StdSetAndMultiset();
}

void STLContainers::Run() {
	SequenceContainers();
	AssociativeContainers();
}
