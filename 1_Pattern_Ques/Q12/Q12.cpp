/*
A B C
B C D
C D E
n=3
isme we can use
i+j-1 for the print value
isse milega 
1 2 3
2 3 4
3 4 5
ab A ko 1 se ma karna h
for 1st element: 
i+j-1 = 1 (add A-1 to map with A, b, C)
i+j-1 + 'A' -1  = "A"
i+j+'A'-1 = A; (solved)
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
        for(j=1; j<=n; j++){
            cout<<(char)(i+j-2+ch)<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    // another pattern of similar type
    /*
    A   
    B C
    C D E
    n=3
    */
   for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            cout<<(char)(i+j-2+ch)<<" ";
        }
        cout<<endl;
    }

    return 0;
}
