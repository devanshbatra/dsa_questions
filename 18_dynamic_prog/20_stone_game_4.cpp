// https://leetcode.com/problems/stone-game-iv/description/

//recursion approach:
//IN these types of questions we need to play from the side of one player.
//lets say we play with alice here.
//do it recursively.
// at every step check if there is a chance of win or not.
// if not then return false.
//exactly, see the recursive function, you will come to know.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//A) top down.
int solve(int n, vector<int>& dp){
    //base cases
    //if n==0 means alice has no stones to pick and she has lost
    if(n==0) return false;

// I think there is no need to check for if(n==1) and as well as for if(n is perfect square). 
// as when we check if(n-(i x i)) - then we are able to handle all the other cases.
// for example if n is perfect square lets say 4.
// then we will take i from --> 1 to (i x i)<=n i.e. i--> 1 to 2.
// and when i==2, (i*i) = 4, and , n-(i x i) => 4-4 => 0 , which we have already handled as our only base case.

    if(dp[n]!=-1) return dp[n];

    //rc
    
    //now check different possiblities of perfect squares
    for(int i=1; i*i <= n; i++){
        bool prevSoln = solve( n-(i*i), dp );//who will win if pile has n-(i*i) stones.

        // If Alice losses the game when piles contains n-(i*i) stones. Then Alice will definately win
        // if piles contains "n" stones. (by picking remaining i*i stones)
        //matlab wo n-(i*i) hamne bob pe daal dia.
        if(prevSoln==false) return dp[n] = true;

    }

    //if till now return true has not happened that means for this n jeetna is not possible
    return dp[n] = false;

}

bool winnerSquareGame(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}

//B) tabulation.
int solve(int n){
    //1) make dp of adequate size.
    vector<int> dp(n+1);

    //2) analyze base case
    dp[0] = 0;

    //3) start from next of base case
    for(int num = 1; num<=n; num++){
        for(int i=1; i*i <= num; i++){
            bool prevSoln = dp[num-(i*i)];//who will win if pile has n-(i*i) stones.

            // If Alice losses the game when piles contains n-(i*i) stones. Then Alice will definately win
            // if piles contains "n" stones. (by picking remaining i*i stones)
            //matlab wo n-(i*i) hamne bob pe daal dia.
            if(prevSoln==0) dp[num] = 1;

        }

    }

    return dp[n];

}

bool winnerSquareGame(int n) {
    return solve(n);
}

//C) space optimization.
//space optimization is not possible here as our dp[n] depends on dp[n-(i*i)] and i is hovering from 1 to near 
// square root of n.