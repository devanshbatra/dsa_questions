#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//here we would be given an array and we have to find the subsequence of non adjacent elements which has the 
//maximum sum.
// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

//approach : 
/*
We will start from left to right.
at every index i(single rec case), we have two options :
    1) either include this i, then include will be arr[i]+solve(next non adj).
    2) or exclude this i, then exc will be 0+solve(next adj element).
    3) and we have to return the max of these.

*/


// A) top down approach - recursion + memoization.
int solve(int i, vector<int>& nums, int n, vector<int>& dp){
    //base case
    if(i>=n) return 0;
    
    //after base case include dp
    if(dp[i]!=-1) return dp[i];
    
    //for this index we just need to find the max result of (if we include vs if we exclude).
    //if we include.
    int include = nums[i] + solve(i+2, nums, n, dp);
    //if we exclude 
    int exclude = 0 + solve(i+1, nums, n, dp);
    
    dp[i] = max(include, exclude);
        
    return max(include, exclude);
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    //initialize dp vector.
    vector<int> dp(nums.size(), -1);
    
    return solve(0, nums, nums.size(), dp);
    
}//tc: O(N). sc: O(N)+O(N)

//B- bottom up approach
int solveTab(vector<int> & nums){
    
    //solving using tabulation
    //1. initialize dp
    int n = nums.size();
    vector<int> dp(n, -1);
    //2. save the base case in dp
    dp[0] = nums[0];
    
    //3. traverse from next of base case to end till we get the ans.
    for(int i=1; i<n; i++){
        int inc = nums[i] + dp[i-2];
        int exc = 0+dp[i-1];
        dp[i] = max(inc, exc);
    }
    
    return dp[n-1];
    
}
int maximumNonAdjacentSum(vector<int> &nums){
    
    return solveTab(nums);
    
}//tc: O(N) sc: O(N).


//C) space optimization
//here we can see that dp[i] depends on two previous values.
//space optimized solution
int solve(vector<int> & nums){
    
    //solving using tabulation
    //1. initialize dp
    int n = nums.size();
    
    
    
    //2. save the base case in dp
    int prev1 = nums[0];
    int prev2 = 0;
    int curr;
    //3. traverse from next of base case to end till we get the ans.
    for(int i=1; i<n; i++){
        int inc = nums[i] + prev2;
        int exc = 0+prev1;
        curr = max(inc, exc);
        
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
    
}

int maximumNonAdjacentSum(vector<int> &nums){
    
    return solve(nums);
    
}
//tc: O(N). sc: O(1).

//similarly solve this question: https://leetcode.com/problems/house-robber/description/
//this is also based on the same concept
    