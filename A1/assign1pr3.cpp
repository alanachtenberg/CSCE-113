//Alan Achtenberg
//CSCE 113-501
//Assignment 1
//problem 3



#include "std_lib_facilities_3.h"

int main(){

	double val1=0; // Initialize 2 double variables to zero named val1 and val2.
	double val2=0;
	cout<<"Please enter your first double value followed by your second double value.\n"; // Prompt the user for input.
	cin>> val1>>val2;

	if ( val1>val2){	// Statement that determines the smallest of the two values. If they are the same it will output val2.
		cout<<val2<<" is the smallest value.\n";}
	else{cout<<val1<<" is smallest value.\n";}
	
	
	if ( val1>val2){    // Statement that determines the smallest of the two values. If they are the same it will output val2.
		cout<<val1<<" is largest value.\n";}
	else{cout<<val2<<" is largest value.\n";}
	

	cout<< val1+val2<< " is the sum.\n"; // Statement that determines and outputs the sum.

	cout<< val1-val2<< " is the difference.\n"; // Statement that determines and outputs the difference.

	cout<< val1*val2<< " is the product.\n";  // Statement that determines and outputs the product.

	cout<< val1/val2<< " is the ratio.\n";   // Statement that determines and outputs the ratio.


	keep_window_open();


	return 0;}