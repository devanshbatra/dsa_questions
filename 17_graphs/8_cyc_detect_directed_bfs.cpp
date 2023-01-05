
//We can also find if there is a cycle in directed graph or not using bfs
//as we learnt kahn's algorithm, we can find its topological sort order.
//and then if the topological order is valid then it does not contain any cycle 
//but if the topological order is not valid then it contains a cycle
//just count the topological sort items , if topo order count = V, means there is no
//cycle. warna topo order poora print he nhi ho payega.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

void bfs(vector<int> adj[], queue<int> &q,int& count, unordered_map<int, int> &indegree){
    
    
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        count++;
        for(int i=0; i<adj[curr].size(); i++){
            int child = adj[curr][i];
            indegree[child]--;
            if(!indegree[child]) q.push(child);
        }
        
    }
    
}

bool isCyclic(int V, vector<int> adj[]) {
    //applying kahns algorithm
    
    unordered_map<int, int> indegree;
    
    for(int i=0; i<V; i++){
        
        for(int j=0; j<adj[i].size(); j++){
            int child = adj[i][j];
            indegree[child]++;
        }
        
    }
    
    
    //adding all indegree 0 elements to the queue.
    queue<int> q;
    
    for(int i=0; i<V; i++){
        if(!indegree[i]) q.push(i);
    }
    int count=0;
    bfs(adj, q, count, indegree);
    
    if(count==V) return false;
    else return true;//means cycle present
}

//time and space complexity: linear: O(N+E).