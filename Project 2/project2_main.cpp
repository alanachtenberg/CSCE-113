/*************************************
Project #2 CSCE 113-501
Achtenberg, Alan
Stone, Jacob
Login name(s): alan76, jstone
****************************************/
/* This is our int main() code for Project 2 */

#include "std_lib_facilities_3.h"
#include "menu.h"


int main()
	try{

	ifstream in("ticket-input.dat");
	ofstream out("ticket-output.dat");
	if(!in)
		throw 1;

	vector<Ticket*> vec;	// Use vector of pointers because 
	Ticket* temp=NULL;		// you cannot create a vector of an abstract object.
	string ans;
	
	while (in>>temp)
		vec.push_back(temp);

	menu(vec);

	
    cout << "Would you like to perform another action? <y/n>: " << endl;
    cin >> ans;
    
    while((ans == "y") || (ans == "yes") ){
        menu(vec);
        cout << "Would you like to perform another action? <y/n>: " << endl;
    	cin >> ans;
    }


	for(int i=0;i<vec.size();++i){
//		cout<<vec[i]<<endl<<endl;
		out<<vec[i]<<endl;
		out<<"************************************\n";
	}
	
	keep_window_open();
	return 0;
}
catch(int){
	cout<<"error input file not found!\n";
	return 2;
}
catch(...){
	cout<<"oops! exception occured!!!\n";
	return 1;
}