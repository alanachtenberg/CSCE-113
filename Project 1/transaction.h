//Project 1
// Alan Jason Chihyen

// simple class to keep track of trasactions

#include "std_lib_facilities_3.h"

struct Transaction{
	string date;
	double amount;
	Transaction(string s="Default", double a=0):date(s),amount(a){}
};


ostream& operator << (ostream& os, Transaction& t);
istream& operator >> (istream& is, Transaction& t);