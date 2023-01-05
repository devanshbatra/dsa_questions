// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence so
that not more than two consecutive fences have the same colors. Since the answer can be large
return it modulo 10^9 + 7

approach: to under stand approach see ss.

*/
//recursive+memoization.
#define mod 1000000007
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    
    
    long long solve(int n, int k, vector<int>& dp){
        //base case
        if(n==1) return k;
        if(n==2) return k*(k-1) + k;
        
        if(dp[n]!=-1) return dp[n];
        
        long long prev2 = (solve(n-2, k, dp)%mod * (k-1)%mod)%mod;
        long long prev1 = (solve(n-1, k, dp)%mod * (k-1)%mod)%mod;
        
        return dp[n] =  (prev1%mod+prev2%mod)%mod;
        
    }
    
    long long countWays(int n, int k){
        vector<int> dp(n+1, -1);
        return solve(n, k, dp);
    }
};

//tabulation - bottom up approach
long long solve(int n, int k){
    
    vector<long long> dp(n+1);
    dp[1] = k;
    dp[2] = k*(k-1) + k;
    
    
    
    for(int i=3; i<=n; i++){
        int prev2 = (dp[i-2]%mod * (k-1)%mod);
        int prev1 = (dp[i-1]%mod * (k-1)%mod);
        dp[i] = (prev1%mod+prev2%mod)%mod;
    }
    
    return dp[n];
    
}

long long countWays(int n, int k){
    return solve(n, k);
}


//space optimization
long long solve(int n, int k){
    
    if(n==1) return k;
    
    long long prev2 = k;
    long long prev1 = k*(k-1) + k;
    
    
    
    for(int i=3; i<=n; i++){
        long long curr = ((prev1*(k-1))%mod + (prev2 * (k-1))%mod)%mod;
        
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
    
}

long long countWays(int n, int k){
    return solve(n, k);
}