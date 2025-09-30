// https://leetcode.com/problems/special-permutations/description/

//find the permutaions of the array where all adjacent elements divide one or the other.(see proper description).
#include <iostream>
#include<vector>
#define mod 1000000007

using namespace std;
class Solution {
public:
    
    //suppose we have n positions, so for every position we have to see all the unused numbers.
    //to make a track of unused and used number and save some space we will use bit mask.
    //it is a standard way to store the used numbers.
    
    int solve(vector<int>& nums, int n, int prev, int curr, int mask, vector<vector<int>>& dp){
        //base case
        if(curr==n) return 1;
        
        if(dp[prev+1][mask]!=-1) return dp[prev+1][mask]; //prev ko ek zyada le rhe hn due to its initialization with -1.
        
        //rc
        //we are at curr position
        //check all possibilities at this position
        int ans = 0;
        for(int i=0; i<n; i++){
            if( ((1<<i) & mask) >0) continue;
            
            if(prev==-1 || nums[i]%nums[prev]==0 || nums[prev]%nums[i]==0){
                ans = (ans + solve(nums, n, i, curr+1, mask|(1<<i), dp))%mod;
            }
            
        }
        
        return dp[prev+1][mask] = ans;
    }
    
    
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int>(16383+1, -1));
        
        return solve(nums, n, -1, 0, 0, dp);
        
    }
};