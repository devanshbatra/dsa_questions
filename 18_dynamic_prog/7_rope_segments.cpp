/*
given three values x, y and z and a rope of length n.
we have to do maximum cut in the cuts using only those three x, y, z.
    https://www.codingninjas.com/codestudio/problems/cut-into-segments_1214651?leftPanelTab=0
*/

#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;
//har point pe we have 3 options to cut.
// and in dp/recursion we generally take the result by comparing all 
// paths.
// at every point we will choose the maximum add one for curr cut and return it.

//top down approach: recursion + memoization.
int solve(int n, vector<int>& cuts, vector<int>& dp){
    
    //base case
    if(n<0) return INT_MIN;
    if(n==0) return 0;
    
    if(dp[n]!=-1) return dp[n];
    //rc
    int maxi = INT_MIN;
    for(auto cut: cuts){
        int usingCut = solve(n-cut, cuts, dp);
        if(usingCut!=INT_MIN) maxi = max(maxi, usingCut+1);//plus one is for this cut.
    }
    
    
    return dp[n] = maxi;
    
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
    vector<int> cuts{x, y, z};
    vector<int> dp(n+1, -1);
    int ans = solve(n, cuts, dp);
    if(ans!=INT_MIN) return ans;
    else return 0;
}

//bottom up approach: tabulation method.
int solve(int n, vector<int>& cuts){
    

//     1) make a dp  and initialize with base case.
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;
    
//     2) start from next of base case till end
    for(int i=1; i<=n; i++){
        for(auto cut: cuts){
            if(i-cut>=0)
                dp[i] = max(dp[i], dp[i-cut]+1);//plus one is for this cut.
        }
    }
    
    if(dp[n]<0) return 0;
    else return dp[n];
    
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
    vector<int> cuts{x, y, z};
    int ans = solve(n, cuts);
    return ans;
}