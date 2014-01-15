//Alan Achtenberg
//CSCE 113-501
//Lab 8

#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "std_lib_facilities_3.h"
int main(){
using namespace std;

	cout<<"please input name of text file for example uin.txt\n";
	string file;
	cin>>file;
	

	ifstream in(file.c_str());
		if(in){
	cout<<"testing\n";
	}
	string temp;
	vector<string> lines;
	cout<<"original:\n\n";
	while(!in.eof()){
	getline(in,temp);
	lines.push_back(temp);
	cout<<temp<<endl;
	}
	
	cout<<"\nreplaced:\n\n";
	boost::regex pat1("\\d{3}-\\d{3}-\\d{3}"); // \\s is for begining and ending with space so that numbers with a uin as a sub expression are not matched
	for(int i=0;i<lines.size();++i){
		lines[i]=boost::regex_replace(lines[i],pat1,"xxx-xxx-xxx"); // add space in replacement as well
		cout<<lines[i]<<endl;
		}
	in.close();

	ofstream out(file.c_str());
	
	for(int i=0;i<lines.size();++i)
		out<<lines[i]<<endl;
	
	

	return 0;
}