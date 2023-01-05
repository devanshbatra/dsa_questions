//topological sorting. -USING BFS
//Kahn's algorithm.

//first see this example and see why normal bfs se ham topo order kyun nhi laa payenge.
//0: 1
//1: 2, 3
//2: 3, 4
//3: -
//4: -


//as we see that there are chances that 3 comes before 2 in topo order but it should not come.
//so to avoid that kahn introduces an algorithm
//we just need to maintain a new data structure hash map which maintains the indegree of the nodes.
//and whenever we pop any node's parent from queue, its indegree should decrease.
//also to ensure, correct topo order only those elements should be pushed to queue whose indegree is 0.

//steps: 
//find indegree of all nodes.
//do a bfs.
//decrease indegreee when a nodes parent is popped.
//while pushing children to queue , push only those whose indegree is 0.

//Note: why are we not using visited map here:
// if we use visited then it will not allow to re-utilize a member which was denied push while it was have 
// indegree != 0, also since it is a directed graph so we do not need to take care that parent will come in 
// child's children and also there are no cycles. bas disconnected components ka khatra h, wo question mein 
// hai ya nhi ye dekh lena , gfg mein nhi hai.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
void bfs(vector<int> adj[], int root, unordered_map<int, int>& indegree, vector<int>& ans, queue<int> &q){
    
    //yaha push karne ki need nahi h
    //jiska indegree 0 tha wo pehle he push ho chuka hai.
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        
        for(int i=0; i<adj[curr].size(); i++){
            int child = adj[curr][i];
            //decrease indegree
            indegree[child]--;
            
            if(indegree[child]==0) q.push(child);
        }
    }
    
}

vector<int> topoSort(int V, vector<int> adj[]) 
{
    unordered_map<int, int> indegree;
    
    //calculating indegrees
    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            int child = adj[i][j];
            indegree[child]++;
        }
    }
    
    
    //important step
    //jis jis ki indegree 0 hai, unko ans mein store queue mein push kardo
    //because wo waise to aa he nhi payenge as wo kisi ke child nhi hai.
    queue<int> q;
    for(int i=0; i<V; i++){
        if(!indegree[i]) q.push(i);
    }
   // cout<<q.front();
    
    vector<int> ans;
    bfs(adj, 0, indegree, ans, q);
    
    return ans;
    
}

//time and space complexity : O(N+E). 