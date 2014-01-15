//Alan Achtenberg
//CSCE 113-501
//Assignment 1
//problem 4

#include "std_lib_facilities_3.h"


int fibo_int (int n){
	const int f1=1;
	const int f2=2;
	if (n==1){
		return f1;}
	if (n==2){
		return f2;}
	int i=2;
	int fib_num;
	int buffer1=f1;
	int buffer2=f2;

	while (i<n){

		fib_num=buffer1+buffer2;
		buffer1=buffer2;
		buffer2=fib_num;
		
		if (fib_num<buffer2||fib_num<0){
			cout<<"error! overflow, the "<<i<<" fibonacci number is the largest that will fit in an int and its value is "<<buffer1<<" \n";
		break;}
		++i;    
	}
	return fib_num;
}

long long fibo_ll (int n){
	const long long f1=1;
	const long long f2=2;
	if (n==1){
		return f1;}
	if (n==2){
		return f2;}
	int i=2;
	long long fib_num;
	long long buffer1=f1;
	long long buffer2=f2;

	while (i<n){

		fib_num=buffer1+buffer2;
		buffer1=buffer2;
		buffer2=fib_num;
		
		if (fib_num<buffer2||fib_num<0){
			cout<<"error! overflow, the "<<i<<" fibonacci number is the largest that will fit in a long long and its value is "<<buffer1<<" \n";
		break;}
		++i;    
	}
	return fib_num;
}


int main()
{
	
	int fib_num=0;
	cout<<"input an integer to find the nth fibonacci nummber, enter a letter to quit \n";

	while(cin>>fib_num){

		if ((fibo_int(fib_num))>0)
		cout<<fibo_int(fib_num)<<" is the "<<fib_num<<" fibonacci number.\n\n"; 
		
		// 45 is the largest fibonacci number that will fit in an int and a long type
		// its value is 1836311903
		// 91 is the largest fibonacci number that will fit in a long long type
		// its value is 7540113804746346429

	
	}
	return 0;
}