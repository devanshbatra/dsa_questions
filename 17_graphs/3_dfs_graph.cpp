#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
//In dfs technique: WE go to the depth first.
// idhar adjacency list ke har array ko traverse karte hai aur jo child unvisited milta jae use print krte hai,
// aur phir usi ke children check krne lagte hain.
//same as the dfs of tree.

// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=1
void dfs(unordered_map<int, bool> &visited, vector<int>& ans, int targetNode, vector<vector<int>> & adj, int V){
    
    ans.push_back(targetNode);
    visited[targetNode] = true;
    for(int i=0; i<adj[targetNode].size(); i++){
        int child = adj[targetNode][i];
        if(!visited[child]) dfs(visited, ans, child, adj, V);
    }
    
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // making adjacency list - from the edges matrix
    vector<vector<int>> adj(V);
    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    for(int i=0; i<V; i++){ //for covering all the disconnected components also.
        if(!visited[i]){
            vector<int> temp;
            dfs(visited, temp, i, adj, V);
            ans.push_back(temp);
        }
    }
    return ans;
}

//tc: O(V).
//sc: (V).