// https://leetcode.com/problems/time-based-key-value-store/
// This question is based on low level design architecture (lld), a kind of it was asked in mtree.
// We have to create a data structure which can store multiple values for the same key with different 
// timestamps
// for that we used a map with key as key and value as a pair of (value, timestamp).
// now the second problem was to find the value of a given key and timestamp.
// if that particular timestamp is not available then we should return the just the closest lower timestamp
// available. For that we used binary search.(classical problem).
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class TimeMap {
public:
    
    map<string, vector<pair<string, int>> > m; //key: [<v1,t1>, <v2,t2>, <v3,t3>...]>
    
 
    
    void set(string key, string value, int timestamp) {
        pair<string, int> p = make_pair(value, timestamp);
        m[key].push_back(p);
    }
    
    void binSearch(int t, vector<pair<string, int>>& arr, int s, int e, string& ans){
        
        //base case
        if(s>e){
            return;
        }
        
        int mid = s+(e-s)/2;
        
        if(arr[mid].second==t){
            ans=arr[mid].first;
            return;
        }
        else if(arr[mid].second > t){
            binSearch(t, arr, s, mid-1, ans);
        }
        else{
            ans = arr[mid].first;
            binSearch(t, arr, mid+1, e, ans);
        }
        
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        if(m.find(key)!=m.end()){
            int s = 0, e = m[key].size()-1;
            binSearch(timestamp, m[key], s, e, ans);
            return ans;
        }
        else return ans;
    }
};