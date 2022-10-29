// https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=0

#include <iostream>
#include<map>
#include<vector>
using namespace std;

//find the maximum frequency element in the array.

int maximumFrequency(vector<int> &arr, int n)
{
    map<int, int> m; //unordered map se hoga.
    int maxi = INT_MIN;
    int ans = -1;
    for(int i=0; i<n; i++){
        m[arr[i]]++;
        if(m[arr[i]] > maxi ){
            maxi = m[arr[i]];
        }
    }
    //same ke case mein hume min index wala element return karana hai.
    //so shuru se start krenge.
    for(int i=0; i<n; i++){
        if(m[arr[i]]==maxi){
            ans = arr[i];
            break;
        }
    }
    return ans;
}