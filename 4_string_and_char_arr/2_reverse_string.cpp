//reverse a string.
// https://leetcode.com/problems/reverse-string/description/

//two pointer approach - put one at start, one at end - and start swapping.
#include <iostream>
using namespace std;

template <class T>
T swap_(T &a, T &b){
    T temp=a;
    a=b;
    b=temp;
}

int main(){
    char arr[10];
    cout<<"Enter your name: ";
    cin>>arr;
    int count=0;
    // getting length
    for(int i=0; arr[i]!=0; i++){
        count++;
    }

    int s = 0, e = count-1;

    while(s<e){
        swap_(arr[s++], arr[e--]);
    }


    cout<<"The reverse your name is: "<<arr<<endl;
}