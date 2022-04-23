// https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/
#include <iostream>
#include <vector>
using namespace std;

// using recursion
class Solution {
public:
    int findPeak(vector<int> arr, int s, int e){
        
//         base case
        if(s>e) return -1;
        
//         processing
        int mid = e+(s-e)/2;
        
//        recursive call
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
        else if(arr[mid]>arr[mid+1]) return findPeak(arr, s, mid-1);
        else return findPeak(arr, mid+1, e);
        
    }

    
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s=0, e=n-1;
        return findPeak(arr, s, e);
    }
};