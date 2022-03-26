/*
1
2 1
3 2 1
4 3 2 1
n=4
*/

#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int i,j, k=1;
    for(i=1; i<=n; i++){
       k=i;
       for(j=1; j<=i; j++){
           cout<<k<<" ";
           k--;
       }
       cout<<endl;
    }

    // Alternate method - better
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            cout<<i-j+1<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
