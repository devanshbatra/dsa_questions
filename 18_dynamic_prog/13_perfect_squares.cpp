// Given an integer n, return the least number of perfect square numbers that sum to n.
// https://leetcode.com/problems/perfect-squares/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//do it recursively , for every target try all the squares of number from 1 to i(where i^2 is less
//  equal to than target)
// 1) recursion + memoization
int solve(int target, vector<int>& dp){
    //base case
    if(target==0){
        return 0;
    }
    if(dp[target]!=-1) return dp[target];
    //rc
    //check for all squares
    int ans = INT_MAX;
    for(int i=1; pow(i, 2)<=target; i++){
        ans = min(ans, 1+solve(target-pow(i, 2), dp));
    }
    return dp[target] = ans;
}
int numSquares(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}

//2) tabulation method
int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int tar = 1; tar<=n; tar++){
        //now tar is our target and check which combination is minimum for the tar.
        for(int i=1; pow(i, 2)<=tar; i++){
            dp[tar] = min(dp[tar], 1+dp[tar-pow(i, 2)]);
        }
    }
    return dp[n];
}

//3) space optimization is not practically possible here as dp[i] is not dependent on countable number of
// previous elements.