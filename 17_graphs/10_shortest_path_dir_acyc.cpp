/*input: v: 6, e: 9
    0 1 5
    0 2 3
    1 2 2
    1 3 6
    2 3 7
    2 4 4
    2 5 2 
    3 4 -1
    4 5 -2
*/


//for find the shortest path between source and destination in a WEIGHTED directed acyclic graph.
//directed acyclic se samajh jaana ki dist nikalne ke liye topological order use hoga.
//MOTA MOTA
// I) MAKE TOPO ORDER
// II) DEVELOP DISTANCE VECTOR USING THAT ORDER.

//DETAILED STEPS
// 1) we will find the topological order of the graph (lets say using dfs backtrack-stack method) and keep it
//    in stack only.
// 2) now make a distance vector, which denotes the distance of difference of different indexes(nodes) from 
//    source.
//3) make dist[source] = 0 and others as infinity or let's say INT_MAX.
// 4) now start with top of topological stack.
// 5) see if the distance is !=infinity.
// 6) if not equal to infinity: then see its adjacency list.
// 7) update its children's distance by : dist[child] = min[dist[child], (dist[src]+weight)]. we are doing min
//    as if the previous distance was less then we need not to take the new dist.
// 8) do it till stack is empty;

//Note: why are we first making a topological order.
// because topological order se he pata chalta hai ki kaun sa node kiske baad aayega.
// if any element is behind the source element in topological order than this element cannot be reached by
// starting from source.
#include<iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits.h>

using namespace std;

//good question
//making a directed graph. - weighted
class Graph{
    public:
    //adjacency list for directed acyclic weighted graph.
    unordered_map<int, vector<pair<int, int>>> adj;


    void addEdge(int u, int v, int weight){
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printGraph(){
        for(auto i: adj){
            cout<<i.first<<"-> ";
            for(auto child: i.second){
                cout<<child.first<<":w>"<<child.second<<", ";
            }
            cout<<endl;
        }
    }

};


//function for topo sort
void dfs(unordered_map<int, vector<pair<int, int>>>& adj, int curr, unordered_map<int, bool>& visited, stack<int>& stk){
    
    visited[curr] = true;

    for(int i=0; i<adj[curr].size(); i++){
        int child = adj[curr][i].first;

        if(!visited[child]){
            dfs(adj, child, visited, stk);
        }

    }
    //backtracking
    stk.push(curr);

}


int main(){

    int V;
    cout<<"Enter the number of vertices"<<endl;
    cin>>V;
    int E;
    cout<<"enter the number of edges"<<endl;
    cin>>E;
    Graph g;
    cout<<"Enter the edges"<<endl;
    for(int i=0; i<E; i++){
        int u;
        int v;
        int w;
        cin>>u>>v>>w;
        g.addEdge(u, v, w);
    }


    g.printGraph();

    //1) making topological order
    unordered_map<int, bool> visited;
    stack<int> stk;

    for(int i=0; i<V; i++){
        if(!visited[i]){
            dfs(g.adj, i, visited, stk);
        }
    }

    //2) make dist and update according to top of stack till stack is empty.

    vector<int> dist(V, INT_MAX);

    int src = 1;
    // cout<<"enter the source: ";
    // cin>>src;
    
    //make source ka dist from source = 0;
    dist[src] = 0;

    while(!stk.empty()){

        int top = stk.top();
        stk.pop();

        if(dist[top]!=INT_MAX){
            //update children
            for(int i=0; i<g.adj[top].size(); i++){
                int child = g.adj[top][i].first;
                int weight = g.adj[top][i].second;

                dist[child] = min(dist[child], dist[top]+weight);
            }
        }

    }

    //printing distance vector
    cout<<"This is the minimum distance of every node from the source: "<<src<<endl;
    for(int i=0; i<dist.size(); i++){
        cout<<"Mindist("<<src<<"->"<<i<<"): "<<dist[i]<<endl;
    }



    return 0;
}

//time complexity: O(N+E) for topological sort + O(n) for furtherO(n^2) hota but isme cycle allowed nhi h lagbhag
// o(n) he rhega. and space complexity: O(N+E).