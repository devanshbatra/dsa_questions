// https://leetcode.com/problems/single-number-ii/description/

//This question is too good, try to do it yourself first.


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void convertBinary(int n, vector<int>& bitCounts){
        int cnt = 0;
        if(n<0){
            n=abs(n);
            bitCounts[33]++;
        }

        while(n>0){
            bitCounts[cnt]+=(n%2);
            cnt++;
            n = n/2;
        }

    }

    // void printArr(vector<int>& arr){
    //     for(auto & i : arr){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }

    int singleNumber(vector<int>& nums) {
        long long x = 0;

        int n = nums.size();

        vector<int> bitCounts(34, 0);

        for(int i=0; i<n; i++){
            convertBinary(nums[i], bitCounts);
            // printArr(bitCounts);
        }

        bool neg = false;
        for(int i=0; i<=33; i++){
            if(i==33 && bitCounts[i]%3!=0 ){
               neg = true; 
               continue;
            }
            if(bitCounts[i]%3!=0){
                x = x + pow(2, i);
            }
        }

        if(neg) x = 0-x;

        return x;

    }
};