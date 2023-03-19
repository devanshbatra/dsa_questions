// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//steps - 
//sort the arr and dep according to the arrival taaki jo next incoming hai uska pata lagta rahe.
//make a minheap.
//start traversing the stations
//take first station put its departure in minheap while increasing the platform
//take second station: 
// if arrival is less than the top of minheap add this new departure in minheap 
// and increase the platforms.
//else pop the top and push the curr departure.

//at end the size of the minheap is the ans.

static bool comparator(pair<int, int> a, pair<int, int> b ){
    if(a.first!=b.first) return a.first < b.first;
    else return a.second<b.second;
}

int findPlatform(int arr[], int dep[], int n)
{
    vector<pair<int, int>> sched;
    
    for(int i=0; i<n; i++){
        sched.push_back({arr[i], dep[i]});
    }
    
    sort(sched.begin(), sched.end(), comparator);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    
    
    for(int i=0; i<n; i++){
        int arr = sched[i].first;
        int dep = sched[i].second;
        if(pq.empty()){
            pq.push(dep);
        }
        else{
            if(arr<=pq.top()){
                pq.push(dep);
            }else{
                pq.pop();
                pq.push(dep);
            }
        }
        
    }
    
    return pq.size();
}