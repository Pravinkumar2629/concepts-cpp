/*
 * MemoryMgmt.cpp
 *
 *  Created on: Nov 19, 2020
 *      Author: pravinkumar
 */

#include "MemoryMgmt.h"
#include "Integer.h"
#include <memory>

#include "Classes.cpp"


//-------------------------------------------------------------------Project class
class Project {
public:
	~Project() {
		std::cout << "~Project " << std::endl;
	}
};
//-------------------------------------------------------------------Employee class
class Employee {
	std::shared_ptr<Project> m_project;
public:
	void SetProject(std::shared_ptr<Project> ob) {
		m_project = ob;
	}
	std::shared_ptr<Project> GetProject(void) {
		return m_project;
	}
	~Employee() {
		std::cout << "~Employee " << std::endl;
	}
};

//-------------------------------------------------------------------Printer class
class Printer {
	std::shared_ptr<int> m_iValue { };
public:
	void SetValue(std::shared_ptr<int> ptr) {
		m_iValue = ptr;
	}

	void PrintValue() {
		std::cout << "Ref count of shared pointer " << m_iValue.use_count()
				<< std::endl;
		std::cout << "Printing value of Printer " << *m_iValue << std::endl;
//		if (m_iValue != nullptr) {
//
//		} else {
//			std::cout << "Invalid value Printer " << std::endl;
//		}
	}
};
class PrinterV2 {
	std::weak_ptr<int> m_iValue { };
public:
	void SetValue(std::weak_ptr<int> ptr) {
		m_iValue = ptr;
	}

	void PrintValue() {
		if (m_iValue.expired()) {
			std::cout << "resource is not available" << std::endl;
			return;
		}
		auto sp = m_iValue.lock();
		std::cout << "Ref count of shared pointer " << sp.use_count()
				<< std::endl;
		std::cout << "Printing value of Printer " << *sp << std::endl;
//		if (m_iValue != nullptr) {
//
//		} else {
//			std::cout << "Invalid value Printer " << std::endl;
//		}
	}
};
class EmployeeV2;

class ProjectV2 {
public:
	std::shared_ptr<EmployeeV2> m_emp;
	ProjectV2() {
		std::cout << "Project v2()" << std::endl;
	}
	~ProjectV2() {
		std::cout << "~Project v2()" << std::endl;
	}
};
class EmployeeV2 {
public:
	std::weak_ptr<ProjectV2> m_prj;
	EmployeeV2() {
		std::cout << "EmployeeV2 v2()" << std::endl;
	}
	~EmployeeV2() {
		std::cout << "~EmployeeV2 v2()" << std::endl;
	}
};
//Question on this is-> when Projet obj should get deleted;
//can't delete ono the constructor of the employee coz project is shared;
Employee* AssignProject() {

	//	Project *p = new Project();
//	Employee *e = new Employee();
//	e->SetProject(p);
//	return e;

}

std::shared_ptr<Employee> AssignProjectV2(void) {
	std::shared_ptr<Project> p { new Project() };
	std::shared_ptr<Employee> e { new Employee() };
	e->SetProject(p);
	return e;
}



void Display(Integer &p) {
	std::cout << "value of P" << p << std::endl;
}
Integer* GetIntegerObj(int value) {
	return new Integer(value);
}

void Store(std::unique_ptr<Integer> &ob) {
	std::cout << "Store func " << ob->GetValue() << std::endl;
}

void Operate(int value) {
	Integer *ob = GetIntegerObj(value);
	if (ob == nullptr) {
		ob = new Integer(value);
	}
	std::cout << "From operate " << *ob << std::endl;
	Display(*ob);
	delete ob;
	ob = nullptr;
	ob = new Integer(10);
	*ob = __LINE__;
	Display(*ob);
	delete ob;
}

void UniquePointer(void) {
	std::cout << "UniquePointer Start" << std::endl;
	std::unique_ptr<Integer> ptr { GetIntegerObj(10) };
	if (ptr == nullptr) {
		ptr.reset(new Integer(10));
	}
	ptr->SetValue(20);
	Display(*(ptr.get()));
	ptr.reset(new Integer());
	*ptr = __LINE__;
	Display(*(ptr.get()));
	Store(ptr);
	std::cout << "UniquePointer End" << std::endl;
}
void SharedPointer() {
	std::shared_ptr<Employee> emp = AssignProjectV2();
}
void WithoutWeakPointer(void) {
	std::cout << "WithoutWeakPointer  " << std::endl;
	Printer ptr;
	std::shared_ptr<int> x { new int(11) };
	ptr.SetValue(x);
	if (*x > 10) {
		std::cout << "delting ptr " << std::endl;
		x = nullptr;

		//problem is when this is deleted the  ref count still be one. and the pritner
		//class won't know that the underlyding pointer is deleted;
	}
	ptr.PrintValue();
}
void WeakPointer(void) {
	std::cout << "WeakPointer  " << std::endl;
	PrinterV2 ptr; //------------------------------------------use of Weakpointer in V2 printer
	std::shared_ptr<int> x { new int(11) };
	ptr.SetValue(x);
	if (*x > 10) {
		std::cout << "delting ptr " << std::endl;
		x = nullptr;

	}
	ptr.PrintValue();

	//////////////////////////Circular reference;

	std::shared_ptr<EmployeeV2> emp1 { new EmployeeV2() };
	std::shared_ptr<ProjectV2> prj1 { new ProjectV2() };
	emp1->m_prj = prj1;
	prj1->m_emp = emp1;

	//when on shared ptr;
	// Line 1 -> ref count of emp1 is 1
	// Line 2 -> ref count of prj1 is 1
	// Line 3 -> ref count prj1 is 2 since is assigned; copy is created;
	// line 4 -> ref count emp1 is 2 since is assigned; copy is created;
	// when scope ends; ref count is decreased by 1; and objects are not destroyed;

	//weak pointer solves this issue by;
	// marking any of the references obj as weak ptr; will make; the below;
	// consider m_prj is a weak pointer;
	// when assigning prj to m_prj; copy is not created; so prj1 ref count is 1;
	// m_emp after assignment ref count is 2; copy is created;
	// at the end of the scope;

	//prj1 ref count is 1 and emp1 ref count is 2;

	// if prj1 is deleted; it will delete the underlying memory; so prj1 will delete m_emp too;
	// so ref count of m_emp is also 1;
	// now as the scope of primary of object m_emp is ended; that will also be deleted;
	// so eventhing will be deleted;
	// that will be deleted; so

}

void MemoryMgmt::Run() {
	WithoutWeakPointer();
	std::cout << "With weak pointer " << std::endl;
	WeakPointer();
	//	Operate(100);
//	UniquePointer();
//
//	SharedPointer();

}
































MemoryMgmt::MemoryMgmt() {
	// TODO Auto-generated constructor stub

}

MemoryMgmt::~MemoryMgmt() {
	// TODO Auto-generated destructor stub
}

MemoryMgmt::MemoryMgmt(const MemoryMgmt &other) {
	// TODO Auto-generated constructor stub

}

MemoryMgmt::MemoryMgmt(MemoryMgmt &&other) {
	// TODO Auto-generated constructor stub

}

MemoryMgmt& MemoryMgmt::operator=(const MemoryMgmt &other) {
	// TODO Auto-generated method stub

}

MemoryMgmt& MemoryMgmt::operator=(MemoryMgmt &&other) {
	// TODO Auto-generated method stub

}

