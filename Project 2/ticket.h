/*************************************
Project #2 CSCE 113-501
Achtenberg, Alan
Stone, Jacob
Login name(s): alan76, jstone
****************************************/
/* This is our ticket.h code for Project 2 */

#include "std_lib_facilities_3.h"
#include "our_time.h"		// For calculation of time and date

//---------------------------------------------------------------------------

class Ticket{
public:
	string name;
	int tick_num;
	double tick_price;
	string date;
	string time;
	string p_date;
	string type;

	virtual void print(ostream& os)=0;
	
	protected:
	
	Ticket(string n="default", int tn=0, string d="00/00/00", string p="p-date", string t="time"):name(n),tick_num(tn),tick_price(0),date(d),p_date(p),time(t){}
};

//---------------------------------------------------------------------------

class Advance: public Ticket{
public:

	Advance(string n="default", int tn=0, string d="00/00/00", string p="p-date",string t="time"):Ticket(n,tn,d,p,t){
		type="Advance Ticket";
	if(calculate_time(date,p_date)>=10)//calculate price
		tick_price=30;
	else tick_price=40;
	}

	virtual void print(ostream& os){
		os<<name<<", "<<date<<" "<<time<<".\n";
		os<<type<<" Number: "<<tick_num<<".\n";
		os<<"Price: $"<<tick_price<<".\n";
	}
};

//---------------------------------------------------------------------------

class Student:public Ticket{
	public:

	Student(string n="default", int tn=0, string d="00/00/00", string p="p-type", string t="time"):Ticket(n,tn,d,p,t){
		type="Student Ticket";
		if(calculate_time(date,p_date)>=10) //calculate price
			tick_price=15;
		else 
			tick_price=20;
	}

	virtual void print(ostream& os){
		os<<name<<", "<<date<<" "<<time<<".\n";
		os<<type<<" Number: "<<tick_num<<".\n";
		os<<"Price: $"<<tick_price<<" (Student Id Required).\n";
	}
};

//---------------------------------------------------------------------------

class Walk: public Ticket{
	public:

	Walk(string n="default", int tn=0, string d="00/00/00", string p="p-type", string t="time"):Ticket(n,tn,d,p,t){
		type="Walk Up Ticket";
		tick_price=50; // ticket calculation
	}

	virtual void print(ostream& os){
		os<<name<<", "<<date<<" "<<time<<".\n";
		os<<type<<" Number: "<<tick_num<<".\n";
		os<<"Price: $"<<tick_price<<".\n";
	}
};

//---------------------------------------------------------------------------

ostream& operator<<(ostream& os, Ticket* t){
	t->print(os);
	return os;
}

istream& operator>>(istream& is, Ticket* &t){ //reference to a pointer allows function to assign existing pointer to a new value
	string name="", date, time, p_date, id; //declare temp values to determine ticket type to construct
	int tick_num;

	is.ignore(25,':');
	ws(is);//skip leading white space because of getline use
	getline(is,name,'\n'); // use get line to account for multiple word event names
	is.ignore(25,':');
	is>>date;
	is.ignore(25,':');
	getline(is,time,'\n');
	is.ignore(25,':');
	is>>p_date;
	is.ignore(25,':');
	is>>tick_num;
	is.ignore(25,':');
	is>>id;

	if (date==p_date)
		t= new Walk(name,tick_num,date,p_date,time);
	else
		if (id=="no"||id=="NO")
			t= new Advance(name,tick_num,date,p_date,time);
		else
			t= new Student(name,tick_num,date,p_date,time);
	return is;
}