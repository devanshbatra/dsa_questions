// https://leetcode.com/problems/pizza-with-3n-slices/description/

//approach : same as house robbery 2.
//as we can see in the function that two parameters are changing their states, namesly curr and count.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//top down approach- recursion + memoization.
int solve(vector<int>&slices, int curr, int endIndex, int count, vector<vector<int>>& dp){
    //base case
    if(curr>endIndex || count==0 ) return 0; //second condition is because kahin wo n/3 se zyada elements na lele.
    // like given in the example also after taking 4(3,5-by friend) , it is left with 6, 1, 2. ab 6 ko agar leta hai.
    // so kahin 2 ko bhi na lele.(kyoki wo ek naya circle bana raha hai.).

    if(dp[curr][count]!=-1) return dp[curr][count];    

    //rc
    //include current
    int include = slices[curr]+solve(slices,curr+2, endIndex, count-1, dp);
    //exclude current
    int exclude = 0+ solve(slices, curr+1, endIndex, count, dp);

    return dp[curr][count] = max(include, exclude);
}


int maxSizeSlices(vector<int>& slices) {
    
    //take first element
    int n = slices.size();
    vector<vector<int>> dp1(n, vector<int>((n/3)+1, -1));

    int case1 = solve(slices, 0, n-2, n/3, dp1);
    //take last element
    vector<vector<int>> dp2(n, vector<int>((n/3)+1, -1));
    int case2 = solve(slices, 1, n-1, n/3, dp2);

    return max(case1, case2);

}

//tc: O(N^square) as variables hai.
//sc: O(n*n/3)  = O(N^square).

//tabulation method
    
int solve(vector<int>&slices, int n, int s, int endIndex){

    //make dp
    vector<vector<int>> dp(n+3, vector<int>((n/3)+1, 0));//curr, count.


    //start from the next of base case
    for(int curr = endIndex; curr>=s; curr--){
        for(int cnt = 1; cnt<=n/3; cnt++){
            //include current
            int include = slices[curr]+dp[curr+2][cnt-1];
            //exclude current
            int exclude = 0+ dp[curr+1][cnt];

            dp[curr][cnt] = max(include, exclude);
        }
    }

    return dp[s][n/3];

}


int maxSizeSlices(vector<int>& slices) {
    
    int n = slices.size();

    //take first element
    int case1 = solve(slices, n, 0, n-2);

    //take last element
    int case2 = solve(slices, n, 1, n-1);

    return max(case1, case2);

}


//C) space optimization.
//space optimization method

int solve(vector<int>&slices, int n, int s, int endIndex){


    vector<int> currRow((n/3)+1, 0);
    vector<int> next((n/3)+1, 0);
    vector<int> nextToNext((n/3)+1, 0);


    //start from the next of base case
    for(int curr = endIndex; curr>=s; curr--){
        for(int cnt = 1; cnt<=n/3; cnt++){
            //include current
            int include = slices[curr]+nextToNext[cnt-1];
            //exclude current
            int exclude = 0+ next[cnt];

            currRow[cnt] = max(include, exclude);
        }
        nextToNext = next;
        next = currRow;
    }

    return currRow[n/3];

}


int maxSizeSlices(vector<int>& slices) {
    
    int n = slices.size();

    //take first element
    int case1 = solve(slices, n, 0, n-2);

    //take last element
    int case2 = solve(slices, n, 1, n-1);

    return max(case1, case2);

}
//tc:O(n^square).
//sc: O(n).