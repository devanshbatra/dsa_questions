//First do this question: https://leetcode.com/problems/climbing-stairs/description/

/*
Then the main question is: https://leetcode.com/problems/min-cost-climbing-stairs/description/

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//top down approach - recursion + memoization.
int minCost(int n, vector<int>& cost, vector<int>& dp){
    //base case
    if(n==0) return cost[0];
    if(n==1) return cost[1];

    if(dp[n]!=-1) return dp[n];

    //rc
    return dp[n] = cost[n]+ min( minCost(n-1, cost, dp), minCost(n-2, cost, dp) );
}

int minCostClimbingStairs(vector<int>& cost) {
    //if we start recursion from staring then there is an ambiguity that which step to choose 0th or 1st.
    //but if we start from ending then we know that we have to to start from nth stair only and 
    //then we can choose minimum from prev and prev-1
    
    //say we start from ending , we not have any cost of end and cost of reaching end would be 
    // f(n) = min(f(n-1), f(n-2)).
    // but since n-1 has a cost, so we need to add that cost in n-1 ka function
    // f(n-1) = min(f(n-1-1), f(n-1-2)) + cost(n-1).

    int n = cost.size();
    
    vector<int> dp(n, -1);

    int ans = min(minCost(n-1, cost, dp), minCost(n-2, cost, dp));
    return ans;
}
//tc: O(n);
//sc: O(N).

//bottom up : tabulation approach
/*
steps:
1) create dp array.
2) set the base case in the dp array.
3) iterate from next of base case towards the end
4)find curr value of dp based on the previously stored values in dp
5) return then end ans.
*/
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    
    vector<int> dp(n+1, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2; i<=n; i++){
        if(i==n){
            dp[i] = min(dp[i-1], dp[i-2]);
            continue;
        }
        dp[i] = cost[i]+min(dp[i-1], dp[i-2]);
    }
    return dp[n];
}
//tc: O(N), sc: o(N).

//SPACE OPTIMIZATION
//we see that our dp[i] function is dependent on just two variables from dp array i.e prev1 and prev2.
//so it is possible to reduce our space complexity to O(1).
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    
    
    int prev2 = cost[0];
    int prev1 = cost[1];
    for(int i=2; i<n; i++){
        int curr = cost[i]+min(prev1, prev2);
        //update previous
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}
//tc: same, sc: O(1).