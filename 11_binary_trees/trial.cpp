#include <iostream>
#include <map>
using namespace std;
 
// Driver code
int main()
{
 
    string s1="foo";
    string s2="bar";

    map<char, char> m12;
    map<char, char> m21;

    int n=s1.length();
    int count=0;
    
    for(int i=0; i<n; i++){
        if(m12[s1[i]] && m12[s1[i]]!=s2[i] ){
            count++;
        }else{
            m12[s1[i]]= s2[i];
        }
        
        if(m21[s2[i]] && m21[s2[i]]!=s1[i] ){
            count++;
        }else{
            m21[s2[i]] = s1[i];
        }
    }

    cout<<count;
 
    return 0;
}