#pragma once
#include "BinTree.h"
#include "Ticket.h"

#define DB_FILE_PATH "db.csv"

class TicketSystem {
public:
	TicketSystem();

	void addItem();
	void print();
	void printAndDel();
	void delItem();
	Ticket* usrInpTicket();
private:
	BinTree<Ticket>* tree;
	void loadFromFile(const char *file);
};