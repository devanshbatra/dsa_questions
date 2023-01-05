/*
STRONGLY CONNECTED COMPONENTS:
    These are those components in a graph in which all the nodes are such that if we start from a node
    then we can reach to all other nodes of that component easily.

Kosaraju's algorithm is used to find which components in the graph are strongly connected.

INTTUITION. - lets take the graph - [0,2],[2,1],[1,0],[3,1],[4,3].
                if we directly start from 0 and do a dfs then we won't get the components instead we will be
                traversing the whole graph.
                but just try to start dfs from 4 and see what happens. You will stuck where the next child would
                be visited and you will get connected components but here also we do not get all the components
                but we came to know that if we do dfs in reverse order of topological sorting then we would 
                get the connected components.


APPROACH: we will not move in reverse order but we will transpose the graph itself and start from end.
        steps:
        1) find the topological order.
        2) now make transpose of the graph.(as stack is reversed na, to shuru se he dekh lenge).
        3) now find strongly connected components using dfs.
          
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

void dfs(vector<int> adj[], int curr, unordered_map<int, bool>& visited, stack<int> &s){
    
    visited[curr] = true;
    
    for(int i=0; i<adj[curr].size(); i++){
        int child = adj[curr][i];
        if(!visited[child]){
            dfs(adj, child, visited, s);
        }
    }
    s.push(curr);
}

void findComp(vector<vector<int>>& adj, int curr, unordered_map<int, bool>& visited){
    
    visited[curr] = true;
    
    for(int i=0; i<adj[curr].size(); i++){
        int child = adj[curr][i];
        if(!visited[child]) findComp(adj, child, visited);
    }
    
    
}

int kosaraju(int V, vector<int> adj[])
{
    //code here
    // 1) find the topological order.
    stack<int> topo;
    unordered_map<int, bool> visited;
    
    for(int i=0; i<V; i++){
        if(!visited[i]) dfs(adj, i, visited, topo);
    }
    
    //2) now make transpose of the graph
    vector<vector<int>> adj2(V);
    
    for(int i=0; i<V; i++){
        visited[i] = false; //also remember to refresh the visited
        for(int j=0; j<adj[i].size(); j++){
            int child = adj[i][j];
            adj2[child].push_back(i);
        }
    }
    
    //3) now find strongly connected components using dfs
    int count = 0;
    while(!topo.empty()){
        int i = topo.top();
        topo.pop();
        if(!visited[i]){
            findComp(adj2, i, visited);
            count++;
        }
    }
    
    return count;
    
}