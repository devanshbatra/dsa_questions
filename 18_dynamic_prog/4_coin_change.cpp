#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// https://leetcode.com/problems/coin-change/description/

//at every amount / step we would have k paths (if k coins are available).

//A) top down approach - rec + memoization.
//recursive approach
//at every step: 
// think as if we would try all of the coins and will take the path which yeilds the minimum result.
// so take a variable minimum and now traverse all the coins.
// the coin ans for each iteration would be equal to f(n-currCoinVal)[for the path down if we take this coin] + 1( for this coin )
int solve(int amt, vector<int>& coins, vector<int>& dp){
    if(amt<0) return INT_MAX;//not possible //because baad mein hum minimum lenge to usme ye wala path reject ho jayega.
    if(amt == 0) return 0; //for 0 amt no coins are needed.
    //make mini variable
    int mini = INT_MAX;
    if(dp[amt]!=-1) return dp[amt];
    //fetch out ans for all coins
    for(auto coinValue: coins){
        int ans = solve(amt-coinValue, coins, dp);
        
        //update mini
        if(ans!=INT_MAX) mini = min( ans + 1 , mini); //ans plus one means iske baad ke path ka ans plus iska ans.
    }
    dp[amt] = mini;
    return mini;
    
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);
    int ans = solve(amount, coins, dp);
    if(ans==INT_MAX) return -1;// if int_max is returned as a whole, means har path se negative mein he jaa rha hai test case means possible he nhi h in coins se.
    else return ans;
}//tc: O(amount)., sc: O(n) + O(n).

//B) Bottom up approach with steps explained.
//tabulation method
int solve(vector<int>& coins, int n){
    //1) initialize dp
    vector<int> dp(n+1, INT_MAX);
    //2) set value in dp arr for base case
    dp[0] = 0;
    //3) traverse from next of base case towards the end till the final amount.
    for(int amt=1; amt<=n; amt++){
        //now we are solving for this amt
        //traverse all coins to see minimum
        for(auto coinVal: coins){
            //4) find curr value of dp based on the previously stored values in dp
            if( amt-coinVal>=0 && dp[amt-coinVal]!=INT_MAX) //1) condition : kahin negative na ho jaaye(negative ho gaya to possible nhi h), 2nd condition : kahin dp[amt-coinVal] intmax na ho warna plus 1 karne pr overflow kar jaayega.
                dp[amt] = min(dp[amt-coinVal]+1, dp[amt]);
        }
    }
    if(dp[n]==INT_MAX) return -1;
    else return dp[n];
}
int coinChange(vector<int>& coins, int amount) {
    
    return solve(coins, amount);
}

// tc: O(N).
// sc: O(N). for dp array.

//3) SPACE OPTIMIZATION : since here dp[i]  = min(dp[i], dp[amt-coinVal]) and amt-coinVal cannot be predicted.