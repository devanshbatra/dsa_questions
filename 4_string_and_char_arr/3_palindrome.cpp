#include <iostream>
using namespace std;

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

    bool is_palin = true;
    while(s<e){
        if(arr[s++]!=arr[e--]) is_palin = false;
    }

    cout<<"Is it pallindrome? : ";
    cout<<is_palin;

}