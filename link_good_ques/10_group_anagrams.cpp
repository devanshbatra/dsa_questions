/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically
 using all the original letters exactly once.

 https://leetcode.com/problems/group-anagrams/

 Approach: //sort karne par anagrams ek jaise ho jaate hain
    //aur phir wo hashmap use krne ka sahil ka mtree wala tareeka.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    
    //sort karne par anagrams ek jaise ho jaate hain
    //aur phir wo hashmap use krne ka sahil ka mtree wala tareeka.
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> m;
        
        for(int i=0; i<n; i++){
            string ele = strs[i];
            
            sort(strs[i].begin(), strs[i].end());
            
            m[strs[i]].push_back(ele); //this way auto matic grouping ho jayegi. 
            //because sort karke to anagrams ek jaise he ho jaate hn.
            
        }
        
        vector<vector<string>> ans;
        
        //iterate the map and push into the ans.
        for(auto it: m){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};