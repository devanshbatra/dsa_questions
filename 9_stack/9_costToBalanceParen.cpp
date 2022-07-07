/*
You have been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid if all the
 brackets are balanced. Formally for each opening bracket, there must be a closing bracket right to it.

https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770?leftPanelTab=0
*/

#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;


vector<int> nextSmallerEle(vector<int> v){
    int n = v.size();
    vector<int> ans;
    stack<int> s;
    s.push(-1);
    for( int i=n-1; i>=0; i-- ){
        int top = s.top();
        if(v[i]>top){
            ans[i] = top;
            s.push(i);
        }else if(v[i]<=top){
            while(i<=s.top()){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
    }
}


int main(){
    vector<int> v = {2, 1, 4, 3};
    vector<int> ans;
    ans = nextSmallerEle(v);

    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}


/*
Now try :
https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?leftPanelTab=0

for this ques : next smaller element , time complexity : O(n).
*/
