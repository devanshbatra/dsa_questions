// https://leetcode.com/problems/house-robber-ii/description/
// houses are arranged in a circle and you have to rob the non adjacent houses.

//ismein bas ek case extra h pichle wale question se
//hame is cheez ka dhyan rakhna pdega ki ab first aur last elements bhi neighbors hain
//so, jab bhi hum solution mein first element include kar rhe hain remember ki last na kara
//aur jab bhi last element ko include kar rhe hein remember ki first na kare

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//top down - recursion + memoization.
int solve(vector<int>& nums, int n, int i, vector<int>& dp){
    //base case
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    //rc
    int include  = nums[i]+solve(nums, n, i+2, dp);
    int exclude = 0 + solve(nums, n, i+1, dp);
    return dp[i] = max(include, exclude);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    //if n==1, then ye to first bhi h aur last bhi hai so ye case alag se handle karna padega.
    if(n==1) return nums[0];
    vector<int> first, second;
    for(int i=0; i<n; i++){
        if(i!=n-1)
            first.push_back(nums[i]);
        if(i!=0) 
            second.push_back(nums[i]);
    }
    vector<int> dp(n, -1);
    int firstinc = solve(first, n-1, 0, dp);
    for(int i=0; i<dp.size(); i++){
        dp[i] = -1;
    }
    int lastinc = solve(second, n-1, 0, dp);
    return max(firstinc, lastinc);
}

//tc: o(N). sc:O(N)+O(N)+O(N).

//next time do its bottom up and space optimization also.