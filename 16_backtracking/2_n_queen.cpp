//The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other.
// https://leetcode.com/problems/n-queens/description/


//we have to place n queens at nxn box with no 2 at same row, column and diagonal
//since we previously know that we have to avoid same rows, so it is clear that every row will have exactly one
//queen.
//yahan BABBAR ne recursion mein column ke liye check kiya tha, but mein row ke liye kr rha hun.
//approach: place the queen at the first row

/*          -now traverse each column of that row and for each column check if it is safe to place queen there.
            -if it is safe to place then place the queen there and make a recursive call for the next row.
            -base case will be when row reaches n.

            IS SAFE FUNC.
            -it will check if the position at which queen is placed is not attacking any other queen.
            -since we are moving from 1 row to last so uppar he hogi queen neeche to hogi nhi
            -aur kyoki hum ek row mein ek he queen place kar rhe hain to same us row mein bhi check krne ki noneed
            -bas check top-left and top-right diagonals and the column up.*/


//THERE IS AN OPTIMIZATION EXPLAINED IN THE END.


#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

    bool isSafe(vector<string> &board, int n, int col, int row){
        //check if this pos queen can attack anyone or not.
        //you are traversing row by row
        //so peeche he koi row hoga, aage nhi hoga
        //so same col mein traverse karo jahan ho wahan se peeche tak
        for(int i=row; i>=0; i--){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //seeing top left diagonal
        int i = row-1;
        int j = col-1;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }

        //seeing top right diagonal
        i = row-1;
        j = col+1;
        while(i>=0 && j<n){
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }


        return true;
    }

    void solve(vector<string>& board, vector<vector<string>>& ans, int row, int n ){
        //base case
        if(row>=n){
            ans.push_back(board);
            return;
        }

        for(int col =0; col<n; col++ ){ //for row
            if(isSafe(board, n, col, row)){
                //put q in ans
                board[row][col] = 'Q';
                // cout<<"found safe at"<<row<<" "<<col<<",,,, ";
                //rc
                solve(board, ans, row+1, n);
                //back track
                // cout<<endl;
                board[row][col] = '.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        //make a board of nxn for storing outputs at each call
        vector<string> board(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                board[i].push_back('.');
            }
        }
        vector<vector<string>> ans;
        solve(board, ans, 0, n);
        return ans;
    }
};


//OPTIMIZATION
//THERE is an optimization that we can do at the isSafe step.
//for now we are using O(N) time complexity there for seeing if there exists any q in attacking position
//but by maintaining a hash map we can avoid this.
//1) for upper column use a <int: bool> hash unordered_map for col: t/f
//2) for top right diagonal we know we are doing row+1 and col+1 , so if we make a noting we get that 
//  for every cell in that diagonal we have sum of row and column as same. (see ss).

//3)for top right diagonal we see that row-col ( or if we need only positive values take (n-1+row-col) )
// is same for this diagonal as we are doing col-1 and row-1.


//optimized wala code
class Solution {
public:

    bool isSafe(int n, int col, int row, unordered_map<int, bool>& colMap, unordered_map<int, bool>& sumMap, unordered_map<int, bool>& diffMap){
        //optimized is safe

        if(colMap.count(col) && colMap[col]==true) return false;
        if(sumMap.count(col+row) && sumMap[(row+col)]==true ) return false;
        if(diffMap.count(n-1+col-row) && diffMap[n-1+col-row]==true )  return false;

        return true;
    }

    void solve(vector<string>& board, vector<vector<string>>& ans, int row, int n, unordered_map<int, bool> &colMap, unordered_map<int, bool>& sumMap, unordered_map<int, bool>& diffMap ){
        //base case
        if(row>=n){
            ans.push_back(board);
            return;
        }

        for(int col =0; col<n; col++ ){ //for row
            if(isSafe(n, col, row, colMap, sumMap, diffMap)){
                //put q in ans
                board[row][col] = 'Q';
                //optimization- updating maps
                colMap[col] = true;
                sumMap[col+row] = true;
                diffMap[n-1+col-row] = true;
                // cout<<"found safe at"<<row<<" "<<col<<",,,, ";
                //rc
                solve(board, ans, row+1, n, colMap, sumMap, diffMap);
                //back track
                // cout<<endl;
                board[row][col] = '.';
                colMap[col] = false;
                sumMap[col+row] = false;
                diffMap[n-1+col-row] = false;
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        //make a board of nxn for storing outputs at each call
        vector<string> board(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                board[i].push_back('.');
            }
        }
        unordered_map <int, bool> colMap;
        unordered_map<int, bool> sumMap;
        unordered_map<int, bool> diffMap; 
        vector<vector<string>> ans;
        solve(board, ans, 0, n, colMap, sumMap, diffMap);
        return ans;
    }
};


//time and space complexity remains same for both optimized and original
//time complexity: n!
//space complexity: n^2