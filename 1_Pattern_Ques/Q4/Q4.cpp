// 321
// 321
// 321
// .where n=3
#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int i,j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            //here j is from 1, 2, 3
            // we need to print 3, 2, 1
            // so we need to print n-j+1
            cout<<n-j+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
