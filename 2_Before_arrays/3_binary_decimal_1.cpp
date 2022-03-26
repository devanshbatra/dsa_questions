// Converting decimal to binary
// ye ques gfg ide pr theek chl rha hai but yahan nhi chl rha
#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int a,ans = 0, digit;
    cout<<"Enter the decimal number: ";
    cin>>a;
    int a1 =a;

    // 2 se dvide krte krte reverse mein chahiye (method 1)
    int i=0;
    while(a!=0){
        digit = a%2;
        ans=ans+digit*pow(10, i);
        a/=2;
        i++;
    }
    cout<<ans<<endl;

    a=a1;
    ans=0;
    i=0;
    // method 2 - faster
    // we will do a a&1 if gives 1 then last bit is 1, otherwise gives 0 then it means last bit is 0, and thats how we will get the bits in reverse order
    // then we will reverse them with the method above
    while(a!=0){
        digit = a&1;
        cout<<digit<<endl;
        ans = ans+digit*(pow(10, i));
        cout<<"ans: "<<ans<<endl;
        a=a>>1;
        i++;
    }
    cout<<ans<<endl;

    return 0;
}

