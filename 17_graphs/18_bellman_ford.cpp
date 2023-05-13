/*
BELLMAN FORD ALGORITHM - this algorithm is used to find the shortest distance in directed weighted graph from
            source to all other destinations.

-> But we already had dijkstra, then why do we need to have bellman ford algo
-> Because dijkstra has a drawback that it could not be applied correctly when the graph also contain negative
   weights. try finding from this example: [A, B, 5], [A, C, 6], [C, B, -3]. the shortest path from A to B can 
   be find out using by travelling directly to B and through and both have different weights.

-> But bellman form can find out the single source shortest path of graph with negative weights provided that
    There is no negative cycle.
-> This is the limitation of bellman ford -  The graph should not have a negative cycle.
   see ss attached for negative cycle.

SO, NOW there arise two uses of bellman ford=
1) to find the shortest distance of all other nodes from this node.
2) To detect if there is any negative cycle in the graph.

approach : steps
    1) develop an array of distance with source as 0 and others as infinity.
    2) now for n-1 times do: 
    3) we have the array of edges like [u, v, wt], [u, v, wt].....traverse it.
     (basically ye operation n-1 times karna hai har edge ke liye).
    4) do the operation: dist[v] = min( dist[u]+w, dist[v] )

    5) now do this operation one more time and see if there is any change in the distance array.
    6) if there is a change in nth time too then it means that there is a negative cycle.
    7) If not then then dist vector is your ans.
*/
#include <iostream>
#include <vector>
using namespace std;
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1, 1e9); //1e9 is the max value given in here.
    dist[src] = 0;
    //doing that operation n-1 times on every edge
    for(int i=0; i<n-1; i++){
        
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u]!=1e9 && dist[v]>dist[u]+wt ){ //1st condition is just to avoid overflow when we would add weight to dist[u]. it has nothing to do with bellman ford algorithm.
                dist[v] = dist[u]+wt;
            }
        }
        
    }
    //now do it one more time
    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        
        if(dist[u]!=1e9 && dist[v]> (dist[u]+wt)){//means negative cycle is present
            return -1;
        }
    }
    
    //else return the asked ans
    return dist[dest];
    
}

//time complexity: O(v*e).
//space complexity: O(v).