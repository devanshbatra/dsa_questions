#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

//applying greedy approach:
//hamare paas do option h, ya toh ham according to start time sort kar de aur phir greedy lagae.
//ya phir according to end time sort kar de aur phir greedy lagae.

//but according to end time sort karna is more optimal, as if we sort with start time.
//aur ek task aaya aur atak he gaya to ek he meeting ho payegi.

static bool Comparator(pair<int, int> a, pair<int, int> b){
    if(a.second!=b.second) return a.second<b.second;
    else return a.first < b.first;
}

int maxMeetings(int start[], int end[], int n)
{
    
    vector<pair<int, int>> meets(n);
    
    for(int i=0; i<n; i++){
        meets[i].first = start[i];
        meets[i].second = end[i];
    }
    
    sort(meets.begin(), meets.end(), Comparator);
    
    int ans = 0;
    int prevEnd = -1;
    
    for(int i=0; i<n; i++){
        int st = meets[i].first;
        int en = meets[i].second;
        
        if(st>prevEnd){
            // cout<<"running for st: "<<st<endl;
            prevEnd = en;
            ans++;
        }
    }
    
    
    
    return ans;
}