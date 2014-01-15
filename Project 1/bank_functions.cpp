//Project 1
// Alan Jason Chihyen
#include "bank_functions.h"


void check_format(string date){
	if(!isdigit(date[0])||!isdigit(date[1])||date[2]!='/'||!isdigit(date[3])||!isdigit(date[4])||date[5]!='/'||!isdigit(date[6])||!isdigit(date[7])) throw Bad_format();
}

void check_int(int a){
	if(!a/1) throw Not_int();
}
void check_name(string name){
	for(int i = 0; i<name.size();i++){
		if(!isalpha(name[i])) throw Bad_input();
	}
}

int access_account(Bank& b){ 
	int acn;
	int p;
	int found=-1;
	while(1){
		cout<<"please input your account number followed by your pin\n"; // find corresponding int to access account in customers vector
		cin>>acn>>p;
		check_int(acn);
		check_int(p);
		// if(cin.fail()) throw Not_int();
		for (int i=0;i<b.customers.size();++i){
			if (b.customers[i].account==acn)
				found=i;
		}
		if (found<0)
			cout<<"error: account number not found"<<endl;
		else {
			if (b.customers[found].pin!=p)
				cout<<"error: pin number incorrect"<<endl;
			else return found;
		}
		cout<<"try again\n";
		found=-1;
	}
}

void record_t(Customer& c,Transaction t){
	c.history.push_back(t);
	if (c.history.size()==11)
		c.history.erase(c.history.begin());
}

int four_generate(){
	int p=rand()%9000+1000;
	return p;
}

int generate(const Bank& b){
	int new_account=rand();
	for (int i=0;i<b.customers.size();++i) // check every existing customer
		while (new_account==b.customers[i].account) // if they have the same account number
			new_account=rand(); // retry random int
	return new_account;
}
Transaction withdrawal(Customer& c){
	Transaction t;
	double initial=c.balance;
	while(1){
		cout<< "Hi! " <<c.f_name<<" "<<c.l_name<<","<<endl;
		cout<<"Please input today's date in the format 02/26/13 with no spaces\n";
		cin>>t.date;
		check_format(t.date);
		cout<<"Please enter the ammount you wish to withdraw up to $500, if your withdrawal leaves your account balance less than 1000 there will be a $10 fee\n";
		cin>>t.amount;
		check_int(t.amount);
		if (initial-t.amount>=60&&t.amount<501){

			t.amount*=-1;
			c.balance=c.balance+t.amount;// subtract withdraw from balance
			record_t(c,t);
			if(c.balance<1000 && c.balance>50){
				cout<<"your withdrawal instantiates a 10 dollar fee because your balance is less than 1000\n";
				c.balance-=10;
			cout<<"Your current balance is "<<c.balance<<endl;
			return t;
			}
			else cout<<"Your current balance is "<<c.balance<<endl;
			return t;
		}
		if(t.amount>=500) {
			cout<<"You can only withdraw up to $500.\n";
		}
		else{
		cout<<"Error cannot overdraw account, account balance must be at least 50 after withdrawal and the";
		cout<<" $10 fee to avoid closing account, to withdraw all of the balance will require you to close your account\n";
		}
	}
}
Transaction deposit(Customer& c){
	Transaction t;
	if(c.balance!=0)
	{}// insert a Fee function
	cout<< "Hi! " <<c.f_name<<" "<<c.l_name<<","<<endl;
	cout<<"please input todays date in the format 02/26/13 with no spaces\n";
	cin>>t.date;
	check_format(t.date);
	cout<<"please input the ammount you wish to deposit\n";
	cin>>t.amount;
	check_int(t.amount);

	c.balance=c.balance+t.amount;// add deposit to balance
	cout<<"Your current account balance is "<<c.balance;
	record_t(c,t);
	return t;
}

void open(Bank& b){
	Customer new_customer;
	Transaction t;
	cout<<"To open account you must deposit at least $1000.\n"
		<<"please input your first and then last name\n";
	cin>>new_customer.f_name;
	cin>>new_customer.l_name;
	check_name(new_customer.f_name);
	check_name(new_customer.l_name);
	new_customer.account=generate(b);
	cout<<"Your new account number is "<<new_customer.account<<"\n";
	new_customer.pin=four_generate();
	cout<<"Your new PIN is "<<new_customer.pin<<"\n";
	t=deposit(new_customer);
	while (t.amount<1000){
		cout<<"deposit amount must be greater than or equal to 1000 please try again \n";
			new_customer.balance=0;// reset balance to zero
			new_customer.history.pop_back();//remove transaction from history
		t=deposit(new_customer);
	}
	b.customers.push_back(new_customer);
	cout<<"Thank you for opening an account with us.\n Your account information is as follows\n";
	cout<<new_customer;
}

void close(Bank& b){
	char confirm = 'a';
	cout << "Are you sure you want to close your account?(y/n)\n";
	cin >> confirm;
	if(confirm == 'y'){
		int n=access_account(b);
		if(b.customers[n].balance<500){
		cout<<"your account has been closed and you will recieve the ammount of "<<b.customers[n].balance<<" dollars\n";
		}
		else cout << "your account has been closed, Please see the cashier to receive your money.\n";
		b.erase(n);
	}
}


Statistic display_stat(Bank& b){
	cout<<b.name<<" has "<<b.stat.total_customer<<" customer accounts\n";
	cout<<"with a total deposit value of "<<b.stat.deposits<<endl;
	cout<<"and an average account balance of "<<b.stat.average<<endl;

	return b.stat;
}

vector<Transaction> display_history(Customer& c){
	cout<<"your transaction history is as follows "<<endl;
	for (int i=0;i<c.history.size();++i)
		cout<<c.history[i]<<endl;
	return c.history;
}


