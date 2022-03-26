/*
A B C
A B C
A B C
n=3
*/

#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int i,j, k=1;
    for(i=1; i<=n; i++){

       for(j=1; j<=n; j++){
           cout<<(char)('A'+j-1)<<" ";
        //    or
        // char ch = 'A'+j-1;
        // cout<<ch<<" ";
       }

       cout<<endl;
    }

    // Next on similar concept
    /*
    A B C
    D E F
    G H I
    n=3
    */
   cout<<endl;
    char ch='A';
    for(i=1; i<=n; i++){
    
        for(j=1; j<=n; j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }

    
    return 0;
}
