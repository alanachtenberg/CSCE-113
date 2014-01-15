//Project 1
// Alan Jason Chihyen

#include "bank.h"


//define meber functions of bank
double Bank::sum(){ //sum of all customers' balance
	double sum=0;
	for(int i=0;i<customers.size();++i)
		sum+=customers[i].balance;
	return sum;
}

Statistic Bank::calc_stat(){
	Statistic stat_temp;
	stat_temp.total_customer=customers.size();
	stat_temp.deposits=sum();
	stat_temp.average=stat_temp.deposits/stat_temp.total_customer;
	return stat_temp;
}

vector<Customer> Bank::read(){
	
	vector<Customer> customer_vec;

	ifstream in; // open input
	in.open("bank_info.txt");// open bank_info
	if (!in.is_open())
		cout<<"no file bank_info.txt found \n";//check for availiable file
	while(1){
		Customer temp_customer;// had to declare temp inside the loop because history vector when pushbacked keeps previous customers info
		if (!(in>>temp_customer))// breaks the loop if no customers, eof and good conditions on the while loop were adding an extra iteration
			break;
		customer_vec.push_back(temp_customer);
	}
	in.close(); // close input
	return customer_vec;
}

void Bank::write(){
	ofstream out;// open output
	out.open("bank_info.txt");
	if (!out.is_open())
		error("no file bank_info.txt found \n");//check for availiable file

	for(int i=0;i<customers.size();++i)
		out<<customers[i];
	out.close(); // close output

}

void Bank::erase(int n){
	customers.erase(customers.begin()+n);// remove customer from vector
}