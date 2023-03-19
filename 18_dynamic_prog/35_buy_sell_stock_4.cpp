// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// initial approach: pichle part se bas ek 2 ki jagah k karna hai.
//top down
int solve(vector<int>& prices, int n, int k, int index, int buyAllowed, int transactions, vector<vector<vector<int>>>& dp){
    //base case
    if(index==n || transactions==k){
        return 0;
    }

    if(dp[index][buyAllowed][transactions]!=-1) return dp[index][buyAllowed][transactions];

    //rc
    int profit;
    if(buyAllowed){
        int buy = -prices[index] + solve(prices, n, k, index+1, 0, transactions, dp);
        int skip = solve(prices, n, k, index+1, 1, transactions, dp);
        profit = max(buy, skip);
    }
    else{ //if buy not allowed
        int sell = prices[index]+ solve(prices, n, k, index+1, 1, transactions+1, dp);
        int skip = solve(prices, n, k, index+1, 0, transactions, dp);
        profit = max(sell, skip);
    }
    return dp[index][buyAllowed][transactions] = profit;
}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1))); //index, buyAllowed, transactions
    return solve(prices, n, k, 0, 1, 0, dp);
}
//tc: O(N*k) space complexity: O(N*K).

//tabulation skipped as ye soln. pura part 3 se he copied h.

//space optimized solution:
//time complexity: O(n*k), space complexity: O(K).
int solve(vector<int>& prices, int n, int k){
        
    vector<vector<int>> currMatrix(3, vector<int>(k+1, 0));
    vector<vector<int>> nextMatrix(3, vector<int>(k+1, 0));

    //analyze base case - covered

    //start from next of the base case
    //in top down index was from 0 to n
    // now we will do it from n-1 to 0.(as n to base case he hai.).

    for(int index=n-1; index>=0; index--){
        for(int buyAllowed = 0; buyAllowed<2; buyAllowed++){
            for(int transactions = k-1; transactions>=0; transactions--){ //trans = k to base case mein he cover ho gaya h.
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

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    return solve(prices, n, k);
}

//ANOTHER METHOD of solving it would be using number of operations- which will use 2d dp.
//approach: isme har buy ya sell ko ek operation count karenga.
//if total 2 transactions are allowed, then total 2*k operations are allowed.
//0-b 1-s 2-b 3-s.
//fayda: we do not need to keep track of "buyAllowed"
//as when no. of operations is even means buy allowed. and odd- buy not Allowed.
//A) top down
int solve(vector<int>& prices, int n, int k, int index, int operations, vector<vector<int>>& dp){
    //base case
    if(index==n || operations==2*k) return 0;

    if(dp[index][operations]!=-1) return dp[index][operations];

    //rc
    //if buy allowed
    int profit;
    if(operations%2==0){
        int buy = -prices[index] + solve(prices, n, k, index+1, operations+1, dp);
        int skip = 0 + solve(prices, n, k, index+1, operations, dp);
        profit = max(buy, skip);
    }
    else{ //buy not allowed
        int sell = prices[index] + solve(prices, n, k, index+1, operations+1, dp);
        int skip = 0 + solve(prices, n, k, index+1, operations, dp);
        profit = max(sell, skip);
    }

    return dp[index][operations] = profit;

}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2*k, -1));

    return solve(prices, n, k, 0, 0, dp);
}

//B) bottom up
int solve(vector<int>& prices, int n, int k){

    vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));


    //base case - covered
    //in top down we go index from 0 to n and operations from 0 to 2k.
    //now index n to 0 and operations from 2k to 0.

    //from next of base case
    for(int index=n-1; index>=0; index--){
        for(int operations=2*k-1; operations>=0; operations--){
            int profit;
            if(operations%2==0){
                int buy = -prices[index] + dp[index+1][operations+1];
                int skip = 0 + dp[index+1][operations];
                profit = max(buy, skip);
            }
            else{ //buy not allowed
                int sell = prices[index] + dp[index+1][operations+1];
                int skip = 0 + dp[index+1][operations];
                profit = max(sell, skip);
            }

            dp[index][operations] = profit;
        }
    }

    return dp[0][0];

}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();


    return solve(prices, n, k);
}

//C) space optimization - sc: O(k). time comp: O(n*k).
int solve(vector<int>& prices, int n, int k){


    vector<int> currRow(2*k+1, 0);
    vector<int> nextRow(2*k+1, 0);


    //base case - covered
    //in top down we go index from 0 to n and operations from 0 to 2k.
    //now index n to 0 and operations from 2k to 0.

    //from next of base case
    for(int index=n-1; index>=0; index--){
        for(int operations=2*k-1; operations>=0; operations--){
            int profit;
            if(operations%2==0){
                int buy = -prices[index] + nextRow[operations+1];
                int skip = 0 + nextRow[operations];
                profit = max(buy, skip);
            }
            else{ //buy not allowed
                int sell = prices[index] + nextRow[operations+1];
                int skip = 0 + nextRow[operations];
                profit = max(sell, skip);
            }

            currRow[operations] = profit;
        }
        nextRow = currRow;
    }

    return currRow[0];

}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    return solve(prices, n, k);
}


//super optimized: 
int solve(vector<int>& prices, int n, int k){

    vector<int> currRow(2*k+1, 0);


    //base case - covered
    //in top down we go index from 0 to n and operations from 0 to 2k.
    //now index n to 0 and operations from 2k to 0.

    //from next of base case
    for(int index=n-1; index>=0; index--){
        for(int operations=0; operations<=2*k-1; operations++){
            int profit;
            if(operations%2==0){
                int buy = -prices[index] + currRow[operations+1];
                int skip = 0 + currRow[operations];
                profit = max(buy, skip);
            }
            else{ //buy not allowed
                int sell = prices[index] + currRow[operations+1];
                int skip = 0 + currRow[operations];
                profit = max(sell, skip);
            }

            currRow[operations] = profit;
        }
    }

    return currRow[0];

}

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    return solve(prices, n, k);
}