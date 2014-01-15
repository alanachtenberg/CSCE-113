//Alan Achtenberg
//CSCE 113-501
// library class using book

#include "book.h"

using namespace cover;

struct by_title   // create compare functions to use with std sort
{
    bool operator()(Book& a, Book&  b)
    {
        return (a.get_title()<b.get_title());
    }
};
struct by_author
{
    bool operator()(Book& a, Book&  b)
    {
        return a.get_author()<b.get_author();
    }
};

struct by_isbn
{
    bool operator()(Book& a, Book&  b)
    {
        return a<b;
    }
};
class Library
{
public:

    vector<Book> lib;
    vector<int> copies;
    Library(vector<int> d=vector<int>(100),string s="library.txt")
    {
        lib=read(s);
        copies=d;
    }


    vector<Book> read(string s);

    vector<int> check(vector<Book> lib);

    vector<Book> sort_title();

    vector<Book> sort_author();

    vector<Book> sort_isbn();

    void display();

};

vector<Book> Library::read(string s)
{
    vector<Book> b;
    Book temp;
    ifstream in(s);
    while(in.good())
    {
        in>>temp;
        b.push_back(temp);
    }
    return b;
}
vector<int> Library::check(vector<Book> lib)  // works only on a sorted library it uses a vector of ints corresponding to vector of books
{
    int temp=1;
    int counter=0;
    for(int i=0; i<lib.size(); ++i)
    {
        counter=i;// initalize and reset values before while loop
        temp=1;
        if (i+1!=lib.size())
        {
            while (lib[counter]==lib[counter+1])  // use a seperate variable counter to check for more than one copy will keep checking untill it doesnt find one
            {
                ++temp;
                ++counter;
                if (counter+1==lib.size())
                    break;

            }
        }
        int d=0;
        while(d!=temp)  // if there is more than one copy, change the values for the next book for every copy
        {
            copies[i+d]=temp;
            ++d;
        }
        i=i+d-1;//
    }
    return copies;
}

vector<Book> Library::sort_title()
{

    sort(lib.begin(),lib.end(),by_title());
    check(lib); //after sort use check to determine number of copies of each book
    return lib;
}

vector<Book> Library::sort_author()
{

    sort(lib.begin(),lib.end(),by_author());
    check(lib);
    return lib;
}

vector<Book> Library::sort_isbn()
{

    sort(lib.begin(),lib.end(),by_isbn());
    check(lib);
    return lib;
}

void Library::display()
{
    for (int i=0; i<lib.size(); ++i)
    {
        cout<<lib[i]<<endl;
        cout<<"there are "<<copies[i]<<" copies of this book"<<endl;
        cout<<"its genre is "<<convert_genre(lib[i].get_genre())<<endl; // use convert_genre to convert from int value to string
        if (lib[i].get_available())
            cout<<"it is available \n\n";
        else
            cout<<"it is not available \n\n";

    }
}

