//  BACKTRACKING -
//     1) checking every possible solution for the problem.
//     2) discarding all the already visited solutions and not visiting them again.
//     3) after we visit a solution and go to previous node we clear any changes made by this node.


//RAT IN A MAZE PROBLEM
//Already done previously
//time complexity: O(4^(n*n))
//space complexity: O(m*n) due to the function call stack
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
    
    void solve(vector<vector<int>>& m, int n, vector<vector<int>> &visited, int x, int y, string path, vector<string>& ans  ){
        //base case
        if(x==n-1 && y==n-1) {
            ans.push_back(path);
            return;
        }
        
        //we need to check D,L,U,R
        //down - x+1, y
        visited[x][y] = 1;
        if(
            (x+1) >= 0 && (x+1)<n &&
            m[x+1][y] == 1 &&
            visited[x+1][y] == 0
        ){
            //path mein daalo, visited ko true karo, rc maaro, backtrack karo
            path.push_back('D');
            solve(m, n, visited, x+1, y, path, ans);
            //backtrack
            path.pop_back();
        }
        
        //left - x, y-1
        if(
            y-1 >= 0 && y-1 < n &&
            m[x][y-1]==1 &&
            visited[x][y-1]==0
        ){
            path.push_back('L');
            solve(m, n, visited, x, y-1, path, ans);
            path.pop_back();
        }
        
        //up - x-1, y
        if(
            x-1 >= 0 && x-1 < n &&
            m[x-1][y]==1 &&
            visited[x-1][y]==0
        ){
            path.push_back('U');
            solve(m, n, visited, x-1, y, path, ans);
            path.pop_back();
        }
        
        //right - x, y+1
        if(
            y+1 >= 0 && y+1 < n &&
            m[x][y+1]==1 &&
            visited[x][y+1]==0
        ){
            path.push_back('R');
            solve(m, n, visited, x, y+1, path, ans);
            path.pop_back();
        }
            
        //backtrack
        visited[x][y] = 0;
        
        
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        //edge case
        vector<string> ans;
        if(m[0][0]==0) return ans;
        
        vector<vector<int>> visited(n);
        //initialize visited
        for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                visited[i].push_back(0);
            }
        }
        string path = "";
        solve(m, n, visited, 0, 0, path, ans);
        
        return ans;
    }
};