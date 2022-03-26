// These are same as integer arrays but they strore characters instead
// we can directly store the name or any thing by just cin and give output by just cout
// Charaacter arrays do not accept spaces. we can just store string without spaces in it.
// Space, tab and new line stops the cin
// This array is terminated by a null character. \0


// strings are somewhat similar but it represents a complete datatype with many functions in c++.
// string can also take spaces string st = "helo my name is devansh Batra"--> is completely valid
// but cin cannot take  spaces
// for cin to take spaces we use getLine(cin, variable_to_store, custom delimieter(optional parameter ));

#include <iostream>
#include  <bits/stdc++.h>

using namespace std;
int main(){
    char arr[10];
    cout<<"Enter your name: ";
    cin>>arr;
    // arr[2] = '\0'; //aisa karne se bas 0t aur 1st position he print hogi bcoz it will get a null character at position 2
    cout<<arr<<endl;

    // FIND THE LENGTH OF THE STRING

    // we know that whenever we get a null character the character array is terminated.
    char a='f';
    int count=0;
    while(a!='\0'){
        a=arr[count];
        if(a!='\0') count++;
    }
    cout<<"The length of your string is: "<<count<<endl;

    // inbuilt functions for character arrays and string
    // length
    // char st[10];
    // int len = strlen(st);
    // for string: st.length();

    // // compare
    // compare(s1, s2);
    // for string: compare(s1, s2);

    // // copy
    // strcopy(src, dest);
    // for string: s1=s2 ; simple

    // oher useful functions for string are : substr, erase, insert.


    // input a string with spaces
    cout<<"Enter a string"<<endl;
    string st;
    getline(cin, st, 'h'); //JAB TAK h nhi aaega tab tak 
    cout<<"String with spaces taken by input: "<<st;
    
}