// https://leetcode.com/problems/minimum-cost-to-split-an-array/description/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
//see for explanation if can't do self.
// https://www.youtube.com/watch?v=9JaxrSwu8YQ 
//catch:
// for every i and j - we have two options whether to make a partition or not.
// if we make partition then add this subarrImportance Value+func(remaining(j+1, j+1)).
// else simply do func(i, j+1).

//to ease the computation - precompute the importance values from every i to j in store.


int solve(vector<int>& nums, int k, int n, int i, int j, vector<vector<int>>& store, vector<vector<int>>& dp){
    //base case
    if(j==n-1){
        //make partition and return ans
        return k+store[i][j];
    }
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    
    //rc
    //make partition at j 
    int partition = k+store[i][j] + solve(nums, k, n, j+1, j+1, store, dp);
    
    //do not make
    int noPartition = solve(nums, k, n, i, j+1, store, dp);
    
    
    return dp[i][j] = min(partition, noPartition);
    
    
}


int minCost(vector<int>& nums, int k) {
    
    vector<vector<int>> store(1001, vector<int>(1001, 0));
    
    int n = nums.size();
    
    //creating importance matrix.
    unordered_map<int, int> m; //number: freq.
    for(int i=0; i<n; i++){
        
        int imp = 0;
        for(int j=i; j<n; j++){
            if(m.find(nums[j])!=m.end()){
                if(m[nums[j]]==1){
                    // if(i==2) cout<<nums[j]<<" : "<<m[nums[j]]<<endl;
                    imp+=2;
                }else{
                    // if(i==2) cout<<nums[j]<<" : "<<m[nums[j]]<<endl;
                    imp+=1;
                }
            }
            m[nums[j]]++;
            store[i][j]+=imp;
            
        }
        
        m.clear();
        
    }
    
    vector<vector<int>> dp(n, vector<int>(n, -1));
    
    //calling the recursive function.
    return solve(nums, k, n, 0, 0, store, dp);
    
    
    
}

//can be optimized further.