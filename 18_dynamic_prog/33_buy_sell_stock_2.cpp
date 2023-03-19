// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//approach: har index pe we have three options, either buy or sell or ignore.

//hame ek cheez ka dhyaan rakhna padega ki we can do BSBSBS.. like this we cannot do B and B again.
//so uske liye ek buyAllowed parameter le skte hain.

//you know when i buy at 1 and sell at 5 the profit+= (5-1). => profit+=(5+)
//so basically jb m koi item buy krta hun to profit mein se minus krta hun
//aur jab koi item sell karta hun to profit mein add karta hun.

//top down approach.
int solve(vector<int>& prices, int n, int buyAllowed, int index, vector<vector<int>>& dp ){
    //base case
    if(index==n) return 0;

    if(dp[index][buyAllowed]!=-1) return dp[index][buyAllowed];

    //rc
    //if buy allowed
    if(buyAllowed){
        int buy = -prices[index] + solve(prices, n, 0, index+1, dp);
        int notBuy = solve(prices, n, 1, index+1, dp);
        return dp[index][buyAllowed] = max(buy, notBuy);
    }
    //if buy not allowed and sell allowed.
    else{
        int sell  = prices[index]+ solve(prices, n, 1, index+1, dp);
        int notSell = 0 + solve(prices, n, 0, index+1, dp);
        return dp[index][buyAllowed] = max(sell, notSell);
    }
    
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(prices, n, 1, 0, dp);
}

//B) tabulation: bottom up approach.
int solve(vector<int>& prices, int n){

    //make dp
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    //analyze base case - covered;

    //start from the next of base case. ie. index = n-1 se start hoga.
    //index pehle 0 se n gaya tha, ab n se 0 jayega.

    for(int index = n-1; index>=0; index--){
        for(int buyAllowed = 0; buyAllowed<2; buyAllowed++){
            if(buyAllowed){
                int buy = -prices[index] + dp[index+1][0];
                int notBuy = dp[index+1][1];
                dp[index][buyAllowed] = max(buy, notBuy);
            }
            //if buy not allowed and sell allowed.
            else{
                int sell  = prices[index]+ dp[index+1][1];
                int notSell = 0 + dp[index+1][0];
                dp[index][buyAllowed] = max(sell, notSell);
            }
        }
    }

    return dp[0][1];
    
}
//time complexity: O(n)
//space complexity: O(N). bcoz: buyAllowed mein toh bas 2 he rows hain.

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return solve(prices, n);
}

//C) space optimization: here buy,notbuy, sell , notSell: all just depend on the second row.
// and buyAllowed is of just 2 columns, so space complexity can be reduced to just O(1).
int solve(vector<int>& prices, int n){

    //make rows
    vector<int> currRow(2, 0);
    vector<int> nextRow(2, 0);


    for(int index = n-1; index>=0; index--){
        for(int buyAllowed = 0; buyAllowed<2; buyAllowed++){
            if(buyAllowed){
                int buy = -prices[index] + nextRow[0];
                int notBuy = nextRow[1];
                currRow[buyAllowed] = max(buy, notBuy);
            }
            //if buy not allowed and sell allowed.
            else{
                int sell  = prices[index]+ nextRow[1];
                int notSell = 0 + nextRow[0];
                currRow[buyAllowed] = max(sell, notSell);
            }
        }
        nextRow = currRow;
    }

    return currRow[1];
    
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return solve(prices, n);
}