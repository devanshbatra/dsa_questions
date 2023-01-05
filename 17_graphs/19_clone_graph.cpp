// https://leetcode.com/problems/clone-graph/description/
//In this question we have applied recursion.
    //the main catch is making the original : clone hashmap.

    // what we will do is :
    // think of a single case
    // do dfs and in the individual call
    // make a cloneNode and initialize with orignal value
    // also make a neighbor array.
    // mark it as visited by marking its entry in the original: clone node.
    // now traverse it children
    // if( children not visited before) then call dfs.
    //      dfs returns a the neighbor , so push it in the neighborarray.
    // else if children already visited, then also we need to push in cloneneighborArr so push from that original: clone
    // mapping.

    //now cloneNode->neighbors = cloneNeighbor;
    // and return cloneNeighbor;

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//utility class copied from leetcode
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

 //used recursion
Node* dfs(Node* curr, unordered_map<Node*, Node*>& visited){
    vector<Node*> cloneNeighbor;
    Node* cloneNode = new Node(curr->val);
    visited[curr] = cloneNode; //storing in visited and preparing the original: clone hashmap.
    
    //traversing its neighbors
    for(int i=0; i<curr->neighbors.size(); i++){
        if( visited.find(curr->neighbors[i])==visited.end() ){
            Node* newNeighbor = NULL;
            newNeighbor = dfs(curr->neighbors[i], visited);
            cloneNeighbor.push_back(newNeighbor);
        }else{//if already visited hai to uska use clone chahiye-  jo original: clone map se ban jaayega.
            cloneNeighbor.push_back(visited[curr->neighbors[i]]);
        }
    }
    cloneNode->neighbors = cloneNeighbor;
    return cloneNode;
}
Node* cloneGraph(Node* node) {
    if(node==NULL) return NULL;
    //doing bfs traversal
    unordered_map<Node*, Node*> visited;//will tell visited or not and also prepare a list of original: clone
    return dfs(node, visited);
    
}