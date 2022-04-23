#include<iostream>
#include<string>

using namespace std;

bool chk_pallindrome(string st, int s, int e){
    //base case
    if(s>e) return true;
    if(st[s]!=st[e]) return false;
    // recursive call
    return chk_pallindrome(st, s+1, e-1);
}

int main(){
    string st= "adskhhksda";
    int n = st.length();
    int s = 0, e = n-1;

    cout<<chk_pallindrome(st, s, e);
    


    return 0;
}