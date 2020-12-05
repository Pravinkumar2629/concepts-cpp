/*
 * Strings.cpp
 *
 *  Created on: Nov 22, 2020
 *      Author: pravinkumar
 */

#include "Strings.h"
#include <cstring>
#include <sstream>

const char* CombineNames(const char *first, const char *last) {
	char fullName[20];
	strcpy(fullName, first);
	strcat(fullName, last);
	return fullName; //address of local vaiable being returned;
}
const char* CombineNamesV2(const char *first, const char *last) {
	char *fullName = new char[strlen(first) + strlen(last)];
	strcpy(fullName, first);
	strcat(fullName, last);
	return fullName;
}
void CStrings() {
	std::cout << "CStrings() start" << std::endl;
	char first[10];
	char lastname[10];
	std::cout << "enter first name " << std::endl;
	std::cin.getline(first, 10);
	std::cout << "enter last name " << std::endl;
	std::cin.getline(lastname, 10);
	const char *fullName = CombineNamesV2(first, lastname);
	std::cout << "CStrings() end 1" << std::endl;
	std::cout << "CStrings() end " << fullName << std::endl;
	std::cout << "CStrings() end 2" << std::endl;
	delete[] fullName;
}
void CppStrings() {
	std::string s1 = "Hello";
	std::string s2 { "world" };

	std::string s3 = s1 + s2;

	std::string s4 { };
	s4 += s3;
	s4.insert(3, s1);
	s4.length();
	if (s4 != s3) {
		if (s3 > s2) {

		}
	}
	s3.erase(0, 4);
	s3.clear();
	s1.empty();
	auto pos = s2.find("world", 2);
	if (pos != std::string::npos) {
		std::cout << " hello " << std::endl;
	}
	s2.find("world 2", 0);

	using namespace std;
	string s5;
	string s6;
	std::cout << "Input s5" << std::endl;
	getline(cin, s5);
	std::cout << "Input s6" << std::endl;
	getline(cin, s6);

	printf("%s", s5.c_str());

	unsigned int x = 100u;
	using namespace std::string_literals;
	auto s7 = "hari"s;
}

void StringStreams() {
	using namespace std::string_literals;
	using namespace std;
	stringstream ss;
	//istringstream iss;
	//ostringstream oss;

	ss << "Hello " << "boy" << "& this is a name "
			<< "you can even use l values here" << std::endl;

	cout << "sstream after formatting " << ss.str();

	auto data = "20 10 21 25 27"s;
	ss.str(data);
	int i;
	std::cout << "going to extract data" << std::endl;
	while (ss >> i) {  // ss.fail () will write the last element twise
		std::cout << i << std::endl;
	}
	ss.clear();

	//ss.seekg(0, std::stringstream::end);
	ss.str(data);
	//ss.seekp(0, std::stringstream::beg);
	cout << "Gonna read again" << endl;
	do {
		ss >> i;
		std::cout << i << std::endl;
	} while (!ss.fail()); /// not working;

	string s = "43";
	auto xx = stoi(s);
	std::cout << std::endl;
}
void Strings::Run() const {
	std::cout << "Strings Run()" << std::endl;
	//CStrings();

	//CppStrings();

	StringStreams();

	std::cout << "Strings Run() end" << std::endl;
}

Strings::Strings() {
	std::cout << "Strings()" << std::endl;
}

Strings::~Strings() {
	std::cout << "~Strings()" << std::endl;
}

