/*
D
C D
B C D
A B C D
n=4
i ke badhne par print value decrease ho rhi h
n-i+1 will give 
4
33
222
1111
j ke badne pr inc ho rha h
n-i+1+j-1
n-i+j
map with  'A'
n-i+j = 1 -->A
n-i+j+A-1 
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
        for(j=1; j<=i; j++){
            cout<<(char)(n-i+j+'A'-1)<<" ";
        }
        cout<<endl;
    }

    return 0;
}

