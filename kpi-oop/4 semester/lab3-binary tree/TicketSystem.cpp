#include <iostream>
#include <fstream>
#include "TicketSystem.h"
#include "BinTree.h"
using namespace std;


void TicketSystem::loadFromFile(const char *file) {
	ifstream db;
	string line;
	db.open(file);

	string destination, flight, passangerName;
	int day, month, year;

	string token;

	while (getline(db, destination, ';')) {
		getline(db, flight, ';');
		getline(db, passangerName, ';');

		getline(db, token, '.');
		day = stoi(token);

		getline(db, token, '.');
		month = stoi(token);

		getline(db, token);
		year = stoi(token);

			Ticket* ticket = new Ticket(flight, destination, passangerName, Date(day, month, year));
			tree->addItem(ticket);

	}
	db.close();
	return;
}
TicketSystem::TicketSystem() {
	this->tree = new BinTree<Ticket>;
	this->loadFromFile(DB_FILE_PATH);
}
void TicketSystem::print() {
	tree->print();
}
void TicketSystem::addItem() {
	Ticket* item = usrInpTicket();
	tree->addItem(item);
	cout << "Successfully added" << endl;
}
void TicketSystem::delItem() {
	Ticket* delItem = usrInpTicket();
	tree->delItem(delItem);
}
Ticket* TicketSystem::usrInpTicket() {
	string destination, flight, passangerName;
	int day, month, year;

	cout << "Flight: ";
	cin >> flight;

	cout << "Destination: ";
	cin >> destination;

	cout << "Passanger name: ";
	cin >> passangerName;

	cout << "Day: ";
	cin >> day;

	cout << "Month: ";
	cin >> month;

	cout << "Year: ";
	cin >> year;

	return  new Ticket(flight, destination, passangerName, Date(day, month, year));
}


Ticket* usrFlightDateInp() {
	string flight;
	int day, month, year;

	cout << "Flight: ";
	cin >> flight;

	cout << "Day: ";
	cin >> day;

	cout << "Month: ";
	cin >> month;

	cout << "Year: ";
	cin >> year;

	return  new Ticket(flight, "", "", Date(day, month, year));
}
bool flownPlaneTicket(Node<Ticket>* checkElem, Ticket* measElem) { // true if flight and flight date of both are equal
	return ((checkElem->value->getDate() == measElem->getDate()) &&
		(
			((checkElem->value->getFligh()).compare(measElem->getFligh())) == 0
		)
	);
}
void TicketSystem::printAndDel() {
	cout << "Delete tickets by flight and date" << endl;
	cout << "---------------------------" << endl;
	Ticket* ticket = usrFlightDateInp(); //ticket with data to compare
	cout << endl << "Deleted tickets: " << endl;
	tree->printAndDel(flownPlaneTicket, ticket);
	cout << "---------------------------" << endl;
}