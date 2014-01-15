//Alan Achtenberg
//CSCE 113-501
//Assignment 1
//problem 2

#include "std_lib_facilities_3.h"

//

string dec_to_hex(int a){
	string hex="";
	string temp;
	vector<int> remainders;
	int rem;
	if (a<1)
		throw 1;
	while (a>15){
		rem=a%16;
		a-=rem;
		a/=16;
		remainders.push_back(rem);
	}

	remainders.push_back(a);

	reverse(remainders.begin(),remainders.end());
	int i=0;

	while(i<remainders.size()){
		switch(remainders[i]){
			case 15: 
			hex=hex+"F";
			break;
			case 14:
			hex=hex+"E";
			break;
			case 13:
			hex=hex+"D";
			break;
			case 12:
			hex=hex+"C";
			break;
			case 11:
			hex=hex+"B";
			case 10:
			hex=hex+"A";
			break;
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:{
				stringstream ss;
				ss<<remainders[i];
				ss>>temp;
				hex=hex+temp;
				}
			break;
			default:
				throw 2;
		}
		++i;
	}

	return hex;
}

long long hex_to_dec(string a){
	long long dec=0;
	stringstream ss;
	ss<<a;
	vector<char>char_vec;
	char temp_char;
	int temp_int;
	while(ss>>temp_char)
		char_vec.push_back(temp_char);
	int i=0;
	reverse(char_vec.begin(),char_vec.end());
	
	while (i<char_vec.size()){
		long long int_case=0;
		double sixteen=16;
		double power=pow(sixteen,i);
	switch(char_vec[i]){
			case 'F':
			int_case=(15*power);
			break;
			case 'E':
			int_case=14*power;
			break;
			case 'D':
			int_case=13*power;
			break;
			case 'C':
			int_case=12*power;
			break;
			case 'B':
			int_case=11*power;
			case 'A':
			int_case=10*power;
			break;
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				{stringstream ss;
				ss<<char_vec[i];
				ss>>temp_int;
				int_case=temp_int*power;
				}
			break;
			default: 
			throw 3;
			break;
			
		}
	dec=dec+int_case;
	if (dec<0)
		throw 'a';
	++i;

	}
	
return dec;
}

string hex_sum(string a, string b){
	int number1=0;
	int number2=0;
	string sum;
	number1=hex_to_dec(a);
	number2=hex_to_dec(b);
	number1=number1+number2;

	sum=dec_to_hex(number1);

	return sum;
}






int main(){
	try{
	cout<<"please input a decimal integer to convert to hexadecimal\n"; //code to recieve and convert an integer into a hexadecimal number
	int number;
	cin>>number;
	string hex=dec_to_hex(number);
	string hex2;
	cout<<"your number "<<number<<" is "<<hex<<" in hexadecimal\n\n";

	cout<<"please input a hexadecimal number with char 0-9 and capital A-F to convert to a decimal integer\n"; //code to recieve and convert a hexidecimal number into a decimal number
	cin>>hex2;
	cout<<"your number "<<hex2<<" is "<<hex_to_dec(hex2)<<" in decimal\n\n";

	cout<<"please input 2 hexadecimal numbers with char 0-9 and capital A-F to find the sum\n";// the code to recieve and add two hexadecimal numbers
	cin>>hex;cin>>hex2;
	cout<<"the sum of "<<hex<<" and "<<hex2<<" is "<<hex_sum(hex,hex2)<<"\n\n";

	keep_window_open();
	}
	catch(int e){ cerr<<"incorect input";
	return 3;
	}
	catch(char) { cerr<<"error overflow number was to large for a long long type to hold\n";
	return 2;
	}
	catch(...){ cerr<<"exception occured \n";
	return 1;
	}
	return 0;
}