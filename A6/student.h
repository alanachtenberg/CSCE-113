#include "std_lib_facilities_3.h"


struct Student{

	string last_name;
	int UIN;
	double GPA;


	Student(string n="default",int u=0,double g=0):last_name(n),UIN(u),GPA(g){}
};

struct by_name{
	bool operator()(Student const &a, Student const &b) const{
		return a.last_name<b.last_name;
	}
};

struct by_UIN{
	bool operator()(Student const &a, Student const &b) const{
		return a.UIN<b.UIN;
	}
};

struct GPA_pred{
	bool operator()(Student const &a, Student const &b) const{
		return a.GPA==b.GPA;
	}
};

struct by_GPA{
	bool operator()(Student const &a, Student const &b) const{
		return a.GPA<b.GPA;
	}
};

istream& operator >>(istream& is,Student &a){
	is.ignore(10,'!');
	is>>a.last_name;
	is>>a.UIN;
	return is>>a.GPA;
}

ostream& operator <<(ostream& os,Student &a){
	return os<<"! "<<left<<setw(10)<<a.last_name<<" "<<a.UIN<<" "<<a.GPA;
}