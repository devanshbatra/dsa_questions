// https://leetcode.com/problems/minimum-sideway-jumps/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//recursion logic: I have throught this approach myself.
// as we start from the 0th index second lane we , at ever index we see the next index at currLane has an obstacle or not.
// if it do not have any obstacle then no side jump required and solve for next index return 0+solve(ind+1, currLane).
// if there is an obstacle on the next lane then we have two options(other two lanes to switch as it is guaranteed that they
// would not have obstacles ahead).
// as we need to find the path with min side jumps so take both options by using a for loop(see that that lane at currIndex do
// not contain an obstacle.)
// return the ans with the minimum solution + 1(for the curr jump).


//dp logic: we can see that index and currLane changes its a 2d dp.

int solve(vector<int>& obstacles, int n, int index, int currLane, vector<vector<int>>& dp){
    //base case
    if(index==n-1){
        return 0;
    }

    if(dp[index][currLane]!=-1) return dp[index][currLane];

    // rc
    //obstacle ahead
    if(obstacles[index+1]==currLane){
        int mini = INT_MAX;
        for(int i=1; i<=3; i++){
            if(i!=currLane && obstacles[index]!=i){
                mini = min(mini, 1+solve(obstacles, n, index+1, i, dp));
            }
        }
        return dp[index][currLane] = mini;
    }
    //no obstacle ahead
    else{
        return dp[index][currLane] = 0+solve(obstacles, n, index+1, currLane, dp);
    }

}

int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    vector<vector<int>> dp(n, vector<int>(4, -1)); //[index][lane]
    return solve(obstacles, n, 0, 2, dp);
}

//tc: O(N*numberOfLanes*numberOfLanes)~~O(N). as hum worst case mein har index ke liye , har index ke liye, agar obstacle aaye to uske bhi
// andar har way ko try karte hain
//sc: O(n*3)==> O(n). as dp array mein 3 size to constant he hai.

//B) tabulation - basic steps follow karo aur ho jaayega.
// last mein starting point ko he return kar dena as this is reverse of top down.
int solve(vector<int>& obstacles, int n){
    //bottom up
    //step 1: make the dp of adequate size.
    vector<vector<int>> dp(n, vector<int>(4, 0));

    //step 2: analyze base case and initialize dp
    for(int i=1; i<=3; i++){
        dp[n-1][i]=0;
    }

    //step 3: start from the next of base case start filling the dp
    for(int index = n-2; index>=0; index--){
        for(int lane = 1; lane<=3; lane++){
            if(obstacles[index+1]==lane){
                int mini = INT_MAX;
                for(int i=1; i<=3; i++){
                    if(i!=lane && obstacles[index]!=i){
                        mini = min(mini, 1+dp[index+1][i]);
                    }
                }
                dp[index][lane] = mini;
            }
            //no obstacle ahead
            else{
                dp[index][lane] = 0+dp[index+1][lane];
            }
        }
    }


    return dp[0][2];

}

int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    return solve(obstacles, n);
}


//C) space optimization: 
// if we see, our ans dp[i][lane] depends on dp[i+1][1 or 2 or 3];
// so we are just using two 3X1 rows
// so our space could be reduced to O(1) only.
// see how
int solve(vector<int>& obstacles, int n){

    //keval do he rows se kaam ho jaayega
    vector<int> curr(4);
    vector<int> prev(4);

    for(int i=1; i<=3; i++){
        prev[i]=0;
    }

    for(int index = n-2; index>=0; index--){
        for(int lane = 1; lane<=3; lane++){
            if(obstacles[index+1]==lane){
                int mini = INT_MAX;
                for(int i=1; i<=3; i++){
                    if(i!=lane && obstacles[index]!=i){
                        mini = min(mini, 1+prev[i]);
                    }
                }
                curr[lane] = mini;
            }
            //no obstacle ahead
            else{
                curr[lane] = 0+prev[lane];
            }
        }
        prev = curr;
    }

    return prev[2];

}

int minSideJumps(vector<int>& obstacles) {
    int n = obstacles.size();
    return solve(obstacles, n);
}

//sc: O(1).