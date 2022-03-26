// 111..n
// 222..n
// 333..n
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
            cout<<i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}
