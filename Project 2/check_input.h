/*************************************
Project #2 CSCE 113-501
Achtenberg, Alan
Stone, Jacob
Login name(s): alan76, jstone
****************************************/
/* This is our check_input.h code for Project 2 */

#include "std_lib_facilities_3.h"

//------------------------borrowed from textbook--------------------------------

void skip_to_int() //checks for numeric; removes alpha
{
    if (cin.fail()) {          // we found something that wasn't an integer
        cin.clear();           // we'd like to look at the characters
        char ch;
        while (cin>>ch){       // throw away non-digits
            if (isdigit(ch)) {
                cin.unget();   // put the digit back,
                // so that we can read the number
                return;
            }
        }
    }
    error("no input");         // eof or bad: give up
}


int get_int() //Takes a valid input
{
    int n = 0;
    while (true) {
        if (cin >> n) return n;
        cout << "Bad input try again: ";
        skip_to_int();
    }
}
//------------------------------------------------------------------------------

