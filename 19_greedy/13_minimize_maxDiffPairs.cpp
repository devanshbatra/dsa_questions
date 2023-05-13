// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

//SPOILER.

//This question is based on greedy + binary search.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:


    bool isGood(vector<int>& nums, int p, int limit){
        int n = nums.size();
        int i=0;
        int count = 0;

        //here we are using the greedy concept.
        //ki koi bhi number ya toh right wale se pair bana sakta hai ya left wale se.
        //agar left se pair banane pr ans<=limit nhi aa rha to i++ kar do
        //warna i+=2;
        while(i<n-1){
            if( nums[i+1]-nums[i] <=limit ){
                count++;
                i+=2;
            }
            else i++;
        }
        // cout<<count<<"=count for limit: "<<limit<<endl;
        if(count>=p) return true;
        else return false;

    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        //finding upper limit.
        int h = nums[n-1]-nums[0];
        int l = 0;
        int ans;
        //binary search.
        while(l<=h){
            int mid = l+(h-l)/2;

            if(isGood(nums, p, mid)){
                ans = mid;
                //try for lower.
                h = mid-1;
            }
            else{
                l = mid+1;
            }

        }

        return ans;

    }
};

//time complexity: O(nlogn) forsorting + O( n/2 * log(R) ) where R is the range of numbers. R is roughly the greatest difference.
//space complexity: O(n) for sorting.(auxiliary space is used in merge sort.)
