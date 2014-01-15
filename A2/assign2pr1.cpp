
//Alan Achtenberg
//CSCE 113-501
//Assignment 2
//Problem 1

#include "std_lib_facilities_3.h"

int main(){

	int i=0;
	char temp;
	char* first;
	char* c =new char[1000];
	first=c;//keep track of the first char of array
	cout<<"input up to 1000 characters into an array or an ! to end \n";

	while (i!=1000){
		cin>>temp;
		if (temp=='!')//character ends loop
			break;
		*c=temp;
		++c;
		++i;
		if (i==1000)// keep from going out of range
			break;
	}

	cout<<"\n your character array is ";
	int i2=0;
	while (i2!=i){
		cout<<*first;
        ++first;
        ++i2;
	}
	cout<<"\n";

	keep_window_open("q");

	return 0;
}



