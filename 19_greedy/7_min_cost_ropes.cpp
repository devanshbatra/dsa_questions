// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Function to return the minimum cost of connecting the ropes.
long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    //now enter every element in the priority queue
    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }
    
    long long sum = 0;
    
    //now pop two elements add them and push sum
    while(pq.size()>1){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        
        sum+=(a+b);
        if(!pq.empty())
            pq.push(a+b);
    }
    
    return sum;
    
}