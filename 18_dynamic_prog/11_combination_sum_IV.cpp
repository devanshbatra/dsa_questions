// https://leetcode.com/problems/combination-sum-iv/description/
// Given an array of distinct integers nums and a target integer target, 
// return the number of possible combinations that add up to target.

#include<iostream>
#include<vector>
using namespace std;

// For the recursion part-
//take the target .
// check with all the numbers with in nums.
// and for each number call for another recursion by reducing that number from the target.
// when target becomes 0 , it means that we have to return 1.
// if target has gone negative then this path could not reach to target, so return 0.
// time complexity for just the recursive solution: exponential.

// for the dp part-
// isme har baar target variable change ho rha h, so 1d dp he lag jaayegi.

// 1) recursion + memoization.
int solve(vector<int>& nums, int n, int target, int sum, vector<int>& dp){
    //base case
    if(sum==target) return 1;

    if(dp[sum]!=-1) return dp[sum];
    //rc
    int ans =0;
    for(int i=0; i<n; i++){
        if(sum+nums[i]<=target) ans+=solve(nums, n, target, sum+nums[i], dp);
    }

    return dp[sum] = ans;

}


int combinationSum4(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(200001, -1);
    return solve(nums, n, target, 0, dp);
}

//time complexity: O(target). 
//space complexity: O(target)+O(target).


//2) tabulation - bottom up approach

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    int n = nums.size();
    //traversing from target d to vr.
    for(int i=1; i<=target; i++){
        //is target ko achive karne ke liye saare number try kar lo.
        for(int j=0; j<n; j++){
            if(i-nums[j]>=0) dp[i]+=dp[i-nums[j]];
        }
    }
    return dp[target];
}

//time complexity: O(target). 
//space complexity: O(target)

//3) space optimization is not possible in this case, as we do not have exact dependency of dp[i] on anything.