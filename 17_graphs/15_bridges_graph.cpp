/*
Bridges - 
    Bridges in graphs are those edges which if removed can increase the number of connected components.
    or it becomes disconnected.

    Finding bridges:
    1) brute force approach: 
        An appraoch could be to take every edges once, remove it and test whether the graph is disconnected or
        not.
        But checking with every edge will consume a lot of time complexity.

    2) see ss. copy image - its a dfs solution in which we maintain 4 things - discovery time, low(earliest
        possible time), 
        https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026?leftPanelTab=0
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<vector>

using namespace std;

void dfs(unordered_map<int, list<int>>& adj, int curr, int &timer, unordered_map<int, bool>& visited, vector<int> &dis, vector<int> &low, int parent, vector<vector<int>>& ans){
    
    visited[curr] = true;
    dis[curr] = timer;
    low[curr] = timer;
    timer++;

    for(auto child: adj[curr]){
        
        if(child==parent) continue;
        if(!visited[child]){ 
            dfs(adj, child, timer, visited, dis, low, curr, ans);
            
            //update low[curr] if child found a back edge
            low[curr] = min(low[curr], low[child]);
            //check if the child--curr edge is a bridge - this happens if child could not find any back edge
            if(low[child]>dis[curr]) {
                vector<int> temp{curr, child};
                ans.push_back(temp);
            }
            
        }
        else{ //already visited and parent bhi nhi h - back edge
            //update low[curr]
            low[curr] = min(low[curr], dis[child]);
        }
        
    }
    
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    //making adjacency list
    unordered_map<int, list<int>> adj;
    
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int, bool> visited;
    vector<int> dis(v, -1); //discovery time.
    vector<int> low(v, -1);
    int parent = -1;
    int timer = 0;
    vector<vector<int>> ans;
    
    for(int i=0; i<v; i++){
        if(!visited[i]) dfs(adj, i, timer, visited, dis, low, parent, ans);
    }
    
    return ans;
}

