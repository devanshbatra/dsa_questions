/*
What is graph?
- A data structure having nodes and edges.


types:
    1) undirected  2) directed  (see ss).


some terms:
Node - entity can store data
edge - it is for the connection of nodes

degree - for a undirected graph , the number of edges connected to a node is its degree.    
        for directed graph we have 2 types of degrees-
        1) indegree - no. of edges coming towards the node.
        2) outdegree - no. of edges going from the node.

weighted graph-
    Here we have some weights assigned to the edges. 
    If there no weights given in a graph and the question demands then we can give the weights as 1.

cyclic graph - 
    agar travel karte karte same node pr pohoch jaaye toh wo cyclic graph khlata hai.
    directed graph mein tabhi cycle banti jab wo arrows ko follow krke same point pe pohoche.

disconnected graph - jisme kuch components alag bhi ho, means kuch grouping ho jo aapas mein connected na ho.

path - sequence of nodes to reach from source node to destination node.
        u-v-p = path
        p-q-v = path
        p-q-v-p !=path as here p has come 2 times and thus forming a cycle and a path cannot have a cycle.

        WAYS OF REPRESENTING A GRAPH
        1) Adjacency matrix   2) adjacency list.
        

    1) adjacency matrix
        it will be a matrix in which nodes will be mapped with each other and then if there is an edge between
        any two, then it will have 1 otherwise 0 see ss.
    2) adjacency list
        saari nodes list kar denge aur phir har nodes ki ek alag list hogi ki usse kaun kaun si nodes connected
        hain.
        like: 1-> 0,3, 5
              2-> 5, 2, 1
              7-> 3, 5
              see ss it would be like a map<int, list<int>>

              2nd method: can be of vector<int> adj[] or vector<vector<int>>
              array of vectors, where each array index denotes the key and the values of the array denotes the
              neighbours

*/

#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class graph{

    public:
    unordered_map<int, list<int>> adj;//adjacency list.
    
    void addEdge(int u, int v, bool direction){ //means u se v ek edge add kardo
        //if direction =0 , then the graph is undirected
        //if direction =1, then the graph is directed.
        adj[u].push_back(v);

        if(direction==0) adj[v].push_back(u);

    }

    void printGraph(){
        for(auto i: adj){
            cout<<i.first<<"-->";
            for(auto j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

};


int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin >> n;
    int m;
    cout<<"Enter the number of edges: ";
    cin>>m;
    graph g;

    for(int i=0; i<m; i++){
        int u;
        int v;
        cout<<"enter "<<i+1<<"th edge points: ";
        cin>>u>>v;
        g.addEdge(u, v, 0);
    }

    g.printGraph();

    return 0;
}

//https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551?leftPanelTab=1
// https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
//for second method of representation.
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    //A NEW THING this is array of vectors.
    vector<int> neighbour[n]; //har vertice ko index maankar chalenge
   
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        neighbour[u].push_back(v);
        neighbour[v].push_back(u);
    }
    
    vector<vector<int>> ans(n);
    
    for(int i=0; i<n; i++){
        ans[i].push_back(i);
        for(int j=0; j<neighbour[i].size(); j++){
            ans[i].push_back(neighbour[i][j]);
        }
    }
    
    return ans;
}


//time complexity: O(E+V)
//space comp: O(v).