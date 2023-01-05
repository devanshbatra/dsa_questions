// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

#define mod 1000000007
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// approach: This problem belongs to a particular pattern namely distinct ways.
//understand by dry run below.
// here see for example we have n=3, k=2, target = 6.
// now we have n=3 positions _ _ _
// and we can fill 2 characters "1" and "2" in them.
// what are total posibilities.
//      111, 112, 121, 122, 211, 212, 221, 222.
// sum   3,   4,  4,   5,    4,   5,   5,   6.
// since we got sum = target= 6 in only one case so our ans would be 1.
// similar approach we would be implementing using recursion.
// at every position travel all the posibilites and call solve function for next position with increased sum.
// after reaching end position , check if sum==target then return 1.
// see ss.


//dp logic: since here two parameters position and sum are changing. so 2d dp would be used.

// A) TOP DOWN - rec+memo
//utility func for mod
int sumMod(int a , int b){
    return (a%mod + b%mod)%mod;
}

int solve(int position, int target, int n, int faces, int sum, vector<vector<int>> & dp ){
    //base case
    if(position>=n){
        if(sum==target) return 1;
        else return 0;
    }
    // if(sum==target) return 0; optimization
    if(dp[position][sum]!=-1) return dp[position][sum];
    //rc
    int ans = 0;
    //for this position, we have k options
    for(int i=1; i<=faces ; i++){
        ans= sumMod(ans, solve(position+1, target, n, faces, sum+i, dp));
    }
    return dp[position][sum] = ans;
}

int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n, vector<int>(n*k, -1)); //position, sum. (max sum could be n*k)
    return solve(0, target, n, k, 0, dp);
}
//time complexity: O(target*n).
//sc: O(target*n).

// bottom up approach
//utility func for mod
int sumMod(int a , int b){
    return (a%mod + b%mod)%mod;
}

int solve(int target, int n, int faces){

    //position 0-->n and sum-->0 to n*k.
    //for bottom up we will go from with base case included->n to 0.
    vector<vector<int>> dp(n+1, vector<int>((n*faces)+1, 0));

    //analyze base case - initialize dp
    //for position==n, and sum=target ->1 , and sum!=target ->0
    for(int i=0; i<=n*faces; i++){
        if(i==target) dp[n][i] = 1;
        else dp[n][i] = 0;
    }


    //go from next of base case

    for(int position = n-1; position>=0; position--){
        for(int sum=0; sum<=n*faces; sum++){ //target tak jaane se he kaam ho jaata as an optimization.
            int ans = 0;
            //for this position, we have k options
            for(int i=1; i<=faces ; i++){
                if(sum+i > n*faces) ans=0;
                else ans= sumMod(ans, dp[position+1][sum+i]);
            }
            dp[position][sum] = ans;
        }
    }

    return dp[0][0];

}

int numRollsToTarget(int n, int k, int target) {
    return solve(target, n, k);
}



//C) space optimization - this can be done with just two rows.
int sumMod(int a , int b){
    return (a%mod + b%mod)%mod;
}
int solve(int target, int n, int faces){
    

    vector<int> currRow((n*faces)+1, 0);
    vector<int> nextRow((n*faces)+1);
    for(int i=0; i<=n*faces; i++){
        if(i==target) nextRow[i] = 1;
        else nextRow[i] = 0;
    }


    //go from next of base case

    for(int position = n-1; position>=0; position--){
        for(int sum=0; sum<=n*faces; sum++){
            int ans = 0;
            //for this position, we have k options
            for(int i=1; i<=faces ; i++){
                if(sum+i > n*faces) ans=0;
                else ans= sumMod(ans, nextRow[sum+i]);
            }
            currRow[sum] = ans;
        }
        nextRow = currRow;
    }

    return currRow[0];

}

int numRollsToTarget(int n, int k, int target) {
    return solve(target, n, k);
}

//since we donot need to