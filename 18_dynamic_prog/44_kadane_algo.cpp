//Kadanes algo is used to find the maximum sum subarray
//it is an iterative dynamic programming approach.
// https://leetcode.com/problems/maximum-subarray/description/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//using kadanes algorithm
//intuition: if all the elements of the array are negative then we just need to return the maximum element.
//so, if the sum is coming negative then discard the sum by just recording the maximum.

int maxSubArray(vector<int>& nums) {
    int curr_max = 0;
    int maxi = INT_MIN;
    int n = nums.size();

    for(int i=0; i<n; i++){
        curr_max+=nums[i];

        maxi = max(curr_max, maxi);
        if(curr_max<0) curr_max = 0;
    }

    return maxi;
}

