// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//good question.

//approach: do not try to build the tree, apply some less brain, see as a bigger level view.
//here can can do this by dividing the array and putting the max of left and right subarray int he current node.
//the subarrays will act as subproblems which would be handeled by the recursion.

//for finding the max from i to j we have precomputed it.

//A) top down approach.
int solve(int s, int e, vector<vector<int>> & maxArr, vector<vector<int>> & dp){
    //base case
    if(s>=e) return 0;

    if(dp[s][e]!=-1) return dp[s][e];
    //rc
    //we have to make partitions from i=0 to i=n-2
    // and return the minimum ans
    int ans = INT_MAX;
    for(int i=s; i<=e-1; i++){
        //make partition after ith element
        int part = (maxArr[s][i] * maxArr[i+1][e]) + solve(s, i, maxArr, dp) + solve(i+1, e, maxArr, dp);
        ans = min(ans, part);
    }

    return dp[s][e] = ans;
}

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();

    //precomputation of max values.
    vector<vector<int>> maxArr(n, vector<int>(n+1, 0));
    for(int i=0; i<n; i++){
        maxArr[i][i] = arr[i];
        for(int j=i+1; j<n; j++){
            if(arr[j]>maxArr[i][j-1]) maxArr[i][j] = arr[j];
            else maxArr[i][j] = maxArr[i][j-1];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(0, n-1, maxArr, dp);
}
//tc: O(n^3)
//sc: 3* O(n^2). for recursive stack, for maxArr, for dp

// B) Bottom up: tabulation
int solve(int n, vector<vector<int>> &maxArr){

    //bottom up approach
    //in top down s was moving from 0 to n.
    //and e was moving from n to 0.
    //now move s from n to 0.
    // and move e from 0 to n.
    // but we know e should not be less than s, so we will start e from s only.

    vector<vector<int>> dp(n, vector<int>(n, 0));

    

    for(int s = n-1; s>=0; s--){
        for(int e = s; e<n; e++ ){
            if(s==e) continue;  //important step : warna aage jaakr dp[s][e] ko he INT_MAX bana dega.
            int ans = INT_MAX;
            for(int i=s; i<=e-1; i++){
                //make partition after ith element
                int part = (maxArr[s][i] * maxArr[i+1][e]) + dp[s][i] + dp[i+1][e];
                ans = min(ans, part);
            }

            dp[s][e] = ans;
        }
    }

    return dp[0][n-1];

}

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();

    //precomputation of max values.
    vector<vector<int>> maxArr(n, vector<int>(n+1, 0));
    for(int i=0; i<n; i++){
        maxArr[i][i] = arr[i];
        for(int j=i+1; j<n; j++){
            if(arr[j]>maxArr[i][j-1]) maxArr[i][j] = arr[j];
            else maxArr[i][j] = maxArr[i][j-1];
        }
    }


    return solve(n, maxArr);
}
//tc: O(n^3)
//sc: 2* O(n^2). for maxArr, for dp