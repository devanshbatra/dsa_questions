#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

//Find the shortest path from the source s to detination t in the graph given by edges (vertices are from 1 to N).
//UNWEIGHTED GRAPH.
// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// using bfs - 
    //when we use bfs we are going level by level towards the destination
    //so the shortest path will first approach the destination than any other
    //path. That's why if we maintain a child: parent table using bfs then
    //we can find the distance between the source and destination using that
    //table entries.
    
    //1) make adjacency list
    vector<vector<int>> adj(n+1);
    
    for(int i=0; i<m; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int, int> parent;
    unordered_map<int, bool> visited;
    
    queue<int> q;
    q.push(s);
    
    parent[s] = -1;
    visited[s] = true;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int i=0; i<adj[curr].size(); i++){
            int child = adj[curr][i];
            if(!visited[child]){
                visited[child] = true;
                parent[child] = curr;
//                 cout<<"pushing: "<<child<<endl;
                q.push(child);
            }
        }
    }
//     for(auto i: parent){
//         cout<<i.first<<" is a child of "<<i.second<<endl;
//     }
    
    int curr = t;
    vector<int> ans;
    ans.push_back(curr);
    while(parent[curr]!=-1){
        curr = parent[curr];
        ans.push_back(curr);    
    }
    //since ans will be in reverse order so reversing the array.
    reverse(ans.begin(), ans.end());

    return ans;
    
    
	
}
// time and space complexity : O(N+E). if we do not include making adja list: then space O(N).
