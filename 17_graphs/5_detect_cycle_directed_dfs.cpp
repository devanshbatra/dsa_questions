#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
//detect cycle in a directed graph.
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//USING DFS
//idhar parent wali dikkat nhi hai.
//so we will see it a visited node comes again then cycle may be present
//BUT WAIT
//a node can still be repeated without any cycle.
//it is the case when there is a cycle but the arrows are not in the same direction.
//so for handling such nodes we will be making an another map which will store the infor
// of the nodes which have been backtracked as only those nodes will be forming such fake cycles.
//and if there is an actual cycle present in the graph then the node would be reapeated (already visited)
//and also would never had been backtracked.

//ya phir backtracked na lene ki jagah ye le skte hai ki ek dfs naam ka map banao
//jaise jaise dfs call ho raha hai curr element ko dfs map mein daaldo
//but agar backtrack hota h to dfs se nikal do.
//now agar koi element visited bhi h aur dfs main bhi h - means backtrack nhi hua- means cycle present h.

bool dfs(vector<int> adj[], int curr, unordered_map<int, bool>& visited, unordered_map<int, bool> &backtracked){
    
    
    visited[curr] = true;
    
    for(int i=0; i<adj[curr].size(); i++){
        
        int child = adj[curr][i];
        if(!visited[child]){
            bool cycleDetected = false;
            cycleDetected = dfs(adj, child, visited, backtracked);
            if(cycleDetected) return true;
        }
        
        else if(!backtracked[child]){//else lagana zarori hai, ham nhi chahate ki wapsi mein ye bhi execute ho
            return true;
        }
        
    }
    //kisi bhi child se cycle nhi mili
    //now since it need to backtrack , so backtracked=true
    backtracked[curr] = true;
    return false;
    
}


bool isCyclic(int V, vector<int> adj[]) {
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> backtracked;
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            bool found = false;
            found = dfs(adj, i, visited, backtracked);
            if(found) return true;
        }
    }
    return false;
    
}

//time complexity: linear = O(V+E).
//space complexity: to make maps = O(V).