/*************************************
Project #2 CSCE 113-501
Achtenberg, Alan
Stone, Jacob
Login name(s): alan76, jstone
****************************************/
/* This is our menu.h code for Project 2 */

#include "std_lib_facilities_3.h"
//#include "check_input.h"
#include "functions.h"

//--------------------------------------------------------------------------

void menu(vector<Ticket*> t){

    int ans;

cout << "********************************************************\n";
	cout << "Welcome to the TAMU Simple Ticket Management System.\n";
	cout << "Please select one of the follow operations: \n";
	cout << "********************************************************\n\n";

	cout << "	" << "1. Find a Ticket by it's Number. \n";
	cout << "	" << "2. View a Record of all Sold Tickets. \n";
	cout << "	" << "3. View Statistical Information of Tickets Sold. \n";

	cout << endl;
	cout << "Please enter the corresponding number for desired operation: ";
	ans = get_int();
	   
	while( ans < 1 || ans > 3){
		cout << "Bad input try again: ";
		ans = get_int();
    }

//---------------------------------------------------------------------------
    
	switch(ans){
		case 1:
			cout << "\nYou have chosen to Find a Ticket by it's Number.\n";
			display(t);
            break;
        case 2:
			cout << "\nYou have chosen to View a Record of all Sold Tickets.\n"; 
            display_all(t);
            break;
        case 3:
			cout << "\nYou have chosen to View Statistical Information "
				<< "of all Tickets Sold.\n"; 
			stat(t);
            break;

	}
	

}
