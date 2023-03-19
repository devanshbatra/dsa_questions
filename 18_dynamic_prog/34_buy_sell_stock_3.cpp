// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//we will increase the transactions when the sell is done.
//rest is same as part 2.
//isme 3d dp use hogi because transaction bhi toh change ho raha hai.

//A) top down.
int solve(vector<int>& prices, int n, int index, int buyAllowed, int transactions, vector<vector<vector<int>>>& dp){
    //base case
    if(index==n || transactions==2){
        return 0;
    }

    if(dp[index][buyAllowed][transactions]!=-1) return dp[index][buyAllowed][transactions];

    //rc
    int profit;
    if(buyAllowed){
        int buy = -prices[index] + solve(prices, n, index+1, 0, transactions, dp);
        int skip = solve(prices, n, index+1, 1, transactions, dp);
        profit = max(buy, skip);
    }
    else{ //if buy not allowed
        int sell = prices[index]+ solve(prices, n, index+1, 1, transactions+1, dp);
        int skip = solve(prices, n, index+1, 0, transactions, dp);
        profit = max(sell, skip);
    }
    return dp[index][buyAllowed][transactions] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1))); //index, buyAllowed, transactions
    return solve(prices, n, 0, 1, 0, dp);
}
// tc: O(n^3)
// sc: O(N) + O(N) //because index ko chod kar baaki parameter to fixed length ke hain.

//B) bottom up
int solve(vector<int>& prices, int n){
    
    //tabulation.
    //make dp
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(3, 0)));

    //analyze base case - covered

    //start from next of the base case
    //in top down index was from 0 to n
    // now we will do it from n-1 to 0.(as n to base case he hai.).

    for(int index=n-1; index>=0; index--){
        for(int buyAllowed = 0; buyAllowed<2; buyAllowed++){
            for(int transactions = 1; transactions>=0; transactions--){ //trans = 2 to base case mein he cover ho gaya h.
                int profit;
                if(buyAllowed){
                    int buy = -prices[index] + dp[index+1][0][transactions];
                    int skip = dp[index+1][1][transactions];
                    profit = max(buy, skip);
                }
                else{ //if buy not allowed
                    int sell = prices[index]+ dp[index+1][1][transactions+1];
                    int skip = dp[index+1][0][transactions];
                    profit = max(sell, skip);
                }
                dp[index][buyAllowed][transactions] = profit;
            }
        }
    }

    return dp[0][1][0];
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return solve(prices, n);
}


//space optimization:
int solve(vector<int>& prices, int n){
    
    //tabulation.
    //make dp

    vector<vector<int>> currMatrix(3, vector<int>(3, 0));
    vector<vector<int>> nextMatrix(3, vector<int>(3, 0));

    //analyze base case - covered

    //start from next of the base case
    //in top down index was from 0 to n
    // now we will do it from n-1 to 0.(as n to base case he hai.).

    for(int index=n-1; index>=0; index--){
        for(int buyAllowed = 0; buyAllowed<2; buyAllowed++){
            for(int transactions = 1; transactions>=0; transactions--){ //trans = 2 to base case mein he cover ho gaya h.
                int profit;
                if(buyAllowed){
                    int buy = -prices[index] + nextMatrix[0][transactions];
                    int skip = nextMatrix[1][transactions];
                    profit = max(buy, skip);
                }
                else{ //if buy not allowed
                    int sell = prices[index]+ nextMatrix[1][transactions+1];
                    int skip = nextMatrix[0][transactions];
                    profit = max(sell, skip);
                }
                currMatrix[buyAllowed][transactions] = profit;
            }
            nextMatrix = currMatrix;
        }
    }

    return currMatrix[1][0];
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return solve(prices, n);
}
//sc: O(1) : 3X3 ke do matrix he toh use ho rhe hain.