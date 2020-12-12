#include "Strings.h"
#include "Enums.h";
#include "Literals.h"

#include "Todo.h"

#include <memory>
//
//void Run(Todo const *ptr) {
//	ptr->Run();
//	delete ptr;
//	ptr = new Strings();
//	delete ptr;
//}

//void Run(Todo *ptr) {
//	atexit([]() {
//		delete ptr;
//	});
//
//	ptr->Run();
//
//}

void Run(std::unique_ptr<Todo> p) {
	p->Run();
}

int main() {
	//Strings s;
//	std::unique_ptr<Strings> p { new Strings() };
//	Run(std::move(p));
//	std::cout << std::endl;
//	std::unique_ptr<Enums> e { new Enums() };
//	Run(std::move(e));

	std::unique_ptr<Literals> l { new Literals() };
	Run(std::move(l));

}
