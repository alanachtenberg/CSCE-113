//Alan Achtenberg
//CSCE 113
//Assignement 4


#include "std_lib_facilities_3.h"


namespace cover
{

enum Genre {fiction, nonfiction, periodical, biography, children};

string convert_genre(int n)
{
    switch(n)
    {
    case 0:
        return "fiction";
    case 1:
        return "nonfiction";
    case 2:
        return "periodical";
    case 3:
        return "biography";
    case 4:
        return "children";
    }
}

struct isbn_exception
{
    int e;
    isbn_exception(int a=0):e(a) {}
};
struct Isbn
{
    int int1;
    int int2;
    int int3;
    char c;
    Isbn(int a=0, int b=0, int c=0, char d='0'):int1(a),int2(b),int3(c),c(d) {}
};

istream& operator>> (istream& is, Isbn& num)
{
    if(!(is>>num.int1))
        throw isbn_exception(1);
    is.ignore(5,'-');
    if(!(is>>num.int2))
        throw isbn_exception(2);
    is.ignore(5,'-');
    if(!(is>>num.int3))
        throw isbn_exception(3);
    is.ignore(5,'-');
    is>>num.c;
    if(!(isalnum(num.c)))
        throw isbn_exception(4);
    return is;
}
ostream& operator<< (ostream& os, Isbn& num)
{
    os<<num.int1<<"-"<<num.int2<<"-"<<num.int3<<"-"<<num.c;
    return os;
}

class Book
{
    Isbn isbn;
    string title;
    string author;
    string copyright;
    Genre g;
    bool available;

public:

    Book(Isbn bn=Isbn(), string t="default-title",string a="john doe",string c="1/1/1500",Genre gg=fiction,bool in_out=true):isbn(bn),title(t),author(a),copyright(c),
        g(gg), available(in_out) {}
    Isbn	get_isbn();
    string	get_title();
    string get_author();
    string get_copyright();
    Genre get_genre();
    bool get_available();
    void check_in();
    void check_out();

    Isbn set_isbn(Isbn n);
    string set_title(string s);
    string set_author(string s);
    string set_copyright(string s);
    Genre set_genre(int n);
    bool set_available(int i);
};



//this operator is pretty verbose becuase it checks every component of isbn
bool operator < (Book& a, Book& b)
{
    if (a.get_isbn().int1<b.get_isbn().int1&&a.get_isbn().int1!=b.get_isbn().int1)
        return true;
    else if (a.get_isbn().int1!=b.get_isbn().int1)
        return false;
    if (a.get_isbn().int2<b.get_isbn().int2&&a.get_isbn().int2!=b.get_isbn().int2)
        return true;
    else if (a.get_isbn().int2!=b.get_isbn().int2)
        return false;
    if (a.get_isbn().int3<b.get_isbn().int3&&a.get_isbn().int3!=b.get_isbn().int3)
        return true;
    else if (a.get_isbn().c!=b.get_isbn().c)
        return false;
    if (a.get_isbn().c<b.get_isbn().c&&a.get_isbn().c!=b.get_isbn().c)
        return true;
    else if (a.get_isbn().c!=b.get_isbn().c)
        return false;
    return false;
}


bool operator ==(Book& a,Book& b) // operator to check if book is equal by comparing every member of isbn
{
    if (a.get_isbn().int1==b.get_isbn().int1&&a.get_isbn().int2==b.get_isbn().int2&&a.get_isbn().int3==b.get_isbn().int3&&a.get_isbn().c==b.get_isbn().c)
        return true;
    else
        return false;
}

bool operator !=(Book& a,Book& b)  // switch the return values of == to get != other method would be to replace every == with !=
{
    if (a.get_isbn().int1==b.get_isbn().int1&&a.get_isbn().int2==b.get_isbn().int2&&a.get_isbn().int3==b.get_isbn().int3&&a.get_isbn().c==b.get_isbn().c)
        return false;
    else
        return true;
}

ostream& operator <<(ostream& os, Book& a)
{
    os<<a.get_title()<<endl;
    os<<a.get_author()<<endl;
    os<<a.get_isbn()<<endl;
    return os;
}

istream& operator >>(istream& is, Book& a)
{
    string temp;
    Isbn temp1;
    int temp2;
    is>>temp1;//use user defined operator to input isbn
    a.set_isbn(temp1);// use set function to modify private data
    is.ignore(1);//ignore leading white space because get line does not
    getline(is,temp,'~');
    a.set_title(temp);
    is.ignore(1);
    getline(is,temp,'~');
    a.set_author(temp);
    is>>temp;
    a.set_copyright(temp);
    is>>temp2;
    a.set_genre(temp2);
    is>>temp2;
    a.set_available(temp2);
    return is;
}

Isbn Book::get_isbn()
{
    return isbn;   //trivial get functions
}

string	Book::get_title()
{
    return title;
}

string Book::get_author()
{
    return author;
}

string Book::get_copyright()
{
    return copyright;
}

Genre Book::get_genre()
{
    return g;
}

bool Book::get_available()
{
    return available;
}

void Book::check_in()
{
    available=true;
}
void Book::check_out()
{
    available=false;
}

Isbn Book::set_isbn(Isbn n)  // trivial set functions
{
    isbn=n;
    return isbn;
}
string Book::set_title(string s)
{
    title=s;
    return title;
}

string Book::set_author(string s)
{
    author=s;
    return author;
}

string Book::set_copyright(string s)
{
    copyright=s;
    return copyright;
}

Genre Book::set_genre(int n)
{
    g=Genre(n);
    return g;
}

bool Book::set_available(int i)
{
    if (i==0)
        available=false;
    else
        available=true;
    return available;
}

}
