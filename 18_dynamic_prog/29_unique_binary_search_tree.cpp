// https://leetcode.com/problems/unique-binary-search-trees/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// recursive approach- my solution:
// given the array 1 to n.
// choose each element as root one by one.
// now three cases arise , choosen element is left corner, middle or right corner.
// if left corner, then take that element as an entity and the whole right sub array as other entity.
// and recursively solve for all the sub array.
// similarly for middle and right corner.
// after that add up all the combinations.
// this approach has been developed by dry run on n=3.

//2d dp is being applied for this approach: space comp: O(N^2).

int solve(int s, int e, vector<vector<int>>& dp){
    //base case
    if(e-s<1) return 1;

    if(dp[s][e]!=-1) return dp[s][e];


    //rc
    int ans = 0;//ans will come by adding all the soln. by making all of them roots one by one.
    for(int i=s; i<=e; i++){
        //take i as root.
        //3 cases
        if(i==s){
            ans+= 1*solve(s+1, e, dp);
        }
        else if(i==e) ans+= 1*solve(s, e-1, dp);
        else ans+= 1*solve(s, i-1, dp)*solve(i+1, e, dp);
    }


    return dp[s][e] = ans;
}


int numTrees(int n) {
    if(n<=1) return 1;
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(1, n, dp);
}



//babbar solution: 
//approach: TOP DOWN
//we donot need to bother with the number on the nodes
//we just need to bother with the number of nodes.
//so by observation we came to know , when we make each ith element root
//then it is divided into two sub problems, (i-1)elements and n-i elements
//so f(i, n) = f(0, i-1) * f(0, n-i).
//time complexity: O(n^2).
//space complexity: O(N)+O(N)

int solve(int n, vector<int>& dp){
    //base case
    if(n<=1) return 1;
    
    if(dp[n]!=-1) return dp[n];
    //rc
    int ans = 0;
    for(int i=1; i<=n; i++){
        //consider i as root.
        ans+=(1*solve(i-1, dp)*solve(n-i, dp));
    }

    return dp[n] = ans;
}

int numTrees(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}


//B) tabulation:
int solve(int n){
    //make dp
    vector<int> dp(n+2, 0);

    //analyze base case and initialize dp
    dp[0]=dp[1]=1;
    dp[2] = 2;

    for(int n1 = 3; n1<=n; n1++){
        for(int i=1; i<=n1; i++){
            //consider i as root.
            dp[n1]+=(1*dp[i-1]*dp[n1-i]);
        }
    }
    
    return dp[n];
}

int numTrees(int n) {
    return solve(n);
}
//O(n^n) time complexity
//O(n) space.

//CATALAN NUMBERS. - not the best solution.
// if we see the solutions: - 
//f(1) = 1
//f(2) = 2
//f(3) = 5
//f(4) = 14.
//this is the catalan number series.
// In combinatorial mathematics, the Catalan numbers are a sequence of natural numbers that
//  occur in various counting problems, often involving recursively defined objects.

//formula for catalan numbers = (2n)!/[(n+1)!n!].

//but this solution cannot run for bigger numbers. so our previous solution is the best

int fact(int n, vector<int> &dp){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];

    //rc
    return dp[n] = n*fact(n-1, dp);
}

int numTrees(int n) {
    vector<int> dp(2*n+1, -1);
    //using the super optimization - catalan numbers
    int catalan = fact(2*n, dp)/(fact(n+1, dp)*fact(n, dp));

    return catalan;
}
