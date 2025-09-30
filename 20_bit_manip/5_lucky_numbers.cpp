#include <iostream>
#include <math.h>
using namespace std;

//Ques: You are given two number 4 and 7 and you can make any number of numbers using just
//these two. like you can make 4, 7, 44, 47, 74, 77, 444, 447 ... in increasing order.
//you are given a number from this series. Give the position of that term in the series.

long long findLuckyNumbers(int n){
    long long ans = 0;
    
    int i = 0;

    while(n>0){
        int dig = n%10;
        n = n/10;
        if(dig == 7) ans += pow(2, (long long)i); //if dig == 7 means there will be some combination if 4 was there.
        cout<<"ans: "<<ans<<endl;
        i++;
    }
    cout<<"i: "<<i<<endl;

    ans+= (pow(2, (long long)i)-2); //for the lower numbers where number of dig<i.
    return ans+1; //for this number.
}

int main(){

    int n;
    cin>>n;
    cout<<findLuckyNumbers(n);
    return 0;
}