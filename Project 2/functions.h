/*************************************
Project #2 CSCE 113-501
Achtenberg, Alan
Stone, Jacob
Login name(s): alan76, jstone
****************************************/
/* This is our functions.h code for Project 2 */

#include "ticket.h"
#include "check_input.h"



void access(vector<Ticket*> t,int n){
	bool found=0;
	for (int i=0;i<t.size();++i)
		if (n==t[i]->tick_num){
			found = 1;
			cout << "Ticket Found!\n";
			cout<<t[i];
		}
	if (found != 1)
		cout<<"Ticket Number Not Found!" << endl;
	cout << endl;
}

//---------------------------------------------------------------------------

void display(vector<Ticket*>& tic){
	int num=0;
	cout<<"Please Input Ticket Number to Display Information: ";
	num = get_int();
	   
	while( num < 1){
		cout << "Sorry Incorrect Input for Ticket Number, Try Again: ";
		num = get_int();
    }

		access(tic,num);
}

//---------------------------------------------------------------------------

void display_all(vector<Ticket*>& t){

	for(int i=0;i<t.size();++i){
		cout << t[i] << endl;
		cout << "****************************************************\n\n";
	}
}

//---------------------------------------------------------------------------

void stat(vector<Ticket*> t){
	int w=0,a=0,s=0; //counters for student advance and walk up ticket
	double total=0;
	for (int i=0;i<t.size();++i){
		total=total+t[i]->tick_price; //calculate total
		if(t[i]->type=="Walk Up Ticket")
			++w;
		else
			if(t[i]->type=="Advance Ticket")
			++a;
		else
			if(t[i]->type=="Student Ticket")
			++s;
	}
	cout<<"The total number of tickets are "<<t.size()<<endl;
	cout<<"The total value of the tickets is $"<<total<<endl;
	cout<<"The types of tickets are as follows \n";
	cout<<"Walk up Ticket: "<<w<<endl;
	cout<<"Advance Ticket: "<<a<<endl;
	cout<<"Student Ticket: "<<s<<endl;

}