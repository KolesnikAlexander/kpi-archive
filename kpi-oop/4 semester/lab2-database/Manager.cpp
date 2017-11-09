#include "Employee.h"
#include "Manager.h"
#include <iostream>
#include <iomanip>
using namespace std;


Manager::Manager(const Manager &m) {
	this->f_name = m.f_name;
	this->l_name = m.l_name;
	this->age = m.age;
	this->department = m.department;
	this->salary = m.salary;
	this->id =m.id;
	this->subordinates = m.subordinates; 
}
Manager& Manager::operator=(const Manager &m){
	this->f_name = m.f_name;
	this->l_name = m.l_name;
	this->age = m.age;
	this->department = m.department;
	this->salary = m.salary;
	this->id = m.id;
	this->subordinates = m.subordinates; 
	return *this;
}
Person* Manager::AddSubordinate(Person *p) {
	subordinates.push_back(p);
	return p;
}
void Manager::DisplaySubordinates() {
	if (this->subordinates.empty()) 
	{
		cout << "No subordinates" << endl;
		return;
	}
	for (list<Person*>::iterator i = this->subordinates.begin(); i != subordinates.end(); ++i)
	{
		cout <<setw(7)<<distance(this->subordinates.begin(), i)+1<<")";
		(*i)->Display(true);
	}
	cout << endl;
}
bool Manager::deleteSubbordinate(int id) {
	Employee* employee;
	for (list<Person*>::iterator it = subordinates.begin(); it != subordinates.end(); it++) {
		employee = dynamic_cast<Employee*>(*it);
		if (employee->GetId() == id)
		{
			this->subordinates.erase(it);
			return true;
		}
	}
		return false;
}
void Manager::Display(bool withPadding) {
	Employee::Display(false);
	cout << "Subordinates: " << endl;
	// print list
	this->DisplaySubordinates();
	

}