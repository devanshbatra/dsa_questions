/*
What is spanning tree?
-When you convert a graph into a tree(no cycle) such that it has N nodes and N-1 edges and Every node is 
reachable to any other node.    

MINIMUM SPANNING TREE
- When you convert a graph into a tree(no cycle) such that it has N node and N-1 edges and every node is 
  reachable to any other node AND out of the multiple spanning trees of a graph , the one having minimum weights 
  is called the minimum spanning tree.

  Now we will be using prims algorithm to find the minimum spanning tree.

*/
//Function to find sum of weights of edges of the Minimum Spanning Tree.

// steps
// 1) make 3 data structures weights, visited, and parent.
// 2) make all weights as infinite , all visited as false and all have a parent of -1;
// 3) choose source node as 0 or 1 as given in ques
// 4) make weight[sourve] = 0 means is tak pohochne ka weight = 0;
// 5) loop - v times
// 6) take min value from weights(which is not visited yet).
// 7) mark is as visited
// 8) see the children of current
// 9) if the child is <<<<not visited>>>>(not yet in mst) and weight[child]>wt(as from curr) - update weight 
//    and make parent[child] = curr.
// 10)repeat jab tak saare true nhi ho jaate (means v times he chlega for loop).

// now you can make the minimum spanning tree using parent and weight vector.

//in this question you need to find the weight sum of mst.
// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include<iostream>
#include <vector>
#include <limits.h>

using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    //1)make weights, visited, and parent
    vector<int> weight(V, INT_MAX);
    vector<bool> visited(V, false); //ye batayega ki kaun kaun mst mein include ho chuke hein.
    vector<int> parent(V, -1);
    
    //2) make source as 0 and make source weight = 0.
    int source = 0;
    weight[source] = 0;
    
    //3) make loop to repeat V times
    for( int i=0; i<V; i++){
        
        //take our min weight and set as curr;
        int mini = INT_MAX;
        int curr = 0;
        for(int j=0; j<V; j++){
            if(weight[j]<mini && !visited[j] ){
                mini = weight[j];
                curr = j;
            }
        }
        //mark visited
        visited[curr] = true;
        // cout<<"curr->"<<curr<<": ";
        
        //traverse children of curr
        for( int j=0; j<adj[curr].size(); j++){
            int child = adj[curr][j][0];
            int wt = adj[curr][j][1];
            
            if(wt<weight[child] && visited[child]==false ){//IMP-jo jo visit nhi hue hai unhi ko he update kar skta hai.
                //set weight and parent
                weight[child] = wt;
                parent[child] = curr;
                
                // cout<<"updated("<<child<<","<<wt<<"), ";
            }
            
        }
        // cout<<endl;
        
    }
    //now we can find that spanning tree using parent and weight vector.
    //find sum of weights as per question requirements
    int sum = 0;
    for(auto i: weight){
        sum+=i;
    }
    
    return sum;
    
}

//time complexity: O(V^2)  but there is one optimization that we can use priority_queue(min heap) in place of
//weights vector as the complexity of finding min element is O(1) there. (check on gfg how to do that.)
//space complecity: O(V).