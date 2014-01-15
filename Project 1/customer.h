//Project 1
// Alan Jason Chihyen
#include "std_lib_facilities_3.h"
#include "transaction.h"
//customer class includes basic information about account

class Customer{
public:
	string f_name;
	string l_name;
	int account;
	int pin;
	double balance;
	vector<Transaction> history;

Customer(string f="john",string l="doe", int a=0, int p=0, double b=0):f_name(f),l_name(l),account(a),pin(p),balance(b){}

};

ostream& operator << (ostream& os, Customer& c);

istream& operator >> (istream& is, Customer& c);