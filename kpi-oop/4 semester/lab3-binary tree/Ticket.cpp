#include "Ticket.h"
#include <iostream>
#include "Node.h"

using namespace std;
Ticket::Ticket(string flight, string destination, string passangerName, Date date) {
	this->flight = flight;
	this->destination = destination;
	this->passangerName = passangerName;
	this->date = date;

}
ostream & operator << (ostream &out, const Date &date)
{
	out << date.day << "." << date.month << "." << date.year;
	return out;
}
string Ticket::getFligh() {
	return this->flight;
}
Date Ticket::getDate() {
	return this->date;
}
ostream & operator << (ostream &out, const Ticket &ticket)
{
	out << ticket.flight << endl;
	out << ticket.destination << endl;
	out << ticket.passangerName << endl;
	out << ticket.date << endl;
	return out;
}
bool Ticket::operator <= (Ticket &ticket) {
	return ((this->passangerName).compare(ticket.passangerName) <= 0);
}
bool Date::operator <= (Date &date) {
	return ((this->day == date.day) &&
		(this->month == date.month) &&
		(this->year == date.year));
}
bool Date::operator == (Date &date) {
	return ((this->day == date.day) &&
		(this->month == date.month) &&
		(this->year == date.year));
}
bool equalFlightAndDate(Node<Ticket>* checkElem) {
	return true;
}
bool Ticket::operator == (Ticket &ticket) {
	return ((this->date == ticket.date)&&
		((this->destination).compare(ticket.destination) == 0)&&
		((this->flight).compare(ticket.flight) == 0) &&
		((this->passangerName).compare(ticket.passangerName) == 0)
		);
}