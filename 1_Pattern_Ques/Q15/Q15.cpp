/*
1111
 222
  33
   4
*/

#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int i,j, k=1;
    char ch='A';

    for(i=1; i<=n; i++){
        // for space
        for(j=1; j<=i-1; j++){
            cout<<" ";
        }
        for(j=1; j<=n-i+1; j++){
            cout<<i;
        }
        cout<<endl;
    }

    cout<<endl;

    // similar type
    /*
       1
      22
     333
    4444
    */
   for(i=1; i<=n; i++){
        // for space
        for(j=1; j<=n-i; j++){
            cout<<" ";
        }
        for(j=1; j<=i; j++){
            cout<<i;
        }
        cout<<endl;
    }

    cout<<endl;

    // similar type
    /*
    1234
     234
      34
       4
    */
   for(i=1; i<=n; i++){
        // for space
        for(j=1; j<=i-1; j++){
            cout<<" ";
        }
        k=i;
        for(j=1; j<=n-i+1; j++){
            cout<<k;
            k++;
        }
        cout<<endl;
    }


    return 0;
}