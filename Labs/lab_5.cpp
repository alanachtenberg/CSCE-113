//Alan Achtenberg
//CSCE 113
//Lab 5


#include "std_lib_facilities_3.h"

void print_array(int* n, int size){
	while (size>0){
		cout<<*n<<" ";
		--size;
		++n;
	}
	cout<< endl;
}

struct my_exception{
	string msg;
	my_exception(const string& s):msg(s){}
};

int input_age()
try {
	int age;
	cout<<"Please input your age \n";
	if (cin>> age){
	if (age<1)
		throw my_exception("impossible! age must be greater than 0 \n");
	if (age>120)
		throw my_exception("impossible! you cant be that old! age must be less than 120 \n");

	return age;
	}
	throw 1;
}
catch (my_exception& ae){ cout<<ae.msg;}


int input_ssn()
try {
	int ssn;
	cout<<"Please input your 9 digit social security number \n";
	if (cin>>ssn){

	int number=ssn;
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
	 if (digits!=9)
		throw my_exception("error ssn must be 9 digits long \n");
	return ssn;
	}
	throw 1;

}
catch (my_exception& se){ cout<<se.msg; keep_window_open();}





int main()
	try{

		int i=0;
		int age[5]={};
		int ssn[5]={};
		char t=0;
		
		while(1){
			cout<<"input q to quit, input any other char add age and ssn entry\n";
			cin>>t;
			if (t=='q')
			break;
			if (i==5)
				throw my_exception("oops can only accept up to 5 ages and ssn \n");
			age[i]=input_age();
			ssn[i]=input_ssn();
			++i;
		}
		print_array(age,5);
		print_array(ssn,5);

		keep_window_open();
	return 0;
}

catch(my_exception & e){cout<<e.msg; return 3;}

catch(int) {cout<<"error input was not of type int \n"; return 2;}

catch(...){cout<< "exception occured!\n"; return 1;}

