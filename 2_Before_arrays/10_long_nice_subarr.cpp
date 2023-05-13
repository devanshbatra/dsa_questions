 //BIT MAP PATTERN + two pointer.
// https://leetcode.com/problems/longest-nice-subarray/description/
//involves finding binary of each number and then seeing the overlap of set bits.

//This is a standard two pointer approach for subarray(continuous elements): 
//see these question: https://leetcode.com/problems/maximum-number-of-robots-within-budget/submissions/923455597/


//we will develop a bit map array of size 32, which will store the number of set bits at diff. positons.
//we will use two pointers.
//both will start from 0. we will start to increase the right (until we find more than one bits set at a 
//particular position.)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> bits(32, 0);
    int ans = 1;
    int l = 0;
    for(int i=0; i<n; i++){
        
        bool found = false;
        //finding it binary- good approach(standard).
        for(int k=0; k<=31; k++){
            if(nums[i]&1<<k){
                bits[k]++;
                if(bits[k]>1){
                    found = true;
                }
            }
        }

        if(!found){
            ans = max(ans, i-l+1);
        }
        else{
            //ek positon pe >1 set bits found now we need to increase l
            while(l<=i){
                //remove influence of l.
                for(int k=0; k<=31; k++){
                    if(nums[l]&1<<k){
                        bits[k]-=1;
                    }
                }
                l++;
                //now check if still two set bits at one position.
                bool stillBits = false;
                for(int i=0; i<=31; i++){
                    if(bits[i]>1) stillBits = true;
                }
                if(!stillBits) break;
            }

        }

    }

    return ans;



}

//time complexity: roughly O(n*32) ~ O(n).