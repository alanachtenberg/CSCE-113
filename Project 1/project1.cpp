//Project 1
// Alan Jason Chihyen
// user names alan76,jclinton, cyc2970
#include "bank_functions.h"
#include "std_lib_facilities_3.h"
//#include "Bank.h"

int main(){
	try{
		int operation=0;
		cout<<"This is your Piggy Bank. Welcome valued customer.\n";
		cout<<"Enter the number of the operation you wish to perform:\n";
		cout<<"1. Open a new accout.\n";
		cout<<"2. Close existing account.\n";
		cout<<"3. Withdraw money (up to $500).\n";
		cout<<"4. Deposit money.\n";
		cout<<"5. Account balance.\n";
		cout<<"6. List last 10 transactions.\n";
		cout<<"7. Statisical information.\n";
		cin>>operation;
		
		string f_name, l_name;
		int acn;
		int pin;
		int bal = 0;
		int n;
		Bank b("Your Piggy Bank"); // declare inside loop so that statistics and information gets saved and reinitialized
		
		switch(operation)
		{
			case 1: 	//Open new account.
			{
				open(b);
				break;
			}
			case 2:		//Close existing account.
			{
				close(b);
				break;
			}
			case 3:		//Withdraw.
			{
				n = access_account(b);
				withdrawal(b.customers[n]);
				break;
			}
			case 4:		//Deposite.
			{
				n = access_account(b);
				deposit(b.customers[n]);
				break;
			}
			case 5:		//View account balance.
			{
				n = access_account(b);
				cout<<"Your current balance is " << b.customers[n].balance << "\n";
				break;
			}
			case 6:		//List last 10 transactions.
			{
				n = access_account(b);
				display_history(b.customers[n]);
				break;
			}
			case 7:		//Statistical information.
			{
				display_stat(b);
				break;
			}
		}
		
		

		keep_window_open();

		return 0;

	}
	
	catch(Bad_format){
		cerr << "Please enter in correct format.\n";
	}

	catch(Bad_input){
		cerr << "Please enter your name with no digit or symbol.\n";
	}

	catch(Not_int){
		cerr << "Not integer, or negative integer was inputted.\n";
	}
	catch (exception& e) {
	   cerr << "error: " << e.what() << '\n'; 
	   return 1;
	}
	catch(...){
		cerr << "Exception occurred\n";
	}
}