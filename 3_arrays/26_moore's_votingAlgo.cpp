// https://leetcode.com/problems/majority-element/description/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:

    //using moore's voting algorithm
    //This can be applied only if there is guarantee that some element is greater than n/2 times.


    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(count==0){
                ele = nums[i];
            }
            if(nums[i]==ele){
                count++;
            }
            else count--;
        }


        return ele;

    }
};