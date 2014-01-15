//Alan Achtenberg
//CSCE 113-501
//Lab 4
//Part 1

#include "std_lib_facilities_3.h"

void print_array(ostream& os,int* a, int n){// add argument n that is the size of array you want to print

	for (int i=0;i<n;++i)
		os<<a[i]<<" ";
	os<<"\n";
}

void print_array10(ostream& os, int*a){

	for (int i=0;i<10;++i)
		os<<a[i]<<" ";
	os<<"\n";
}

void print_vector(ostream& os, vector<int>vec){ //function to print vector, do not need to pass in the size because of vectors member function size()
	for (int i=0;i<vec.size();++i)
		os<<vec[i]<<" ";
	os<<"\n";
}

int main(){

	int* p=new int[10];// allocate array of 10 ints and set pointer p to point to the array
	for (int i=0;i<10;++i)// output the uninitialized values of the array
		cout<<p[i]<<" ";
	cout<<"\n";
delete[] p;// deallocate the array

p= new int[10];

for (int i=0;i<10;++i)//intiaalize values to 100 101 102 ....
	p[i]=100+i;

print_array10(cout,p);

delete[] p; // dealocate array

p=new int[20]; // allocate new array of size 20

for (int i=0;i<20;++i)//intiaalize values to 100 101 102 ....
	p[i]=100+i;

print_array(cout,p,20);// use new function to print the array, arguments are ostream pointer to array and size of array

delete[] p;

//repeat 5 6 and 8 with vectors instead of arrays

vector<int>vec1(10);
for (int i=0;i<10;++i)//initialize values to 100 101 102 ...
	vec1[i]=100+i;

print_vector(cout,vec1);

vec1.push_back(110);//add value 110 to make a vector of size 11

print_vector(cout,vec1);

vector<int>vec2(20);// intialize vector of size 20 to 100 101 102 ...
for (int i=0;i<20;++i)
	vec2[i]=100+i;

print_vector(cout,vec2);

keep_window_open();
return 0;
}