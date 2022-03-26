// Q17 ka advanced version
#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Enter the value of n";
    cin >> n;
    int i, j, k = 1;

    // upper pattern same as Q17
    for (i = 1; i <= n; i++){

        for (j = 1; j <= n - i + 1; j++){
            cout << j;
        }

        for (j = 1; j <= 2 * (i - 1); j++){
            cout << "*";
        }

        
        for(k = n-i+1; k>0; k--){
            cout<<k;
        }

        cout << endl;
    }

    // lower part in continuation
    // here we need 4 rows and starting i from 2 fits great, your question your solution
    for(i=2; i<=n; i++){

        for(j=1; j<=i; j++){
            cout<<j;
        }

        for(j=1; j<=2*(n-i); j++){
            cout<<"*";
        }

        for(j=i; j>0; j--){
            cout<<j;
        }

        cout<<endl;

    }

    return 0;
}