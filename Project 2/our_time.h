/*************************************
Project #2 CSCE 113-501
Achtenberg, Alan
Stone, Jacob
Login name(s): alan76, jstone
****************************************/
/* This is our our_time.h code for Project 2 */


#include "std_lib_facilities_3.h"
#include <time.h> //for date and time operations

//---------------------------------------------------------------------------

void parse(int& m,int& d, int& y, string date){
	stringstream ss; // use ss to parse date
	ss<<date;

	stringstream con; // us con to convert temp string to int
	string temp;

	getline(ss,temp,'/');
	con<<temp;
	con>>m;
	con.clear(); //clear garbage

	getline(ss,temp,'/');
	con<<temp;
	con>>d;
	con.clear();

	getline(ss,temp,'/');
	con<<temp;
	con>>y;
}

//---------------------------------------------------------------------------

double calculate_time(string date, string p_date){
	double difference=0;

	int m=0, d=0, y=0;
	int m2=0, d2=0, y2=0;

	parse(m,d,y,date);
	parse(m2,d2,y2,p_date);
	
	time_t raw;
	time(&raw); //set raw to current time
	
	struct tm one;
	one=*localtime(&raw);//initialize one by raw time that is converted to tm thorugh localtime function
	one.tm_mon=m-1;
	one.tm_mday=d;
	one.tm_year=y+100;//because years count from 1900 add 100 to make the year 20xx
	if (y>20) //change value if year is greater than 20 because change of century
		one.tm_year=y;

	struct tm two;
	two=one;
	two.tm_mon=m2-1;
	two.tm_mday=d2;
	two.tm_year=y2+100;
	if (y2>20) //change value if year is greater than 20 because change of century
		one.tm_year=y2;
	
	raw=mktime(&one)-mktime(&two);

	raw=raw/3600;//convert seconds to hours
	raw=raw/24;//convert hours to days
	difference=raw;
	return difference;
}