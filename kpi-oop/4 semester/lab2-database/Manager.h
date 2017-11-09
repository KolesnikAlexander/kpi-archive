#pragma once
#include "Employee.h"
#include<list>
class Manager : public Employee {
public:
	Manager() {};
	Manager(string _f_name, string _l_name, int _age, int _id) :
		Employee(_f_name, _l_name, _age, _id) {};
	Manager(const Manager &m);
	Manager& operator=(const Manager &m);
	virtual void Display(bool withPAdding);
	//add an employee to the subordinates list
	Person* AddSubordinate(Person *p);
	void DisplaySubordinates();
	//Add here whatever you need
	bool deleteSubbordinate(int id);
private:
	list<Person *> subordinates;//список подчиненных
};
