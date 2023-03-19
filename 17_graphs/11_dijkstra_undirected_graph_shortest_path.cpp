//Dijkstra Algorithm is used to find the single source shortest path to all other nodes in a weighted
	//undirected graph.
	//steps:
	//since here there is no directions involved so we do not have to find the topological order, bas sabse min
    //wali edge ko uthao aur uske children ko ease karo, ab simple si baat h source se he shuru hoga because
    //source ko he toh ham zero dalenge.
	//we just need to make a MIN_HEAP or set and select the minimum distance from it for processing our 
	//distance array.
	
	//steps:
	//1) make a set of pairs like <distance, nodeValue>
	//2) make a distance vector with every node as infinte and source distance as 0 initially.
	//3) insert the source distance in the set.
	//4) make a loop while(!set.empty())
	//5) inside the loop take out the min of the set and store as currNode.
	//6) traverse the children of the minNode and see if dist{child]>weight+dist[currNode]
	//7) if true then check if this distance and child pair are already there in set .
	//8) if yes in set then remove it as we have to update this pair in the set also.
	
	//9) now set the dist[child] as the newdist.
	//10)insert the newdist, child pair in the set.
	//11)done.
	
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.

    //TRY THIS after dijkstra: hard level question using dijkstra.
    //https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/


#include<iostream>
#include <vector>
#include <set>
#include <limits.h>

using namespace std;
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //make a set
        set<pair<int, int>> s;
        //set : pair<distance, nodevalue>
        
        //push the source node in set
        s.insert(make_pair(0, S));
        
        //make distance vector
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        
        
        while(!s.empty()){
            //fetch top node , store and pop from the set.
            pair<int, int> p = *(s.begin());//star isliye because .begin() ek pointer return karta hai 
            int node = p.second;
            int nodeDist = p.first;
            s.erase(p);
            
            //traverse the children of nodes and update their distance.
            for(int i=0; i<adj[node].size(); i++){
                int child = adj[node][i][0];
                int weight = adj[node][i][1];
                if(dist[child]> nodeDist+weight){
                    //remove previous distance from set if available
                    if(s.find(make_pair(dist[child], child))!=s.end()){
                        s.erase(make_pair(dist[child], child));
                    }
                    dist[child] = nodeDist+weight;
                    s.insert(make_pair(dist[child], child));
                    
                }
            }

            
        }
        
        return dist;
        
    }