// 1
// 2 3
// 4 5 6
// 7 8 9 10

#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int i,j, k=1;
    for(i=1; i<=n; i++){
       for(j=1; j<=i; j++){
           cout<<k<<" ";
           k++;
       }
       cout<<endl;
    }
    
    return 0;
}
