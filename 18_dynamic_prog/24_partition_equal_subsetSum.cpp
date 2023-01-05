// https://leetcode.com/problems/partition-equal-subset-sum/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// This problem belongs to a particular pattern namely distinct ways
//FOLLOWING QUESTION USES BEST APPROACHES AS WE ARE GOING ONLY TILL TARGET NOT THE WHOLE SUM.
//since we should have equal sum on both the sides.
//so it is clear that equal sum would be half of actual sum.
//so this problem can be derived to a shorter problem to choose a subset with sum = totSum/2.
//if totSum is odd then no partition can be made.

//at every index we will choose whether to include this or not.
//at base we check if target is reached or not.

// A) top down
int solve(vector<int>& nums, int n, int index, int sum, int target, vector<vector<int>>& dp){
    //base case
    if(index==n){
        if(sum==target){
            cout<<"returning true for : "<<sum<<endl;
            return true;
        }
        else return false;
    }
    if(sum>target) return 0; //agar sum target se bada nikal gaya and only positive integers are there.

    if(dp[index][sum]!=-1) return dp[index][sum];

    //rc
    bool include = solve(nums, n, index+1, sum+nums[index], target, dp);
    bool exclude = solve(nums, n, index+1, sum, target, dp);

    if(include==true || exclude==true) return dp[index][sum] = true;
    else return dp[index][sum] = false;


}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum= 0;
    for(auto& i: nums){
        sum+=i;
    }
    if(sum%2!=0) return false; //it is already understood that if sum is odd then 2x cannot be equal to that sum.
    int target=sum/2;
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    return solve(nums, n, 0, 0, target, dp);
}
//time = O(n^square). and space = O(n^square).

//Tabulation
int solve(vector<int>& nums, int n, int target){

    vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));

    //analyze base case.
    dp[n][target] = 1;

    //next of base case
    for(int index = n-1; index>=0; index--){
        for(int sum=0; sum<=target; sum++){
            bool include = false;
            if(sum+nums[index]<=target)
                include = dp[index+1][sum+nums[index]];
            bool exclude = dp[index+1][sum];

            if(include==true || exclude==true) dp[index][sum] = true;
            else dp[index][sum] = false;
        }
    }

    return dp[0][0];//ham 0 index aur 0 sum se aaye the.
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum= 0;
    for(auto& i: nums){
        sum+=i;
    }
    if(sum%2!=0) return false; //it is already understood that if sum is odd then 2x cannot be equal to that sum.
    int target=sum/2;
    return solve(nums, n, target);
}

//C) space optimization - 2 rows se ho gaya.
int solve(vector<int>& nums, int n, int target){

    // vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));

    vector<bool> currRow(target+1, 0);
    vector<bool> nextRow(target+1, 0);
    nextRow[target] = 1;


    //next of base case
    for(int index = n-1; index>=0; index--){
        for(int sum=0; sum<=target; sum++){
            bool include = false;
            if(sum+nums[index]<=target)
                include = nextRow[sum+nums[index]];
            bool exclude = nextRow[sum];

            if(include==true || exclude==true) currRow[sum] = true;
            else currRow[sum] = false;
        }
        nextRow = currRow;
    }

    return currRow[0];//ham 0 index aur 0 sum se aaye the.
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum= 0;
    for(auto& i: nums){
        sum+=i;
    }
    if(sum%2!=0) return false; //it is already understood that if sum is odd then 2x cannot be equal to that sum.
    int target=sum/2;
    return solve(nums, n, target);
}


//D) space optimization -2 , single row se ho gaya. space comp = O(sum/2).
int solve(vector<int>& nums, int n, int target){

    // vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));

    vector<bool> currRow(target+1, 0);
    currRow[target] = 1;


    //next of base case
    for(int index = n-1; index>=0; index--){
        for(int sum=0; sum<=target; sum++){
            bool include = false;
            if(sum+nums[index]<=target)
                include = currRow[sum+nums[index]]; //kyoki right wale ko access kar rhe h, so old value new value problem bhi nhi aayegi.
            bool exclude = currRow[sum];

            if(include==true || exclude==true) currRow[sum] = true;
            else currRow[sum] = false;
        }
    }

    return currRow[0];//ham 0 index aur 0 sum se aaye the.
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum= 0;
    for(auto& i: nums){
        sum+=i;
    }
    if(sum%2!=0) return false; //it is already understood that if sum is odd then 2x cannot be equal to that sum.
    int target=sum/2;
    return solve(nums, n, target);
}