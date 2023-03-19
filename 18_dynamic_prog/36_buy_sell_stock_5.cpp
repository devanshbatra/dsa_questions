// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//we just have to deduct the given fee when the sell is done, rest is same as previous parts.

//A) top down
int solve(vector<int>& prices, int n, int fee, int index, int buyAllowed, vector<vector<int>> &dp){
    //base case
    if(index==n) return 0;

    if(dp[index][buyAllowed]!=-1) return dp[index][buyAllowed];

    //rc
    //if buy is allowed
    int profit;
    if(buyAllowed){
        int buy = -prices[index] + solve(prices, n, fee, index+1, 0, dp);
        int skip = 0 + solve(prices, n, fee, index+1, 1, dp);
        profit = max(buy , skip);
    }
    else{
        int sell = prices[index] - fee + solve(prices, n, fee, index+1, 1, dp);
        int skip = 0 + solve(prices, n, fee, index+1, 0, dp);
        profit = max(sell , skip);
    }

    return dp[index][buyAllowed] = profit;
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));

    return solve(prices, n, fee, 0, 1, dp);
}

//B) bottom up
int solve(vector<int>& prices, int n, int fee){

    //make dp
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    //analyze base case
    //start from next of base case in reverse order.
    for(int index=n-1; index>=0; index--){
        for(int buyAllowed=0; buyAllowed<2; buyAllowed++){
            int profit;
            if(buyAllowed){
                int buy = -prices[index] + dp[index+1][0];
                int skip = 0 + dp[index+1][1];
                profit = max(buy , skip);
            }
            else{
                int sell = prices[index] - fee + dp[index+1][1];
                int skip = 0 + dp[index+1][0];
                profit = max(sell , skip);
            }

            dp[index][buyAllowed] = profit;
        }
    }

    return dp[0][1];



}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();

    return solve(prices, n, fee);
}

// C) space optimized
int solve(vector<int>& prices, int n, int fee){

    //make dp

    vector<int> curr(3, 0);
    vector<int> next(3, 0);

    //analyze base case
    //start from next of base case in reverse order.
    for(int index=n-1; index>=0; index--){
        for(int buyAllowed=0; buyAllowed<2; buyAllowed++){
            int profit;
            if(buyAllowed){
                int buy = -prices[index] + next[0];
                int skip = 0 + next[1];
                profit = max(buy , skip);
            }
            else{
                int sell = prices[index] - fee + next[1];
                int skip = 0 + next[0];
                profit = max(sell , skip);
            }

            curr[buyAllowed] = profit;
        }
        next = curr;
    }

    return curr[1];



}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();

    return solve(prices, n, fee);
}