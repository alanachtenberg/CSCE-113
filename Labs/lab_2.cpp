//Alan Achtenberg
//CSCE 113-501
//Lab 2


#include "std_lib_facilities_3.h"

int main(){

	vector<int>coins;
	int temp;
	

	cout<<"How many pennies do you have?\n";//query the user for input and input directly into vector coins
	cin>>temp;
	coins.push_back(temp);
	cout<<"How many nickels do you have?\n";
	cin>>temp;
	coins.push_back(temp);
	cout<<"How many dimes do you have?\n";
	cin>>temp;
	coins.push_back(temp);
	cout<<"How many quarters do you have?\n";
	cin>>temp;
	coins.push_back(temp);
	cout<<"How many half dollars do you have?\n";
	cin>>temp;
	coins.push_back(temp);
	cout<<"How many one dollar coins do you have?\n";
	cin>>temp;
	coins.push_back(temp);

	double total;// find total value by adding the components of the vector multiplyed by their corresponding coins value
	total=coins[0]+coins[1]*5+coins[2]*10+coins[3]*25+coins[4]*50+coins[5]*100;
	total/=100;//convert pennies into dollars
	
	if (coins[0]!=1)
		cout<<"You have "<<setw(6)<<coins[0]<<" pennies\n";// output in a list the number of bills, the purpose of setw(6) is to right allign the numbers up to 6 decimals
	else cout<<"You have "<<setw(6)<<coins[0]<<" pennie\n";
	
	if (coins[1]!=1)
		cout<<"You have "<<setw(6)<<coins[1]<<" nickels\n";
	else cout<<"You have "<<setw(6)<<coins[1]<<" nickel\n";
	
	if (coins[2]!=1)
		cout<<"You have "<<setw(6)<<coins[2]<<" dimes\n";
	else cout<<"You have "<<setw(6)<<coins[2]<<" dime\n";

	if (coins[3]!=1)
		cout<<"You have "<<setw(6)<<coins[3]<<" quarters\n";
	else cout<<"You have "<<setw(6)<<coins[3]<<" quarter\n";

	if (coins[4]!=1)
		cout<<"You have "<<setw(6)<<coins[4]<<" half dollars\n";
	else cout<<"You have "<<setw(6)<<coins[4]<<" half dollar\n";

	if (coins[5]!=1)
	cout<<"You have "<<setw(6)<<coins[5]<<" one dollar coins\n\n";
	else cout<<"You have "<<setw(6)<<coins[5]<<" one dollar coin\n\n";

	cout<<"the value of all of your coins is $"<<total<<"\n";// output the total

keep_window_open();
return 0;
}
