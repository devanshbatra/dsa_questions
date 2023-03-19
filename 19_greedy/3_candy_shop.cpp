// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//sort the array
//it just uses two pointers.
//for min money start buy from start and start reducing from last.

//for max money start buy from end and start reducing from start.
vector<int> candyStore(int candies[], int N, int k)
{
    vector<int> store;
    for(int i=0; i<N; i++){
        store.push_back(candies[i]);
    }
    
    sort(store.begin(), store.end());
    
    vector<int> ans;
    int mini=0;
    int i=0, j=N-1;
    while(i<=j){
        mini+=store[i];
        i++;
        j-=k;
    }

    
    int maxi=0;
    i=0; 
    j=N-1;
    while(i<=j){
        maxi += store[j];
        j--;
        i+=k;
    }
    
    ans.push_back(mini);
    ans.push_back(maxi);
    return ans;
    
}