#include<iostream>

using namespace std;

int main(){

    int n;
    cout<<"enter value of n: ";
    cin>>n;
    for(int i=0; i<n; i++){

        for(int x=0; x<i; x++){
            cout<<" ";
        }

        int k=i+1;
        for(int j=0; j<n-i; j++){
            cout<<k;
        }
        cout<<endl;
    }
    return 0;
}
