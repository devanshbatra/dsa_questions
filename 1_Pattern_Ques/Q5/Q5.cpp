// 123
// 456
// 789
// .where n=3
#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int i,j,k=1;
    for(i=1; i<=n; i++){
       for(j=1; j<=n; j++){
           cout<<setw(2)<<k<<" ";
           k++;
       }
       cout<<endl;
    }
    return 0;
}
