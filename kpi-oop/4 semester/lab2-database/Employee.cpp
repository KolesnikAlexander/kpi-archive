#include "Employee.h"
#include <iostream>
#include "Manager.h"
using namespace std;

void Employee::Display(bool withPadding) {
	cout << endl;
	if (withPadding) cout << "\t";
	cout << "Employment type: ";
	if (typeid(*this) == typeid(Employee))
		cout << "employee" << endl;
	else if (typeid(*this) == typeid(Manager)) 
		cout << "manager" << endl;
	else
		cout << "unknown";
	
	if (withPadding) cout << "\t";
	cout <<"Id: " << this->id << endl;
	if (withPadding) cout << "\t";
	cout << "Name: " << this->f_name << endl;
	if (withPadding) cout << "\t";
	cout << "Sirname: " << this->l_name << endl;
	if (withPadding) cout << "\t";
	cout << "Department: " << this->department << endl;
	if (withPadding) cout << "\t";
	cout << "Age: "<< this->age << endl;
	if (withPadding) cout << "\t";
	cout << "Salary: " << this->salary<<endl;
	
}
Employee::Employee(const Employee &e)
{
	this->f_name = e.f_name;
	this->l_name = e.l_name;
	this->age = e.age;
	this->department = e.department;
	this->salary = e.salary;
	this->id = e.id;
}
Employee& Employee::operator=(const Employee &e) {
	this->f_name = e.f_name;
	this->l_name = e.l_name;
	this->age = e.age;
	this->department = e.department;
	this->salary = e.salary;
	this->id = e.id;

	return *this;
}
void Employee::SetSalary(int s) {
	this->salary = s;
}
void Employee::SetDepartment(string dept) {
	this->department = dept;
}
void Employee::SetId(int n) {
	this->id = n;
}
int Employee::GetId() {
	return this->id;
}
string Employee::GetDepartment() {
	return this->department;
}
string Employee::getF_name() {
	return this->f_name;
}
string Employee::getL_name() {
	return this->l_name;
}
int Employee::getAge() {
	return this->age;
}
int Employee::getSalary() {
	return this->salary;
}