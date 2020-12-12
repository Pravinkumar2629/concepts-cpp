/*
 * Enums.cpp
 *
 *  Created on: Nov 22, 2020
 *      Author: pravinkumar
 */

#include "Enums.h"
enum Color {
	GREEN, RED, BLUE
};
enum class TrafficLights : char {
	GREEN = 'c', RED, BLUE
};

Enums::Enums() {
	std::cout << "Enums()" << std::endl;

}
void Run1(Color color) {
	if (color == RED) {
		std::cout << "RED" << std::endl;
	} else {
		std::cout << "NOT RED" << std::endl;
	}
}
void Run2(TrafficLights light) {
	if (light == TrafficLights::GREEN) {
		std::cout << "Green light" << std::endl;
	} else {
		std::cout << "Not Green light" << std::endl;
	}
}

void Enums::Run() const
{
	Run1(GREEN);
	Run2(TrafficLights::GREEN);
	std::cout << "Enums() Run" << std::endl;
	std::cout << "cast to char " << static_cast<char>(TrafficLights::RED)
			<< std::endl;
}
Enums::~Enums() {
	std::cout << "~Enums()" << std::endl;
}

