//bit manip good question.
// https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long beautifulSubarrays(vector<int>& nums) {
    
    //observation 1: 
    //since we are asked to compare if they have kth bit and if they have then substract 2^k from both.
    //substracting 2^k in bit manip if you observe means removing the kth bit only.
    //so basically we need to make both of number zero by removing the set bits,
    //now for that the zor of all the numbers in the subarray should be zero.
    //why?
    //because when you zor all and if all set bits collide, then 1 xor 1 = 0, and other bits would be 0 only , 0 xor 0 = 0.
    //so all will be 0 with that.
    
    //so problem reduced to finding substrings with xor = 0.
    
    //observation 2:
    //now we should know if a xor b = a, then b = 0.
    //as 1 xor 0 = 1 and 0 xor 0 = 0.
    //now if we find a prefix xor array for the array nums.
    //then we would find some repetitive values.
    //that would mean that subarrays between those repetitive values are beautiful(xor of all ele = 0).
    int n = nums.size();
    // vector<int> prefix(n); no need.
    int driver = 0;
    unordered_map<int, int> freq; //digit: freq.
    freq[driver]++;
    
    long long sum = 0;
    for(int i=0; i<n; i++){
        driver = driver ^ nums[i];
        // cout<<driver<<endl;
        freq[driver]++;
        sum+=(freq[driver]-1);
    }
    
    
    return sum;
}