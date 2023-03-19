// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//Method 1: using stack - tc: O(n). sc: O(n).
string reverseWords(string S) 
{ 
    stack<string> stk;
    string temp = "";
    //we will reverse using stack
    int n = S.length();
    
    for(int i=0; i<n; i++){
        if(S[i]=='.'){
            stk.push(temp);
            temp = "";
        }
        else{
            temp+=S[i];
        }
    }
    stk.push(temp);
    
    
    string ans = "";
    while(!stk.empty()){
        ans+=stk.top();
        stk.pop();
        
        if(!stk.empty()){
            ans+='.';
        }
    }
    
    return ans;
    
} 



//Method 2: using single pointer(but we have to reverse at every . here tc: nearly O(N^2). sc: O(N).
string reverseWords(string S) 
{ 
    string temp;
    string ans;
    //last se shuru karo aur jaise he . mile reverse kardo aur ans mein daal do, aur temp phir se khaali.
    int n=S.length();
    
    if(n==1 && S[0]=='.') return ".";//iss approach mein bas ye ek case phasega
    
    for(int i=n-1; i>=0; i--){
        if(S[i]=='.'){
            reverse(temp.begin(), temp.end());
            ans+=(temp+".");
            temp="";
        }
        else{
            temp+=S[i];
        }
    }
    
    //last word
    reverse(temp.begin(), temp.end());
    ans+=temp;
    return ans;
} 

//method 3: go straight from 0 to n and do : '.' + temp + ans;
//most optimal approach.