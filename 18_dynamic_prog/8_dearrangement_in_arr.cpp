//take example of a single node let say 1st node, we can place this 1st number at n-1 other numbers.
//so total ways would be (n-1)* ans of others.
// now here arise two cases when we are putting this 1st number on ith node.
//case 1: 
// if we place 1st on ith and also ith on 1st (swap them). then we are left with n-2 nodes on n-2 places,
// which do not want to be at their position. - which is a sub problem f(n-2).
// case 2:
// if we place 1st on ith element and we donot want to place ith on first(not direct swap). then,
// i node becomes a node which do not want to be on 1st position, similary 2nd node do not want 2nd position
// so, (n-1) nodes are there which do not want to be on (n-1) respective place, - this also is a subproblem
// f(n-1).
// CONCLUDING:  so for a single node total ans f(n) = n-1 * [f(n-1)+f(n-2)].
// see ss.

#include<iostream>
#include<vector>
#define mod 100000009
using namespace std;

long int solve(int n, vector<long int>& dp){
    if(n<2) return 0;
    if(n==2) return 1;
    
    
    
    if(dp[n]!=-1) return dp[n];
    
    long int ans =   (n-1) * (solve(n-1, dp)%mod +solve(n-2, dp)%mod)%mod;
    return dp[n] =  ans;
    
    
}
long int disarrange(int N){
    vector<long int> dp(N+1, -1);
    return solve(N, dp);
}

// BOTTOM UP APPROACH: tabulation.
long int solve(int n){
    //step1: initialize dp of adequate size.
    vector<long int> dp(n+1);
    //step2: see the base cases and initialize the dp accordingly.
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    
    //step3: traverse from next of base case towards the end.
    for(int i=3; i<=n; i++){
        dp[i] = (i-1)* (dp[i-1]%mod+dp[i-2]%mod)%mod;
    }
    return dp[n];
    
}
long int disarrange(int N){
    long int ans = solve(N);
    return ans;
}

// c) SPACE OPTIMIZATION METHOD
long int solve(int n){
    
    if(n==0) return 0;
    if(n==1) return 0;
    
    long int prev2 = 0;
    long int prev1 = 1;
    long int curr;
    
    for(int i=3; i<=n; i++){
        curr = (i-1)* (prev1%mod+prev2%mod)%mod;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;;
    
}
long int disarrange(int N){
    long int ans = solve(N);
    return ans;
}