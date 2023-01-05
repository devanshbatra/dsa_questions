/*
Articulation points - 
    Articulation points in a graph is a point which if removed can make the graph disconnects( or more general,
    can increase the components of a graph).

    approach 1 : brute force - har point ko remove karke dekh lo, kitne kitne components ban rhe hain.

    approach 2 : It is just same as the bridges approach(see its ss).
                but there is one change.
                the articulation condition while backtracking is:
                    if(low[child]>=disc[curr] && parent[curr]!=-1 ){
                        //means the child could not find any way to connect the elements before curr node(no back edge).
                        //so if we delete curr then there will be two components
                        // SO CURR - > ARTICULATION POINT.
                    }
                
                -difference from bridge detection method.
                    //main
                    1) we have included a second condition parent[curr]!=1 as if we see ,
                        the first condition which is low[child]>=disc[curr] will always be true for the 
                        source node, but there can be a chance where 
                        a) source node has multiple child(more than 1) - then it is an articulation point
                        b) source node has single child - then it is NOT ARTICULATION.

                        so for the source node we will check separately:
                        if(adj[source].size()>1) then yes it also articulation.


                    2) we have included a = sign in the condition
                        because agar koi back hai aur wo 1 ke equivalent node se he ban paayi hai. to koi matlab nhi
                    

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph{
    public:
        unordered_map<int, vector<int>> adj;



        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

};



void  dfs(unordered_map<int, vector<int>>& adj, int curr, int& timer, int parent, vector<int>& disc, vector<int>& low, unordered_map<int, bool>& visited, vector<int>& ans){

    visited[curr] = true;
    disc[curr] = timer;
    low[curr] = timer;
    timer++;

    for(int i=0; i<adj[curr].size(); i++){

        int child = adj[curr][i];
        if(!visited[child]){
            dfs(adj, child, timer, curr, disc, low, visited, ans);
            //agar back edge banai ho to we need to update the low of curr
            low[curr] = min(low[curr], low[child]);
            //check if this point is articulation or not based on the previous child- means kahi is child ko backedge na mili ho to wo to alag he ho jaayega na jab curr ko remove kia jaayega
            //arti condition
            if(low[child]>=disc[curr] && parent!=-1){
                ans.push_back(curr);
            }
        }
        else if(child!=parent){ //visited hai aur parent bhi nhi hai- means back edge mil gayi hai
            low[curr] = min(low[curr], disc[child]);
        }

    }


}

/*
input: v = 5, e = 5
edges
0 1
0 3
1 2
0 2
3 4
*/


int main(){

    int v;
    cout<<"enter vertices number: ";
    cin>>v;
    int e;
    cout<<"enter edges number";
    cin>>e;
    Graph g;
    cout<<"Now enter the edges"<<endl;
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }

    //making data structures
    unordered_map<int, bool> visited;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;

    int timer = 0;
    vector<int> ans;


    for(int i=0; i<v; i++){
        if(!visited[i]){
            //checking externally for source
            if(g.adj[i].size()>1) ans.push_back(i); 
            dfs(g.adj, i, timer, parent, disc, low, visited, ans);
        }
    }

    cout<<"printing articulation points: ";

    for(auto i: ans){
        cout<<i<<" ";
    }



}
//time complexity: dfs = O(V+E).
//space - O(V).