#include <iostream>

using namespace std;

int main(){

    int a[10][10] = { {1,2,3}, {3,4,5}, {2,7,9} };

    //row wise sum 
    for(int i=0; i<3; i++){
        int sum = 0;
        for(int j=0; j<3; j++){
            sum+=a[i][j];
        }
        cout<<"sum of "<<i+1<<"th row is: "<<sum<<endl;
    }


    // largest row sum
    int max=INT_MIN, index=-1;
    for(int i=0; i<3; i++){
        int sum = 0;
        for(int j=0; j<3; j++){
            sum+=a[i][j];
        }
        if(sum>max) {
            max=sum;
            index = i;
        };
    }

    cout<< "The max sum row wise is : "<<index<<endl;


    return 0;
}