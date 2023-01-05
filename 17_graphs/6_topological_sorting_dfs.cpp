//What is topological sort?
// It is the linear ordering of vertices such for every edge u -> v, u always appears before v in that ordering.
//for eg: for the graph: 
//1: 2
//2: 4
//4: 5, 6

//top sort :
// 1 2 5 4 6 INVALID - and 
// 1 2 4 5 6 VALID
//SEE SS ALSO.
//note: topological sort can be found out of DIRECTED ACYCLIC GRAPH (DAG) only.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

//we are doing it with simple DFS first.
//we will take a stack and push elements in it, when backtracking.
//just make a recursive call stack and a dry run on:
// 	1 2, 2 4, 4 6, 4 5, 5 6, 1 3, 3 4
//then you will come to know that any element which is not coming in order also comes in order while backtracking
void dfs(vector<int> adj[], int curr, unordered_map<int, bool> &visited, stack<int>& sortStk){
    
    visited[curr] = true;
    
    for(int i=0; i<adj[curr].size(); i++){
        int child = adj[curr][i];
        if(!visited[child]){
            dfs(adj, child, visited, sortStk );
        }
        
    }
    //backtrack
    sortStk.push(curr);
    
}

//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    unordered_map<int, bool> visited;
    stack<int> sortStk;
    
    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs(adj, i, visited, sortStk);
        }
    }
    
    vector<int> ans;
    while(!sortStk.empty()){
        ans.push_back(sortStk.top());
        sortStk.pop();
    }
    
    return ans;
}

//time complexity: O(V+E)
//space : O(V).