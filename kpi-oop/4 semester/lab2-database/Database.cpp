#include "Database.h"
#include "Employee.h"
#include "Manager.h"
#include <fstream>
#include <iostream>

using namespace std;

#define ASSIST_FILE_PATH "assistant.csv"

bool Database::LoadFromFile(const char *file) {
	ifstream db;
	string line;
	db.open(file);
	this->file = file;
	int personType;

	string f_name, l_name;
	int age;

	string department;
	int salary;
	int id;

	string token;

	while (getline(db, token, ';')) {
	personType = stoi(token);
	getline(db, token, ';');
	id = stoi(token);
	getline(db, f_name, ';');
	getline(db, l_name, ';');
	getline(db, token, ';');
	age = stoi(token);
	getline(db, department, ';');
	getline(db, token);
	salary = stoi(token);

	// To do: Change next verifications:

	if (personType == 0)
	{
		Employee* employee = new Employee(f_name, l_name, age, id);
		employee->SetSalary(salary);
		employee->SetDepartment(department);
		employees.push_back(employee);
	}
	if (personType == 1)
	{
		Manager* manager = new Manager(f_name, l_name, age, id);
		manager->SetDepartment(department);
		manager->SetSalary(salary);
		employees.push_back(manager);
	}
	
}
	db.close();
	return true;
}
void Database::DisplayAll() {
	if (employees.empty())
		cout << "No employees" << endl;
		for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++)
		{
			(*it)->Display(false);
		}
}
void Database::ArrangeSubordinates() {
	list<Manager*> managers;
	vector<Person*>::iterator it = employees.begin();
	for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++) {
		if (typeid(**it) == typeid(Manager)) {//manager
			managers.push_back(dynamic_cast<Manager*>(*it));
		}
	}


	for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++)
	{
		if (typeid(**it) == typeid(Employee)) {//employee
			string dept = dynamic_cast<Employee*>(*it)->GetDepartment();
			for (list<Manager*>::iterator manIt = managers.begin(); manIt != managers.end(); manIt++)
			{
				if (!dept.compare((*manIt)->GetDepartment())) {
					(*manIt)->AddSubordinate(*it);
				}
			}
		}
	}
}
void Database::DisplayDepartmentEmployees(string _department) {
	string dept;
	bool found = false;
	for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++)
	{
		dept = dynamic_cast<Employee*>(*it)->GetDepartment();
		if (dept == _department) {
			(*it)->Display(false);
			found = true;
		}
			
	}
	if (!found)
	{
		cout << "\tNo employees found" << endl;
	}
}
void writePersonToFile(Person *p, string file) {
	ofstream output;
	output.open(file, std::ios_base::app);
	if (typeid(*p) == typeid(Employee)) {
		output << endl;
		output << 0 << ";";
		Employee* empl = dynamic_cast<Employee*>(p);
		output << empl->GetId() << ";";
		output << empl->getF_name() << ";";
		output << empl->getL_name() << ";";
		output << empl->getAge() << ";";
		output << empl->GetDepartment() << ";";
		output << empl->getSalary();
	}
		
	
	else if (typeid(*p) == typeid(Manager)) {
		output << endl;
		output <<"1;";
		
		Manager* empl = dynamic_cast<Manager*>(p);
		output << empl->GetId() << ";";
		output << empl->getF_name() << ";";
		
		output << empl->getL_name() << ";";
		output << empl->getAge() << ";";
		output << empl->GetDepartment() << ";";
		output << empl->getSalary();
		
	}

	else
	{
		cout << "Cannot write to database " << endl;
		return;
	}

	output.close();
	return;
}
bool idIsUnique(int id, Database* db) {
	for (vector<Person*>::iterator it = db->getEmployees().begin(); it != db->getEmployees().end(); it++) {
		if (typeid(**it) == typeid(Employee)) {//Employee
			Employee* empl = dynamic_cast<Employee*>(*it);
			if (empl->GetId() == id)
				return false;
		}
		else if (typeid(**it) == typeid(Manager)) {//manager
			Manager* manager = dynamic_cast<Manager*>(*it);
			if (manager->GetId() == id) 
				return false;
		}
	}
	return true;
}
Person* Database::HireEmployee(Person *p){
	
		if (typeid(*p) == typeid(Employee))
		{
			
			Employee* empl = dynamic_cast<Employee*>(p);
			if (!idIsUnique(empl->GetId(), this))
				return NULL;
			employees.push_back(p);
			//lokoking for managers
			list<Manager*> managers;
			vector<Person*>::iterator it = employees.begin();
			for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++) {
				if (typeid(**it) == typeid(Manager)) {//manager
					managers.push_back(dynamic_cast<Manager*>(*it));
				}
			}
			//check whether employee belongs to some manager
			string dept = empl->GetDepartment();
			for (list<Manager*>::iterator manIt = managers.begin(); manIt != managers.end(); manIt++)
			{
				if (!dept.compare((*manIt)->GetDepartment())) {
					(*manIt)->AddSubordinate(empl);//New subbordinate added to manager
				}
			}


		}
		else if (typeid(*p) == typeid(Manager))
		{
			
			Manager* man = dynamic_cast<Manager*>(p);
			if (!idIsUnique(man->GetId(), this))
			return NULL;
			employees.push_back(p);
			string dept = man->GetDepartment();
			for (vector<Person*>::iterator it = employees.begin(); it != employees.end(); it++) {
				if (typeid(**it) == typeid(Employee)&&
					!dept.compare(dynamic_cast<Employee*>(*it)->GetDepartment())) {//depatments match
					man->AddSubordinate(*it);//subbordinate added to the new manager
				}
			}
		}
		writePersonToFile(p, this->file); //write to database file
		return p;

}
Person* getPersonById(int id, Database* db) {
	Person* foundEmpl = NULL;
	
	for (vector<Person*>::iterator it = db->getEmployees().begin(); it != db->getEmployees().end(); it++) {
		if (typeid(**it) == typeid(Employee)) {//Employee
			Employee* empl = dynamic_cast<Employee*>(*it);
			if (empl->GetId() == id) {
				foundEmpl = *it;
			}
		}
		else if (typeid(**it) == typeid(Manager)) {//manager
			Manager* manager = dynamic_cast<Manager*>(*it);
			if (manager->GetId() == id) {
				foundEmpl = *it;
			}
		}
		
	}
	return foundEmpl;
}
bool deletefromEmplList(int id, Database* db) {
	for (vector<Person*>::iterator it = db->getEmployees().begin(); it != db->getEmployees().end(); it++) {
		if (typeid(**it) == typeid(Employee)) {//Employee
			Employee* empl = dynamic_cast<Employee*>(*it);
			if (empl->GetId() == id) {
				delete *it;
				db->getEmployees().erase(it);
				return true;
			}
		}
		else if (typeid(**it) == typeid(Manager)) {//manager
			Manager* manager = dynamic_cast<Manager*>(*it);
			if (manager->GetId() == id) {
				delete *it; 
				db->getEmployees().erase(it);
				return true;
			}
		}
	}
	return false;
}

void deletefromSuubordinates(int id, Database* db) {
	list<Manager*> managers;
	for (vector<Person*>::iterator it = db->getEmployees().begin(); it != db->getEmployees().end(); it++) {
		if (typeid(**it) == typeid(Manager)) {//manager
			dynamic_cast<Manager*>(*it)->deleteSubbordinate(id);
		}
	}
}
int stringNumber(int delId, string file) {
	fstream fs;
	fs.open(file);
	string token;
	string fullLine = "";
	int id;
	int counter = -1;

	while (getline(fs, token, ';')) {
		counter++;
		fullLine = "";
		fullLine += token;
		getline(fs, token, ';');
		fullLine += token;
		id = stoi(token);
		if (id == delId) {
			getline(fs, token);
			fullLine += token;
			return counter;
		}
		getline(fs, token);
	}
	return -1;
}
void writeBackToDbFile(string file, int n) {
	fstream fs;
	fs.open(file, std::ios::out);// file overwriting

	fstream assistFile;
	assistFile.open(ASSIST_FILE_PATH); 
	string token;

	for (int i = 0; i <= n; i++) {
		if (i == n) {
			getline(assistFile, token);
			fs << token;
		}
		else
		{
			getline(assistFile, token);
			fs << token << "\n";
		}
		
	}
	
	//cout << token;
}
void delStr(string file, int n){
	fstream fs;
	fs.open(file);

	fstream assistFile;
	assistFile.open(ASSIST_FILE_PATH, std::ios::out); // file overwriting
	string token;
	

	for (int i = 0; i < n; i++) { //reading before string to delete
		std::getline(fs, token);
		assistFile << token << "\n" ;
	}
	//skipping string
	std::getline(fs, token);
	cout << token;
	//reading after the string to delete
	int lineCounter = n;
	while (getline(fs, token)) {
		assistFile << token << "\n";
		n++;
	}
	fs.close();
	assistFile.close();
	writeBackToDbFile(file, n-1);
}
void deleteFromFile(int delId, string file) {
	int strToDel = stringNumber(delId, file);
	delStr(file, strToDel);

	
}
bool Database::FireEmployee(int id) {
	
	Person* foundEmpl = getPersonById(id, this);
	if (foundEmpl == NULL) {
		cout << "No such employee" << endl;
		return false;
	}
		
	else
	{
		cout << "Delete this person? (1 - yes): " << endl;
		foundEmpl->Display(false);
		cout << "=============" << endl;
		int inp;
		cin >> inp;
		switch (inp)
		{
		case 1:
			//nop
			break;
		default:
			return false;
			break;
		}
		
		deletefromSuubordinates(id, this);
		deletefromEmplList(id, this);
		deleteFromFile(id, this->file);
		cout << "Successfully deleted" << endl;
	}
	return true;

}