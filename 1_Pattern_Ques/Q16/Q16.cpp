// type in photo
#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int i,j, k=1;

    for(i=1; i<=n; i++){
        for(j=1; j<=n-i;j++){
            cout<<" ";
        }
        for(j=1; j<=i; j++){
            cout<<j;
        }
        k=i-1;
        for(j=1; j<=i-1; j++){
            cout<<k;
            k--;
        }
        cout<<endl;
    }

    return 0;
}
