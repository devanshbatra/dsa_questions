// Function to detect cycle in an undirected graph.
    //doing with bfs-
    //we will use queue and maintain a visited as usual
    //we will detect cycle if already visited nodes comes in the children of some node again
    //but since it is an undirected graph so parents will also come there.
    //so we will also maintain a map of child: parent ( to remove the ambiguity ).
    
    //now if a nodes comes which is already visited and is not a parent of curr Node- then it means
    //that the cycle is present.
    // https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
bool isCycleUtil(vector<int> adj[], int V, unordered_map<int, bool>& visited, int targetNode){
    
    unordered_map<int, int> parent; //child: parent
    queue<int> q;
    q.push(targetNode);
    parent[targetNode] = -1;
    visited[targetNode] = true;
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        
        for(int i=0; i<adj[curr].size(); i++){
            int child = adj[curr][i];
            if(visited[child] && visited[child]==true && parent[curr]!=child){
                // cout<<"returning true for: "<<curr<<" and its child which is not its parent is: "<<child;
                return true;
            }
            
            if(!visited[child]){
                visited[child] = true;
                q.push(child);
                parent[child] = curr;
            }
        }
        
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    
    unordered_map<int, bool> visited;
    
    for(int i=0; i<V; i++){
        bool found = false;
        if(!visited[i]){
            found = isCycleUtil(adj, V, visited, i);
        }
        if(found==true) return true;
    }
    
    return false;
    
}
//time complexity: O(V).


//USING DFS - same time complexity - linear- O(V).
bool dfs(vector<vector<int>> & adj, unordered_map<int, bool> &visited, unordered_map<int, int>& parent, int targetNode){
    
    
    for(int i=0; i<adj[targetNode].size(); i++){
        int child = adj[targetNode][i];
        
        if(!visited[child]){
            visited[child] = true;
            parent[child] = targetNode;
            bool cycleDetected = dfs(adj, visited, parent, child);
            if(cycleDetected) return true;
            //directly return dfs nahi kar skte kyunki agar false aaya to bina aage
            //ki nodes check kiye false return kar dega.
        }
        else if(visited[child] && visited[child]==true && parent[targetNode]!=child)
            return true;
        
    }
    //if can't return true for this node that means no cycle
    return false;
    
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //making adjacency list
    vector<vector<int>> adj(n+1);
    
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
//     for(int i=1; i<n+1; i++){
//         cout<<i<<"->";
//         for(int j=0; j<adj[i].size(); j++){
//             cout<<adj[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent; //child: parent
    
    for(int i=1; i<n+1; i++){
        if(!visited[i]){
            bool found = false;
            parent[i] = -1;
            visited[i] = true;
            found = dfs(adj, visited, parent, i);
//             cout<<"found: "<<found<<endl;
            if(found) return "Yes";
        }
    }
    
    return "No";
}