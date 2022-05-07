#include<iostream>
#include<string>
#include<vector>
using namespace std;

void solve(string st, vector<string> &ans, int index ){
    int n = st.length();
    //base case
    if(index>=n){
        ans.push_back(st);
        return;
    }

    //recursive calls
    for(int i = index; i<n; i++){
        string temp = st;
        swap(st[i], st[index]);
        solve(st, ans, index+1);

        //reset the st for backtrack
        st = temp; //ya fir again swap kr do(ek he baat hai).       
    }

}

int main(){
    string st = "abc";
    int index = 0;
    vector<string> ans;
    solve(st, ans, index);

    cout<<"printing the output"<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;


    return 0;
}