//Project 1
// Alan Jason Chihyen
#include "std_lib_facilities_3.h"

struct Statistic{

	int total_customer;
	double deposits;
	double average;

	Statistic(int t=0, double d=0):total_customer(t),deposits(d),average(t/d){}

};

