#include<iostream>
#include<vector>
#include<string>

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

using namespace std;
bool isSafe(vector<vector<int>> maze,vector<vector<int>> visited, int x, int y, int n){
    if( (x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && maze[x][y]==1 ) return true;
    else return false;
}

void solve(vector<vector<int>> maze, int n, vector<vector<int>> visited,int x, int y, string path, vector<string>& ans){
    //here you have reached x, y.
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    
    //mark visited
    visited[x][y]=1;

    // we have four choices here
    // D L R U
    //DOWN
    int newx = x+1;
    int newy = y;
    if( isSafe(maze, visited, newx, newy, n) ){
        path = path + "D";
        solve(maze, n, visited, newx, newy, path, ans);
        //jab bhi iss function call se wapas aayenge tab path mein se hata dena
        path.pop_back();
    }

    //LEFT
    newx = x;
    newy = y-1;
    if( isSafe(maze, visited, newx, newy, n) ){
        path = path + "L";
        // path.push_back("L"); //or we can use this also
        solve(maze, n, visited, newx, newy, path, ans);
        //jab bhi iss function call se wapas aayenge tab path mein se hata dena
        path.pop_back();
    }

    //RIGHT
    newx = x;
    newy = y+1;
    if( isSafe(maze, visited, newx, newy, n) ){
        path = path + "R";
        solve(maze, n, visited, newx, newy, path, ans);
        //jab bhi iss function call se wapas aayenge tab path mein se hata dena
        path.pop_back();
    }

    //UP
    newx = x-1;
    newy = y;
    if( isSafe(maze, visited, newx, newy, n) ){
        path = path + "U";
        solve(maze, n, visited, newx, newy, path, ans);
        //jab bhi iss function call se wapas aayenge tab path mein se hata dena
        path.pop_back();
    }


    //for backtrack
    visited[x][y]=0;
}

int main(){
    vector<vector<int>> maze{{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    vector<vector<int>> visited{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int n= 4;
    int srcx = 0, srcy = 0;
    string path = "";
    vector<string> ans;
    solve(maze,n, visited, srcx, srcy, path, ans);

    for(auto i: ans){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}