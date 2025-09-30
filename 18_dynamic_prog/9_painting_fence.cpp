// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence so
that not more than two consecutive fences have the same colors. Since the answer can be large
return it modulo 10^9 + 7

approach: to under stand approach see ss.

*/
//recursive+memoization.
#define mod 1000000007
#define ll long long
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




//alternate solution - done by me did by dry run on n = 3 , k=2
long long solve(int n, int k, int i, int used, vector<vector<ll>> & dp){
    //base case
    if(i==n) return 1;
    //rc
    if(dp[i][used]!=-1) return dp[i][used];
    ll use = 0, notUse = 0;
    if(!used) use = 1* solve(n, k, i+1, 1, dp)%mod; //use the same as previous - only one way * solve(others)
    notUse = (((k-1)%mod)*(solve(n, k, i+1, 0, dp)%mod))%mod; //not use the same as previous
    return dp[i][used] = (use+notUse)%mod;
}


long long countWays(int n, int k){
    // code here
    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    return (k%mod*solve(n, k, 1, 0, dp)%mod)%mod;
}


//optimized - my solution
long long solve(int n, int k){
    ll next0 = 1;
    ll next1 = 1;
    
    for(int i=n-1; i>=1; i--){
        ll curr0, curr1;
        for(int used=0; used<=1; used++){
            ll use = 0, notUse = 0;
            if(!used) use = (next1)%mod;
            notUse = (((k-1)%mod)*(next0%mod))%mod;
            if(used) curr1 = (use+notUse)%mod;
            else curr0 = (use+notUse)%mod;
        }
        next0 = curr0;
        next1 = curr1;
    }
    
    
    return next0;
}


long long countWays(int n, int k){
    // code here
    return (k%mod*solve(n, k)%mod)%mod;
}