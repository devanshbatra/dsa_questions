#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;


//BREADTH FIRST SEARCH: means first exploring all child and then going deep
//queue will be used for fifo
// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002

void bfsUtil(unordered_map<int, bool>& visited, vector<int> &ans, vector<vector<int>>& neighbour, int startNode){
    
    //now traversal
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(int i=0; i<neighbour[curr].size(); i++){
            int child = neighbour[curr][i];
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
            }
        }
    }
    
} 

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int> ans;
    unordered_map<int, bool> visited;
    vector<vector<int>> neighbour(vertex);//adjacency list.
    //making the adjacency list as we don't have been given. (gfg mein thi)
    for(auto i: edges){
        neighbour[i.first].push_back(i.second);
        neighbour[i.second].push_back(i.first);
    }
    
    for(int i=0; i<vertex; i++){ //as all the components may not be connected(for disconnected components).
        if(!visited[i]){
            sort(neighbour[i].begin(), neighbour[i].end()); //sorting as code studio need children in sorted order.
            bfsUtil(visited, ans, neighbour, i);
        }
    }
    return ans;
}

//time complexity : O(E+V).