//Alan Achtenberg
//CSCE 113-501
//Assignment 2
//Problem 2

#include "std_lib_facilities_3.h"

//includes sample code from 17.10.1 from programming practice and principles bjarnne stroustrup

class Link {
public:
    string value;

    Link(const string& v, Link* p = 0, Link* s = 0)
        : value(v), prev(p), succ(s) { }

    Link* insert(Link* n) ;   // insert n before this object
    Link* add(Link* n) ;      // insert n after this object
    Link* erase() ;           // remove this object from list
    Link* find(const string& s);    // find s in list
    const Link* find(const string& s) const; // find s in list
	int node_count(); // find size of list from current link to end of list

    Link* advance(int n);     // move n positions in list
	Link* first(); // return pointer to first element in list
    Link* next() const { return succ; }
    Link* previous() const { return prev; }
private:
    Link* prev;
    Link* succ;
};

//------------------------------------------------------------------------------

Link* Link::insert(Link* n)   // insert n before this object; return n
{
    if (n==0)
        return this;
    if (this==0)
        return n;

    n->succ = this;           // this object comes after n
    if (prev) prev->succ = n;
        n->prev = prev;           // this object's predecessor becomes n's predecessor
    prev = n;                 // n becomes this object's predecessor
    return n;
}

Link* Link::add(Link* n)
{
	n->prev=this; //set n previous to this
	n->succ=succ; //
	if (succ)
        succ->prev=n;
	succ=n;
	return n;

}
//------------------------------------------------------------------------------

Link* Link::erase()          // remove this object from the list; return this's successor
{
    if (this==0)
        return 0;
    if (succ)
        succ->prev = prev;
    if (prev)
        prev->succ = succ;
    return succ;
}

//------------------------------------------------------------------------------

Link* Link::find(const string& s) // find s in list;
// return 0 for "not found"
{
    Link* p = this;
    while(p) {
        if (p->value == s)
            return p;
        p = p->succ;
    }
    return 0;
}

int Link::node_count(){
	int counter=1;
	Link* p=this;
	Link* buf=succ;// create a buffer to check when value is 0 without losing the last pointer
	while (buf!=0){
        p=buf;
        buf=buf->succ;
        ++counter;
        if (buf==0)
            break;
	}
return counter;
}

Link* Link::advance(int n) {
	Link* p= this;
	while (n!=0){
		p=p->succ;
		--n;
	}
	return p;
}
Link* Link::first(){ // return pointer to first element in list
	Link* p=this;
	Link* buf=prev;
	while (buf!=0){
        p=buf;
        buf=buf->prev;
        if (buf==0)
            break;
	}
	return p;
}

//------------------------------------------------------------------------------

void print_all(Link* p)
{
    cout << "{ ";
    while (p) {
        cout << p->value;
        if (p=p->next()) cout <<  ", ";
    }
    cout << " }";
}

//------------------------------------------------------------------------------

int main()
{
    Link* norse_gods = new Link("Thor");
    norse_gods = norse_gods->insert(new Link("Odin"));
    norse_gods = norse_gods->insert(new Link("Zeus"));
    norse_gods = norse_gods->insert(new Link("Freia"));

    Link* greek_gods = new Link("Hera");
    greek_gods = greek_gods->insert(new Link("Athena"));
    greek_gods = greek_gods->insert(new Link("Mars"));
    greek_gods = greek_gods->insert(new Link("Poseidon"));

    Link* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    // Move Zeus into his correct Pantheon:
    {
        Link* p = norse_gods->find("Zeus");
        if (p) {
            if (p==norse_gods)
                norse_gods = p->next();
            p->erase();
            greek_gods = greek_gods->insert(p);
        }
    }

	norse_gods->add(new Link("loki"));
    // Finally, let's print out those lists:

	print_all(norse_gods);
    cout<<"\n";
	norse_gods=norse_gods->advance(2); // test advance
    print_all(norse_gods);
    cout<<"\n";

    print_all(greek_gods);
    cout<<"\n";
	cout<<greek_gods->node_count()<<endl; // test node count

	Link* god_list=new Link("Apollo");
	god_list=god_list->add(new Link("Aphrodite"));
	god_list=god_list->add(new Link("Artemis"));
	god_list=god_list->add(new Link("Hades"));
	god_list=god_list->first();
	print_all(god_list);
	cout<<endl;
	keep_window_open();
}

//------------------------------------------------------------------------------
