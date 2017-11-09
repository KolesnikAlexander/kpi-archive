#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date{
public:
	int day;
	int month;
	int year;

	Date() {};
	Date(int day, int month, int year) :day(day), month(month), year(year){};
	friend ostream & operator << (ostream &out, const Date &date);

	bool operator <= (Date &date);
	bool operator == (Date &date);
};

class Ticket {

public:
	Ticket(string flight, string destination, string passangerName, Date date);
	~Ticket() {};   
	bool operator == (Ticket &ticket);
	bool operator <= (Ticket &ticket);

	friend ostream & operator << (ostream &out, const Ticket& ticket);

	string getFligh();
	Date getDate();

private:
	string flight;
	string destination;
	string passangerName;
	Date date;


	
};