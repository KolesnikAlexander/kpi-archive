#include <iostream>
using namespace std;
#include "Employee.h"
#include "Manager.h"
#include "Database.h"

#define DB_FILE "db.csv"
Database db;
int addEmployee() {
	Database db;
	db.LoadFromFile(DB_FILE);
	db.ArrangeSubordinates();
	db.DisplayAll();
	Manager* man = new Manager("Alexander", "Kolesnik", 18, 20);
	man->SetDepartment("IT");
	man->SetSalary(5000000);
	db.HireEmployee(man);
	Employee* man2 = new Employee("Arnold", "Schwarzeneiger", 450, 16);
	man2->SetDepartment("Stirka noskov");
	man2->SetSalary(1.75);
	db.HireEmployee(man2);
	cout << "=======NEW LIST=======" << endl;
	db.DisplayAll();
	return 0;
}
void hireEmployeeMenu() {
	int inp;
	cout << "\t1. Employee" << endl;
	cout << "\t2. Manager" << endl;
	cout << "\tOther key to exit" << endl;
	cin >> inp;

	string f_name;
	string l_name;
	int id;
	int age;
	string department;
	int salary;
	Employee* empl1;
	Manager* manager;

	switch (inp)
	{
	case 1:
		cout << "Id: ";
		cin >> id;
		cout << "Name: ";
		cin >> f_name;
		cout << "Sirname: ";
		cin >> l_name;
		cout << "Department: ";
		cin >> department;
		cout << "Age: ";
		cin >> age;
		cout << "Salary: ";
		cin >> salary;

		empl1 = new Employee(f_name, l_name, age, id);
		empl1->SetDepartment(department);
		empl1->SetSalary(salary);
		if (db.HireEmployee(empl1) == NULL) {
			cout << "Id is not unique" << endl;
		}
		else
			cout << "Employee is hired" << endl;
		break;
	case 2:
		cout << "Id: ";
		cin >> id;
		cout << "Name: ";
		cin >> f_name;
		cout << "Sirname: ";
		cin >> l_name;
		cout << "Department: ";
		cin >> department;
		cout << "Age: ";
		cin >> age;
		cout << "Salary: ";
		cin >> salary;

		empl1 = new Manager(f_name, l_name, age, id);
		empl1->SetDepartment(department);
		empl1->SetSalary(salary);
		if (db.HireEmployee(empl1) == NULL) {
			cout << "Id is not unique" << endl;
		}
		else
			cout << "Employee is hired" << endl;
		break;
	default:
		break;
	}

}
int main() {
	
	db.LoadFromFile(DB_FILE);
	db.ArrangeSubordinates();
	int inp;
	do
	{
		cout << "========================" << endl;
		cout << "Operations: " << endl;
		cout << "1. Display all" << endl;
		cout << "2. Display department employees" << endl;
		cout << "3. Hire employee" << endl;
		cout << "4. Fire employee" << endl;
		cout << "0. Exit" << endl;
		cout << "========================" << endl;
		cin >> inp;
		string inp2;
		int inp4;
		switch (inp)
		{
		case 1:
			db.DisplayAll();
			break;
		case 2:
			cout << "\tDepartment: ";
			cin >> inp2;
			db.DisplayDepartmentEmployees(inp2);
			break;
		case 3:
			hireEmployeeMenu();
			break;
		case 4:
			cout << "Id: ";
			cin >> inp4;
			db.FireEmployee(inp4);
			break;
		case 0:
			return 0;
		default:
			cout << "Wrong input" << endl;
			break;
		}
	} while (true);

	return 0;
}
