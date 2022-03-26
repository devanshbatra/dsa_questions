#include<iostream>

using namespace std;

int main(){
    int i=0, j=0;
    while(i<4){
        int j=0;
        while(j<4){
            cout<<"*";
            j++;
        }
        i++;
        cout<<endl;
    }
    return 0;
}
