/*
Kruskals algorithm is used to find the minimum spanning tree by the use of DISJOINT SETS.

how? - ekdum layman logical sa method hai. sabse min edge ko jodte jao.(bas ye pata lagana hai ki same
         component mein ha ya nahi aur wo cheez ham disjoint sets se kar he lete hain.)

         
    -basically we make a disjoint set using parent and ranks
    -initially all ranks are 0 and all nodes are their own parents.
    -here we no not need any adjacency list , here we just need a data structure edges which is vector<vector<int>>
    -such that [1, 2, 8]
              [2, 3, 7]
              [n1, n2, weight] ...
    -sort this vector according to the weights in ascending order.
    -now take out first edge(minimum as it is asc).
    -see if both nodes are in same components by checking parent(disjoint set).
    -if not then union them.
    -if yes then ignore(wo isse kam weight se join ho chuke hain).
*/
// https://www.codingninjas.com/codestudio/problems/minimum-spanning-tree_631769?leftPanelTab=0
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findParent(int a, vector<int>& parent){
    if(a==parent[a]) return a;
    
    parent[a] = findParent(parent[a], parent);
    return parent[a];
}

int doUnion(int a, int b, vector<int>& parent, vector<int> & rank){
    
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

bool comparator(vector<int>& a, vector<int>& b){
    return a[2]< b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for(int i=0; i<n; i++){
        parent[i] = i; //make them their parent initially.
    }
    
    //sort the edges [u, v, weight], [u, v, weight]
    sort(edges.begin(), edges.end(), comparator);
    
    //now traverse the edges and start making the sum
    int sum = 0;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        
        int parU = findParent(u, parent);
        int parV = findParent(v, parent);
        if(parU!=parV) { //means they were not in same segment
            doUnion(u, v, parent, rank);
            sum+=weight;
        }
        //else ignore
    }
    
    return sum;
    
}

//TC: O(eloge) for sorting edges + [O(e) for traversing * O(1) union find] ~ O(eloge).
//space comp: O(N). 


//Try this question after this: https://leetcode.com/problems/find-if-path-exists-in-graph/description/