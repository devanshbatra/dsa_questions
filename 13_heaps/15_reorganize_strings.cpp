// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.
// https://leetcode.com/problems/reorganize-string/

//approach: 
// we tried many approaches but none of them worked then saw the video.
// we will be always pushing the most frequent element to the ans but there is a catch.
// we will create a lastvisited variable so that we do not copy the same element which was last pushed in ans.
// on the last of the next iteration we will update the lastvisited and push our prev lastvisited to the maxheap

//also to access the freq of the elements we will use hashmap
// now for accessing then most frequent element every time, we will use max heap (customizable) which store the 
// nodes with their character as well as frequency and work as a maxheap for the freq.

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
class Node{
    public:
        char ch;
        int freq;
        Node(char c, int f){
            ch= c;
            freq = f;
        }
};


class comparator{
    public:
        bool operator()(Node* a, Node* b){
            return a->freq <= b->freq;
        }
};

class Solution {
public:
    
    string reorganizeString(string s) {
        
        //creating a custom heap.
        priority_queue<Node*, vector<Node*>, comparator> maxheap;
        
        unordered_map<char, int> m;
        int n = s.length();
        for(int i=0; i<n; i++){
            m[s[i]] += 1;
        }
        
        for(auto it: m){
            Node* newnode = new Node(it.first, it.second);
            maxheap.push(newnode);
        }
        string ans = "";
        Node* lastvisited = new Node('$', 0); //last visited pehle se banalo taaki same he push na ho jaaye wapas
        while(!maxheap.empty()){
            ans+=maxheap.top()->ch;
            Node* temp = maxheap.top();
            maxheap.pop();
            //pushing back the last visited
            if(lastvisited->freq > 0)
                maxheap.push(lastvisited);
            //updating the lastvisited
            temp->freq-=1;
            lastvisited = temp;
            
            //not possible condition
            //agar last visited abhi bacha hai aur heap khali ho gaya h.
            if(lastvisited->freq > 0 && maxheap.empty()){
                ans = "";
                return ans;
            }
            
        }
        
        return ans;
        
        
        
    }
};