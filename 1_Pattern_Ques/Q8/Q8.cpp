// 1
// 2 3
// 3 4 5
// 4 5 6 7  n=4

#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n";
    cin>>n;
    int i,j, k=1;

    // shuruat har ro ki row number se he ho rhi hai
    for(i=1; i<=n; i++){
        k=i;
       for(j=1; j<=i; j++){
           cout<<k<<" ";
           k++;
       }
       
       cout<<endl;
    }




    k=1;
    // alternate method - pehle dimaag mein yhi aaya tha :-)
    for(i=1; i<=n; i++){

       for(j=1; j<=i; j++){
           cout<<k<<" ";
           k++;
       }
       if(i>1){
        k = k-(i-1);
       }
       cout<<endl;
    }

    // alternate method - best method without using k - pehle we were using n-j+1
    // but yahan number badh rhe hn row ke andar
    // aur ek row mein j is aisa h jo badh rha h
    // so we can relate with i such that i+j-1
    for(i=1; i<=n; i++){

       for(j=1; j<=i; j++){
        cout<<i+j-1<<" ";   
       }
       cout<<endl;
    }
    
    return 0;
}
