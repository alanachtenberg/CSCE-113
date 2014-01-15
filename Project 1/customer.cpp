//Project 1
// Alan Jason Chihyen
#include "std_lib_facilities_3.h"
#include "customer.h"


//define input and output operators for customer

ostream& operator << (ostream& os, Customer& c){
	os<<"[ customer "<<c.f_name<<" "<<c.l_name<<endl;
	os<<"  Account# "<<c.account<<endl;
	os<<"  PIN "<<c.pin<<endl;
	os<<"  Balance "<<c.balance<<endl;
	os<<"  Transactions { ";
	for(int i=0;i<c.history.size();++i) // history is a vector of transaction
		os<<c.history[i];
		return os<<"} ]\n";
}


istream& operator >> (istream& is, Customer& c){ //dont understand....(?)
	is.ignore(30,'r');
	is>>c.f_name>>c.l_name;
	is.ignore(30,'#');
	is>>c.account;
	is.ignore(30,'N');
	is>>c.pin;
	is.ignore(30,'e');
	is>>c.balance;
	is.ignore(40,'{');
	Transaction temp;
	char test=0;
	is>>test;
	while(test=='('){
		is.putback('(');
		is>>temp;
		c.history.push_back(temp);
		is>>test;
	}

	is.ignore(30,']');
	return is;
}
