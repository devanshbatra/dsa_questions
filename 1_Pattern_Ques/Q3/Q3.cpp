// 123..n
// 123..n
// 123..n
// .
// .
// .n
#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int i,j;
    i=1;
    while(i<=n){
        j=1;
        while(j<=n){
            cout<<j<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}
