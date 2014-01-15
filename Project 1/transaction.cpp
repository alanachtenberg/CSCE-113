//includes definitions of transaction operators

#include "std_lib_facilities_3.h"
//Project 1
// Alan Jason Chihyen
#include "transaction.h"

ostream& operator << (ostream& os, Transaction& t){
	return os<<"("<<t.date<<" "<<t.amount<<") ";
}

istream& operator >> (istream& is, Transaction& t){
	 is.ignore(25,'(');
	 is>>t.date>>t.amount;
	return is.ignore(25,')');
}
