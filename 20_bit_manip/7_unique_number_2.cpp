// https://leetcode.com/problems/single-number-iii/
// you are give an array of integers where every number is in pair except two unique numbers
// find those unique numbers.
#include <iostream>   
#include <vector>   
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int twoXor = 0;
        for(auto& i: nums) twoXor = twoXor ^ i;

        //now see where in the bits of this twoXor is 1 coming.
        //if 1 is coming that means there will be 0 ^ 1 or 1 ^ 0.
        int i = 0;
        int n= twoXor;
        cout<<"twoXor: "<<twoXor<<endl;
        while(i<32){
            if(n&1) break;
            i++;
            n=n>>1;
        }

        //we have got a position i where xor is 1.
        //use bitmask to find which elements in the array nums have 1 at this i-th position.
        int bitmask = 1<<i;
        int unique1 = 0, unique2 = 0;

        for(auto& dig: nums){
            if(dig&bitmask) unique1 = unique1 ^ dig;
            else unique2 = unique2 ^ dig;
        }

        vector<int> ans{unique1, unique2};
        return ans;


    }
};

//or we can find b using result = a^b,  result^a = a^b^a = b.