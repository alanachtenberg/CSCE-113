//Alan Achtenberg
//CSCE 113-501
//Assignment 6

#include "student.h"
#include <set> //not included in sstd_lib facilities
#include <map>
void print(vector<Student>& v){
	for(int i=0;i<v.size();++i)
		cout<<i<<v[i]<<endl;
	cout<<endl;
}
void print(list<Student>& l){
	list<Student>::iterator p=l.begin();
	for(int i=0;i<l.size();++i){
		cout<<i<<*p<<endl;
		++p;
	}
	cout<<endl;
}
void print(set<Student,by_UIN>& s){
	set<Student,by_UIN>::iterator p=s.begin();
	
	for(p;p!=s.end();++p){
		Student t=*p;
		cout<<t<<endl;
	}
	cout<<endl;
	}
void print(set<Student,by_name>& s){
	set<Student,by_name>::iterator p=s.begin();
	
	for(p;p!=s.end();++p){
		Student t=*p;
		cout<<t<<endl;
	}
	cout<<endl;
	}
void print(map<int,double>& m){
	map<int,double>::iterator p;
	for(p=m.begin();p!=m.end();++p){
		cout<<"! "<<setw(4)<<p->first<<" "<<p->second<<endl;
	}
	cout<<endl;
	}
void print(map<double,int>& m){
	map<double,int>::iterator p;
	for(p=m.begin();p!=m.end();++p){
		cout<<"! "<<setw(4)<<p->first<<" "<<p->second<<endl;
	}
	cout<<endl;
	}



void vec(){
	Student temp;
	vector<Student> vi;

	ifstream in("students.txt");
	for (int i=0;i<10;++i){
		in>>temp;
		vi.push_back(temp);
	}

	sort(vi.begin(),vi.end(),by_name());
	print(vi);
	sort(vi.begin(),vi.end(),by_UIN());
	print(vi);
	Student find_me("Achtenberg",608000321,3.9);

	vector<Student>::iterator access; //declare iterator
	access=lower_bound(vi.begin(),vi.end(),find_me,by_UIN());//lower bound returns iterator to first item found in binary search
	cout<<vi[access-vi.begin()]<<endl<<endl;
	
	sort(vi.begin(),vi.end(),by_GPA()); //sort vector to make it easier to find all students with particular gpa
	access=search_n(vi.begin(),vi.end(),1,find_me,GPA_pred());
	
	int i=0;
	while(vi[access-vi.begin()].GPA==vi[access-vi.begin()+i].GPA){
			cout<<vi[access-vi.begin()+i]<<endl;
			++i;
	}
	cout<<endl<<endl;


	temp=Student("Smith", 204394130, 3.4);

	vi.insert(vi.begin(),temp); //first argument can be any iterator, used begining for simplicity, this code puts new student at beginning of list
	sort(vi.begin(),vi.end(),by_name());
	print(vi);

	access=lower_bound(vi.begin(),vi.end(),find_me,by_name());//find student by name
	cout<<*access<<" has been removed from list\n\n";//out
	vi.erase(access);//remove found student
}

void lt(){
	Student temp;
	list<Student> vi;
	ifstream in("students.txt");
	for (int i=0;i<10;++i){
		in>>temp;
		vi.push_back(temp);
	}

	vi.sort(by_name());//list has member function sort
	print(vi);
	vi.sort(by_UIN());
	print(vi);
	Student find_me("Achtenberg",608000321,3.9);

	list<Student>::iterator access; //declare iterator
	access=lower_bound(vi.begin(),vi.end(),find_me,by_UIN());//lower bound returns iterator to first item found in binary search
	cout<<*access<<endl<<endl;
	
	vi.sort(by_GPA()); //sort list to make it easier to find all students with particular gpa
	access=search_n(vi.begin(),vi.end(),1,find_me,GPA_pred());
	
	int i=0;
	cout<<*access<<endl;
	while(1){
	temp=*access;
	Student temp2;
	++access;
	temp2=*access;
	if (temp2.GPA==temp.GPA)
		cout<<temp2;
	else
		break;
	}

	cout<<endl<<endl;


	temp=Student("Smith", 204394130, 3.4);

	vi.insert(vi.begin(),temp); //first argument can be any iterator, used begining for simplicity, this code puts new student at beginning of list
	vi.sort(by_name());
	print(vi);

	access=lower_bound(vi.begin(),vi.end(),find_me,by_name());//find student by name
	cout<<*access<<" has been removed from list\n\n";//out
	vi.erase(access);//remove found student


}
void st(){
	Student temp;
	set<Student,by_UIN> vi;

	ifstream in("students.txt");
	for (int i=0;i<10;++i){
		in>>temp;
		vi.insert(temp);
	}
	print(vi);
	Student find_me("Achtenberg",608000321,3.9);
	set<Student,by_UIN>::iterator it;

	it=vi.lower_bound(find_me);
	temp=*it;
	cout<<temp<<"\n\n";
	
	it=search_n(vi.begin(),vi.end(),1,find_me,GPA_pred());
	


	int i=0;
	temp=*it;
	cout<<temp<<endl;
	while(1){
	temp=*it;
	Student temp2;
	++it;
	temp2=*it;
	if (temp2.GPA==temp.GPA)
		cout<<temp2;
	else
		break;
	}

	cout<<endl<<endl;

	
	temp=Student("Smith", 204394130, 3.4);

	vi.insert(temp);
	set<Student,by_name> ni;

	for(set<Student,by_UIN>::iterator me=vi.begin();me!=vi.end();++me){
		temp=*me;
		ni.insert(temp);
	}
	ni.erase(find_me);
	print(ni);
}

void mp(){
	Student temp;
	map<int,double> mid;
	ifstream in("students.txt");
	for (int i=0;i<10;++i){
		in>>temp;
		mid.insert(pair<int,double>(temp.UIN,temp.GPA));
	}
	print(mid);
	map<int,double>::iterator it;
	double sum=0;
	for (it=mid.begin();it!=mid.end();++it)
		sum=sum+it->second;
	cout<<"the average gpa is "<<sum/mid.size()<<endl<<endl;
	it=mid.end();
	--it;//decrement iterator for it to point to last element in container
	mid.erase(it);

	map<double,int> mdi;

	for (it=mid.begin();it!=mid.end();++it)
		mdi.insert(pair<double,int>(it->second,it->first));
	print(mdi);
}

int main(){
	cout<<"PART 1:\n\n";
	vec(); //vector
	cout<<"\n\n\n\nPART 2:\n\n";
	lt(); //list
	cout<<"\n\n\n\nPART 3:\n\n";
	st(); //set
	cout<<"\n\n\n\nPART 4:\n\n";
	mp(); //map
	keep_window_open();
	return 0;
}