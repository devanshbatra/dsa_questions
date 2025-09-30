#include <iostream>
using namespace std;

int main(){

    //1st method
    int num = 5;

    int count = 0;

    while(num>0){
        count+=(num&1); //if(num&1) count+=1 else no increase.
        num = num>>1;
    }

    cout<<"count 1st method: "<<count<<endl;

    count = 0; num = 5;
    //complexity = O(number of bits)


    //2nd method
    //There is a concept in bit manip that if we AND n and n-1 then the last set bit of n will be removed.
    //try doing on paper. as doing -1 will make the last set bit to shift left. So now if we 
    //do & of n and n-1 then that last set bit will be removed.
    //This can be used in a loop by removing the last set bit at every iteration and we can
    //count the number of set bits.
    while(num>0){
        num = num & num-1;
        count++;
    }
    cout<<"count 2nd method: "<<count<<endl;

    //complexity: O(number of set bits).

    return 0;
}


