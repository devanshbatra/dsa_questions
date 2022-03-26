#include <iostream>

using namespace std;

int main(){

    int a[10][10] = { {1,2,3,4}, {3,4,5,7}, {2,7,9,6} };

    //row wise sum 
    for(int i=0; i<4; i++){
        int sum = 0;
        for(int j=0; j<3; j++){
            sum+=a[j][i];
        }
        cout<<"sum of "<<i+1<<"th col is: "<<sum<<endl;
    }


    return 0;
}