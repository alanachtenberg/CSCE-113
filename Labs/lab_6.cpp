//Alan Achtenberg
//CSCE113-501
//Lab 6


#include "std_lib_facilities_3.h"

/*

Write a program that reads from the raw_temps.txt into a vector. (the raw_temps data is in fahrenehit) 
Please update this temperature as celcius and update this information on the raw_temps.txt in the following format:

original format in raw_temps.txt:

hour temp_F
hour temp_F
.....

updated format for raw_temps.txt:

hour temp_F temp_C
hour temp_F temp_C
.....

*note-the raw_temps.txt will contain 24 hours (0-23hrs) worth of temperature readings



Please use and modify the struct Reading to accomodate for celcius temperatures 
*/
struct Reading{   					//a temperature reading
	int hour;     					//hour after midnight [0:23]
	double temp_F; //in Fahrenehit
	double temp_C;
	Reading(int h=0, double t=0):hour(h),temp_F(t),temp_C(t){}// directly convert from F to C in the constructor
	double calc_C(){
		temp_C=(5*(temp_F-32)/9);
			return temp_C;
	}
};

istream& operator >>(istream& is, Reading& r){
	int h;
	double t;
	is>>h>>t;
	r.hour=h;
	r.temp_F=t;
	is.ignore(25,'\n');// ignore untill new line to keep functionality of being able to read file with or without celcius
	return is;
}
ostream& operator <<(ostream& os, Reading& r){
	os<<r.hour<<" "<<r.temp_F<<" "<<r.temp_C<<endl;
	return os;
}

int main(){
	const string f_name="raw_temps.txt";
	vector<Reading> tmp;
	fstream f;
	Reading r;

	f.open(f_name,fstream::in);

	while(f.good()&&!f.eof()){
		f>>r;
		r.calc_C();// determine c after reading in f
		tmp.push_back(r);
	}
	tmp.pop_back(); //remove trash value caused by loop
	f.clear();
	f.close();
	f.open(f_name,fstream::out);
	for(int i=0;i<tmp.size();++i){
		cout<<tmp[i];
		f<<tmp[i];
	}
	f.close();
	keep_window_open();
	return  0;
}