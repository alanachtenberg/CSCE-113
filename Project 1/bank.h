//Project 1
//Alan,Jason,Chinyen


#include "std_lib_facilities_3.h"
#include "customer.h"
#include "statistics.h"

//bank class includes statistics and common members/functions

class Bank{
public:
	string name;
	vector<Customer> customers;
	Statistic stat;

	Bank(string s="bank of america"){name=s;
									 customers=read(); 
									 stat=calc_stat();}// constructer initializes customers with the return value of read and stat with return value of calc_stat
	~Bank(){write();} // define destructor to call write, saves to file upon destruction
	Statistic calc_stat();
	double sum();
	vector<Customer> read();
	void write();
	void erase(int n);
};


