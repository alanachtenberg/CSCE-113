//Alan Achtenberg
//CSCE 113-501
//Assignment 2
//Problem 3

#include "std_lib_facilities_3.h"


class Singly_link {

public:
Singly_link* next; // next element in list
string name; // data in list

Singly_link ( const string& s="default", Singly_link* n=0)
	: name(s),next(n) {}

Singly_link* add(Singly_link* sl); // adds link after current pointer

Singly_link* insert(Singly_link* sl, Singly_link* first);// adds link before current pointer must pass in first object

void push_back(Singly_link* sl); // adds link to the end of the list

Singly_link* find(const string& s);// very important*** returns pointer to link before not link with string unless it is the first

void delete_link(const string& s); // deletes link with name s

Singly_link* advance(int n);

int node_count(); // returns size of list

Singly_link* end(); // returns pointer to last link in list


void print_list();
};



Singly_link* Singly_link::add(Singly_link* sl){
	sl->next=next;//object after link becomes object after new link
	next=sl;
	return sl;
}

Singly_link* Singly_link::insert(Singly_link* sl, Singly_link* first){
	Singly_link* p=first->find(name);// find pointer before current element
	p->next=sl;
	if(p!=this)
	sl->next=this;
	return sl;
}

void Singly_link::push_back(Singly_link* sl){
	Singly_link* p=end();//find last element in list
	p->next=sl;// set member next of last element to new link*
}

Singly_link* Singly_link::find(const string& s){
	if (name==s)
	return this;
	Singly_link* p=this;
	Singly_link* buff=this->next;
	while (s!=buff->name){
	p=buff;
	buff=buff->next;
	if (p==0){
		cout<<"string not found \n";
		return 0;}
	}
	return p;
}

void Singly_link::delete_link(const string& s){
	Singly_link* p=find(s);
	Singly_link* pp=p->next->next;
	delete p->next;
	p->next=pp;
}
Singly_link* Singly_link::advance(int n) {
	Singly_link* p= this;
	while (n!=0){
		p=p->next;
		--n;
		if(p==0){
			cout<<"advanced too far";
			return 0;
		}
	}
	return p;
}

int Singly_link::node_count(){ // find number of elements in list
	int counter=1;
	Singly_link* p=this;
	Singly_link* buf=next;// create a buffer to check when value is 0 without losing the last pointer
	while (buf!=0){
        p=buf;
        buf=buf->next;
        ++counter;
        if (buf==0)
            break;
	}
return counter;
}

Singly_link* Singly_link:: end(){ // find last element of list
	Singly_link* p=this;
	Singly_link* buf=next;
	while (buf!=0){
        p=buf;
        buf=buf->next;
        if (buf==0)
            break;
	}
return p;
}

void Singly_link::print_list(){
	Singly_link* p=this;
	while (p!=0){
		cout<<p->name<<" ";
		p=p->next;
	}
	cout<<" \n";
}

int main(){

	Singly_link* norse_first; // keep track of first element
	Singly_link* norse_gods = new Singly_link("Thor");
	norse_first=norse_gods;

    norse_gods = norse_gods->insert(new Singly_link("Odin"),norse_first);
    norse_gods = norse_gods->insert(new Singly_link("Zeus"),norse_first);
    norse_gods = norse_gods->insert(new Singly_link("Freia"),norse_first);

	Singly_link* greek_first;
    Singly_link* greek_gods = new Singly_link("Hera");

	greek_first=greek_gods;

    greek_gods = greek_gods->insert(new Singly_link("Athena"),greek_first);
    greek_gods = greek_gods->insert(new Singly_link("Mars"),greek_first);
    greek_gods = greek_gods->insert(new Singly_link("Poseidon"),greek_first);

    Singly_link* p = greek_first->find("Mars");
    if (p) p->next->name = "Ares";

    // Move Zeus into his correct Pantheon:
    {
            norse_first->delete_link("Zeus");
            greek_gods = greek_gods->insert(new Singly_link("Zeus"),greek_first);
        }

	norse_gods=norse_gods->add(new Singly_link("loki")); // test add
    // Finally, let's print out those lists:

	norse_first->print_list();
    cout<<"\n";
	norse_first=norse_first->advance(2); // test advance
    norse_first->print_list();
    cout<<"\n";

    greek_first->print_list();
    cout<<"\n";
	cout<<greek_gods->node_count()<<"\n\n"; // test node count

	Singly_link* god_list=new Singly_link("Apollo");
	Singly_link* god_first=god_list;
	god_list=god_list->add(new Singly_link("Aphrodite"));
	god_list=god_list->add(new Singly_link("Artemis"));
	god_list=god_list->add(new Singly_link("Hades"));

	god_first->print_list();
	cout<<endl;
	keep_window_open();
	return 0;
}
