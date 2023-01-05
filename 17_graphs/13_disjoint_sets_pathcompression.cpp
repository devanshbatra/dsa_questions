/*
DISJOINT SETS- (easy concept but very important)
    Disjoint sets is a data structure which:
    -can be used in kruskals algorithm to find minimum spanning tree, 
    -can be used to DETECT CYCLE in a graph, 
    -can be used to find whether two nodes belong to same components or different components in a graph.

    BASICALLY IT HAS 2 OPERATIONS:
        1) findParent(node) - returns the parent of the node.
        2) union(node1, node2) - make the disconnected nodes connected .
        see ss for visualization of these operations.

    We will do an efficient implementation of disjoint sets by using rank and parent data structures.

    Algorithm:
        1) make two vectors rank and parent.
        2) initialize rank all with 0 and initially all are parent of themselves.

        union(a, b) - 
            - check the most upper parents of a and b. check uptill the parent of parent is itself also do
                path compression.(discussed later.)
            - now compare the ranks of both the parents.
            - if same-
                then make any one as a child of another one. let say u and v were there so, parent[v]= u;
                also remember when ranks are same - increase the rank of new parent by 1, so rank[u]++;

            - if rank[u]> rank[v]
               then make greater rank digit as parent.
               parent[v] = u.

            - if rank[v]> rank[u]
                parent[u] = v.

            Now what is path compression?
            - it is the process of reducing the complexity of finding the upper most parent.
              once we have found the uppermost parent of a node d as a.
              then directly put parent[d] as a. so that a becomes its direct parent and next time some one
              a query to find the parent of d then we do not need to dive deep.

              see ss2.

            
            findParent(a).- recursive
             if(parent[a]==a) return a;

             parent[a] = findParent[parent[a]]; (for path compression)
             return parent[a]; 

*/

#include<iostream>
#include <vector>
using namespace std;

//prototype
int findParent(int, vector<int>&);

void doUnion(int a, int b, vector<int>& parent, vector<int>& rank){
    a = findParent(a, parent);
    b = findParent(b, parent);

    if(rank[a]>rank[b]){
        parent[b] = a;
    }
    else if(rank[b]>rank[a]){
        parent[a] = b;
    }
    else{
        parent[b] = a;
        rank[a]++;
    }

}

int findParent(int a, vector<int>& parent){
    if(parent[a] == a) return a;

    parent[a] = findParent(parent[a], parent);
}

int main(){

    int v = 8;

    vector<int> parent(v);
    vector<int> rank(v, 0);

    for(int i=0; i<v; i++){
        parent[i] = i;
    }

    doUnion(1, 2, parent, rank);
    doUnion(2, 3, parent, rank);
    doUnion(4, 5, parent, rank);
    doUnion(6, 7, parent, rank);
    doUnion(5, 6, parent, rank);
    doUnion(3, 7, parent, rank);

    for(auto i: parent){
        cout<<i<<" ";   
    }

    //now two nodes lie in the same component if their uppermost parent is same.




    return 0;
}

//time complexity: studies show that tc of findparent and dounion function are nearly constant O(1). basically 
// O(4alpha ) or O(4) hota hai.



