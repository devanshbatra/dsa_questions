//basic masking to find if ith bit is set of not.

//1001011001
//      i   
//here i = 3
//now if we & this with 1<<3
//1001011001
//0000001000
//0000001000
//we got greater than 0.

#include <iostream>
using namespace std;

int main(){

    int n = 77;

    //find if 3rd bit is set
    int i = 3;
    if(n&(1<<i)) cout<<i<<"th bit is set"<<endl;
    else cout<<i<<"th bit not set"<<endl;
    

    //if I want to make the ith bit not set
    n = n & (~(1<<i));
    cout<<"after making ith bit as not set: "<<n<<endl;

    return 0;


}