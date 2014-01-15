//Alan Achtenberg
//CSCE 113-501
//Assignment 4
//Library main

#include "library.h"


int main()
try
{
    using namespace cover;

    int num;
    Library  lib1;
    cout<<"to display library choose to sort by title(1) author(2) or isbn(3) corresponding to input 1 2 or 3, please input integer now";
    cin>>num;
    switch(num)
    {
    case 1:
        lib1.sort_title();
        break;
    case 2:
        lib1.sort_author();
        break;
    case 3:
        lib1.sort_isbn();
        break;
    default:
        cout<<"error you did not input 1 2 or 3";
        keep_window_open();
        return 0;
        break;
    }
    cout<<"\n\n\n";
    lib1.display();
    keep_window_open();
    return 0;
}

catch(cover::isbn_exception& e)
{
    cout<<" isbn error has occured  1 2 3 correspond to the ints 4 corresponds to the last character"<<e.e<<endl;
    keep_window_open("~");
    return 1;
}
catch(...)
{
    cout<<"exception occured"<<endl;
    keep_window_open("~");
    return 2;
}
