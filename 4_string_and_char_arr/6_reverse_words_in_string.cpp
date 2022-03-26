
#include <iostream>
#include <string>
using namespace std;


int main(){
    
    string s = "";
    string ans;
    int e = s.length()-1;
    int back = e;

    while(e>=0){
        // cout<<s[e]<<",";
        if(s[e]==' '){
            // cout<<"got spcace"<<", back: "<<back<<" i : ";
            for(int i = e+1; i<=back; i++){
                // cout<<i<<" ";
                ans+=s[i];
            }
            back = e-1;
            // cout<<endl;
            ans+=' ';
        }
        e--;
    }    

    for(int i = 0; i<=back; i++){
        ans+=s[i];
    }

    // cout<<endl;
    cout<<ans;

}