// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/

//Spoiler ahead: 
//this question is based on finding and playing with some mathematics of modulus( modulus of negative numbers also).

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> m;
        
        int n = nums.size();
        for(int i=0; i<n; i++){
            int modulus;
            //modulus of negative aise nikalte hain.
            if(nums[i]<0){
                int inter = (abs(nums[i])%value);
                if(inter==0) modulus = 0;
                else modulus = value-inter;
            }
            else modulus = abs(nums[i])%value;
            // cout<<modulus<<endl;
            m[modulus]++;
        }
        
        int ans;
        for(int i=0; true; i++){
            int modu = i % value;
            if(m.count(modu)!=0 && m[modu]>0){
                // cout<<"for i: "<<i<<" m["<<modu<<"]: "<<m[modu]<<endl;
                m[modu]--;
            }
            else{
                ans = i;
                break;
            }
        }
        
        return ans;
        
    }
};