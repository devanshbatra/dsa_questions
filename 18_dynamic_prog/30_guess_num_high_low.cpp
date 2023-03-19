// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// approach:
// return the minimum amount of money you need to guarantee a win regardless of what number I pick.
// try to under stand this statement
//here for numbers 1 to n , we will try to pick each of them and assume them to be wrong.
//assuming wrong because we want the maximum amount of fine possible.
//for a particular number i from 1 to n.
// ai = i + max(f(s, i-1)+f(i+1, e)).
// we will find the maximum amount found from both the sub trees so that we have sufficient
//money to tackle every possibility.
//now from all these i. choose the minimum(as we would plan such that we get minimum sufficient
//money regardless of what they pick).
//SEE SS.

//A) recursion + memoization.
int solve(int s, int e, vector<vector<int>>& dp){
    //base case
    if(s>=e) return 0;

    if(dp[s][e]!=-1) return dp[s][e];

    //rc
    //pick each element from s to e and always assume that you have picked wrong one
    //  return the minimum fine by comparing all
    int ans = INT_MAX;
    for(int i=s; i<=e; i++){
        //since we have to find the minimum amount required to guarantee a win. - that why for an individual ai
        //we are find the max of both the subtrees.
        ans = min(ans, i+ max(solve(s, i-1, dp), solve(i+1, e, dp)));
    }

    return dp[s][e] = ans;
}

int getMoneyAmount(int n) {

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(1, n, dp);
}


//B) tabulation - dekho dhyan se ki start aur end ko kis tarah tackle kia hai.
int solve(int n){


    //make dp
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));


    //analyze base case and initialize dp
    // for(int i=0; i<=n; i++){
    //     dp[i][i] = 0;
    // } - waise he done.


    //start from the next of base case.
    //in top down s= 1 to n  &  e= n to 1.
    // do reverse i.e. s = n to 1.  and e = 1 to n.

    for(int s = n; s>=1; s--){
        for(int e=s; e<=n; e++){ //end ko start se he shuru kia taaki wo start se bhi kam na ho jaae
            if(s==e) continue;

            dp[s][e] = INT_MAX;
            for(int i=s; i<=e; i++){
                //since we have to find the minimum amount required to guarantee a win. so we are doing
                dp[s][e] = min(dp[s][e], i+ max(dp[s][i-1], dp[i+1][e]) );
            }
        }
    }

    return dp[1][n];
}

int getMoneyAmount(int n) {

    return solve(n);
}
//time complexity: O(N^3).
//space complexity: O(n^2).

//C) space optimization - 
//here our dp[s][e] is depending on i+1 and i-1, since i itself is running on loop so space optimization is not
//possible here.
