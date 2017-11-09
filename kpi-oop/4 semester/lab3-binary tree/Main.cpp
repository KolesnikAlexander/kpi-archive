#include <iostream>
#include "TicketSystem.h"

using namespace std;

bool negativeCondition(Node<int>* checkElem, int* measElem) {
	return *(checkElem->value) == 2 ;
}

int main() {
	TicketSystem ticketSystem;
	int inp;
	do
	{
		cout << "========================" << endl;
		cout << "Operations: " << endl;
		cout << "1. Display all" << endl;
		cout << "2. Add order" << endl;
		cout << "3. Delete order" << endl;
		cout << "4. Plane has flown (removes orders by date and flight)" << endl;
		cout << "0. Exit" << endl;
		cout << "========================" << endl;
		cin >> inp;
		string inp2;
		int inp4;
		switch (inp)
		{
		case 1:
			ticketSystem.print();
			break;
		case 2:
			cout << "\tAdd order: " << endl;
			ticketSystem.addItem();
			break;
		case 3:
			cout << "\tDelete order: " << endl;
			ticketSystem.delItem();
			break;
		case 4:
			cout << "\tPlane has flown (removes orders by date and flight): " << endl;
			ticketSystem.printAndDel();
			break;
		case 0:
			return 0;
		default:
			cout << "Wrong input" << endl;
			break;
		}
	} while (true);
	system("PAUSE");
	return 0;
}
