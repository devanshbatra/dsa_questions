// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//VERY GOOD QUESTION
//simply sort the array according to the profit, we don't care about deadline.
//and place the job in the timeline closer to its deadline so that if any other job comes, even smaller
//than this deadline could also be accomodated.

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool comparator(Job a, Job b){ //static bhi aayega yahan pata nhi error nhi aa rha hai.
    if(a.profit!=b.profit) return a.profit>b.profit;
    else return a.dead>b.dead;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    vector<Job> store;
    for(int i=0; i<n; i++){
        store.push_back(arr[i]);
    }
    
    sort(store.begin(), store.end(), comparator);
    
    int maxTime = -1;
    for(int i=0; i<n; i++){
        maxTime = max(maxTime, store[i].dead);
    }
    
    //prepare timeline array-
    //so that we can mark/reserve the time for the jobs.
    vector<int> timeline(maxTime+1, -1);
            
    int profit = 0;
    int count = 0;
    
    int i=0;
    while(i<n){
        //if time is there then do the job
        //check from end of time line as if we allocate at the end then shuru ke times to bache he rhenge.
        int deadline = store[i].dead;
        for(int j=deadline; j>=1; j--){ //starting from end bcs last mein lage toh acha hai.
            if(timeline[j]==-1){
                timeline[j]=store[i].id;
                profit+=store[i].profit;
                count++;
                break;
            }
        }
        i++;
    }
    
    vector<int> ans;
    ans.push_back(count);
    ans.push_back(profit);
    return ans;
    
} 

//TIME COMPLEXITY: Nlog(n)(for sorting). + n*k(where k is maxDeadline).
//space complexity: 