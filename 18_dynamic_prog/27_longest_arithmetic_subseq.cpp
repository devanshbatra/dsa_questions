// https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

//for brute force:
// we will select every pair from the array possible- bcoz ap ke liye min 2 required h.
// these two pairs will be treated as the last two numbers of the ap.(or vice versa can also be done.)
// note the difference and see previous of this pair if same difference element exist
// increase the length of ap formed accordingly.
// at end update ans  = max(ans, currLength).
//tc: O(n^3 cube).
int solve(int arr[], int i, int j){
    //backward check.
    int diff = arr[j]-arr[i];
    
    int border = arr[i];
    int length = 2;
    
    for(int k = i-1; k>=0; k--){
        if(border-arr[k]==diff){
            border = arr[k];
            length++;
        }
    }
    
    return length;
    
    
}

int lengthOfLongestAP(int A[], int n) {
    
    if(n<=2) return n;
    
    int ans = 0;
    
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int currLength = solve(A, i, j);
            ans = max(ans, currLength);
        }
    }
    
    return ans;
}


//B) top down approach
//dp with hashing
int solve(vector<int>& nums, int diff, int borderIndex, vector<unordered_map<int, int>>& dp){
    
    //base case
    if(borderIndex<0){
        return 0;
    }

    if(dp[borderIndex].find(diff)!=dp[borderIndex].end()) return dp[borderIndex][diff];
    
    //rc
    int ans = 0;
    for(int j=borderIndex-1; j>=0; j--){
        if(nums[borderIndex]-nums[j]==diff){
            ans = max(ans, 1+solve(nums, diff, j, dp));
        }
    }

    return dp[borderIndex][diff] = ans;

}

int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    if(n<=2) return n;
    
    int ans = 0;
    
    vector<unordered_map<int, int>> dp(n+1); //we have made vector of maps here because as we do not know the exact length or
    //range of difference in dp. and for a particular borderIndex different differences can have different lengths(main reason).
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int diff = nums[j]-nums[i];
            int currLength = solve(nums, diff, i, dp);
            ans = max(ans, currLength+2);
        }
    }
    
    return ans;
}


//C) tabluation
int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    if(n<=2) return n;
    
    int ans = 0;

    unordered_map<int, int> dp[n+1];
    //tabulation mein sab ulta kar rhe hain.
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            int diff = nums[i]-nums[j]; //because i hamesha j se aage rahega.
            
            int currLength = 1;// initial length base case

            //check if the ans already in the dp
            if(dp[j].find(diff)!=dp[j].end()) currLength = dp[j][diff];


            dp[i][diff] = currLength+1; //hame 0 to j ki length to mil gayi but ab ham i ko bhi toh uss ap mein include karne jaa rhe hain. so that's why we have added 1.
            ans = max(ans, dp[i][diff]);
        }
    }
    
    return ans;
}


//D) there is also a spaced optimized approach, using the concept of 2b = a+c in an ap. But I can't find that 
// optimization.