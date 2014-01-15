//Alan Achtenberg
//CSCE 113-501
//Lab 4
// Part 2


#include "std_lib_facilities_3.h"

int main(){


	int* p1=new int(7);//create a pointer that points to an int of value 7
	cout<<p1<<" is the value of p1, "<<*p1<<" is the value p1 points to \n";

	int* p2=new int[7]; // create a pointer that points to 1st element of an array of size 7
	p2[0]=1;p2[1]=2;p2[2]=4;p2[3]=8;p2[4]=16;p2[5]=32;p2[6]=64; //because of the new operator
	
	cout<<p2<<" is the value of p2, ";

	for (int i=0;i<7;++i)
		 cout<<p2[i]<<" ";

	cout<<" are the values of the array \n";

	int* p3=p2;
	
	p3=p1;
	p1=p2;

	cout<<p1<<" is the value of p1, "<<*p1<<" is the value p1 points to \n";

	cout<<p2<<" is the value of p2, "<<*p2<<" is the value p2 points to \n";

	delete p3;// free memory
	delete[] p1;

	int int_array[10]={1,2,4,8,16,32,64,128,256,512};// initialize array

	p1=&int_array[0];// set p1 to point to first object in array of ints

	p2= new int[10]; // alocate array of ten ints set pointer p2 to point to first element of array

	for (int i=0;i<10;++i) // copy elements
		p2[i]=p1[i];

	delete[] p2;// delete p2 because of the new operator, p1 did not use new to create array


	vector<int>vec1(10);// repeat process with vectors

	const double power=2;// initialize vector with values that are powers of 2
	for(int i=0;i<10;++i)
		vec1[i]=pow(power,i);

	vector<int> vec2(10);

	vec2=vec1;// no need to delete vectors because the class takes care of allocation and deallocation of memory


	keep_window_open("q");

	
return 0;
}