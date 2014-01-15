//Alan Achtenberg
//CSCE 113-501
//Assignment 3
//Problem 3

// this program takes a string of encrypted text and decrypts and displays the plaintext

#include "std_lib_facilities_3.h"


void decrement_char(char& c) //made function to decrement the char directly rather than convert to ints and use
{
    if (c=='a')              //the formula (p+26-k)mod26
        c='z';
    else --c;
}

string shift(string& s, int key)
{
    vector<int> nums;
    vector<char>chars;
    string text;
    char temp;

    stringstream ss;      // convert string into a vector of chars
    ss<<s;
    while(ss>>temp)
    {
        chars.push_back(temp);
    }

    for(int i=0; i<chars.size(); ++i)
    {
        for (int z=0; z<key; ++z)
            decrement_char(chars[i]);
    }
    ss.clear(); // reset all fail and eof bits
    for(int i=0; i<chars.size(); ++i) // convert vector of chars into a string
        ss<<chars[i];
    ss>>text;

    return text;
}


int main()
{

    string text;
    cout<<"input the encrypted text in lower case letters only\n";
    cin>>text;
    int key=1;
    while (key<26)
    {
        cout<<"key: "<<key<<" text: "<<shift(text,key)<<endl<<endl;
        ++key;
    }
    text="kszqcashcqfmdhcufodvm"; // sample text, key was determined by brute force method above to be 14
    cout<<text<<" decrypted with the key 14 is "<<shift(text,14)<<endl;
    keep_window_open();
    return 0;

}
