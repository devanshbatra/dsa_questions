// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//brute force approach.
//traverse the array.
//treat the current element as the last element of the ap.
//move backward and see if you can find any element = curr-d.
//if found then recursive see backwards of that element.


int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    int ans = 0;
    vector<int> dp(n, 1);


    for(int i=1; i<n; i++){
        int curr = arr[i];
        //check backwards
        for(int j=i-1; j>=0; j--){
            if(curr-difference==arr[j]){
                dp[i]=dp[j]+1;

                break;
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;

}

//B) optimized approach using dp with hashing.
//we know that we need the ans of curr-d at every point.
//so why move backwards everytime. instead see if the dp contains the curr-d already.
//now since we do not know the curr-d ka upper and lower range.
//so we have used dp with hashing.
int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    int ans = 0;
    unordered_map<int, int> dp;


    for(int i=0; i<n; i++){
        int curr = arr[i];
        int temp = curr-difference;
        if(dp.count(temp)){
            dp[arr[i]] = dp[temp]+1;
        }
        else{
            dp[arr[i]] = 1;
        }
        // cout<<"for i: "<<i<<" dp[i]: "<<dp[i]<<endl;
        ans = max(ans, dp[arr[i]]);

    }

    return ans;

}
