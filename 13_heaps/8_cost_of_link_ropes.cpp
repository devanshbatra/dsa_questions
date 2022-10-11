/*
There are given N ropes of different lengths, we need to connect these ropes into one rope.
The cost to connect two ropes is equal to sum of their lengths. The task is to connect the
ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 
*/

//we know the complexity of finding the min element from min heap is O(1).
#include<iostream>
#include<queue>
using namespace std;
long long minCost(long long arr[], long long n) {
    // Your code here
    if(n==1) return 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long i=0; i<n; i++){
        pq.push(arr[i]);
    }
    long long sum = 0, ans = 0;
    while(pq.size()>1){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        
        sum = a+b;
        ans = ans+sum;
        pq.push(sum);
        
    }
    return ans;
}