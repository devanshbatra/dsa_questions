/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
*/

/*
approach: we will make a recursive function
            inside it we will traverse the 2d array and see the empty position
            //FOR EACH RECURSION CELL.
            when empty position is found then we will see which number from 1 to 9 is safe to insert there
            if a number is found safe - then we will check for other spaces
            if all other spaces return true then we also return true for this empty space.
            if not - then we may have put something wrong before, so backtrack.


            isSafe function:
            row aur column mein check to easy hai.
            for block:
                for row we need to have some thing which depends on i from 1 to 9 but it should be 0 0 0
                                                                                                   1 1 1
                                                                                                   2 2 2
                for column of the block we need something like 0 1 2 and then first column of the block added to it
                                                               0 1 2
                                                               0 1 2
                so we found the formula : board[3*(row/3)+i/3][3*(col/3)+i%3]

*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:

    bool isSafe(vector<vector<char>> &board, int val, int row, int col){
        char ch = char('0'+val);

        //not to be in same row
        for(int j=0; j<9; j++){
            //not in same row
            if(board[row][j]==ch) return false;

            // not in same col
            if(board[j][col]==ch) return false;


            //not in same box
            if(board[3*(row/3)+j/3][3*(col/3)+j%3]==ch) return false;

        }

        return true;
    }

    bool solveSudokuUtil(vector<vector<char>>& board){
        //base case


        //rc
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                //if empty
                if(board[row][col]=='.'){
                    //try placing from 1 to 9
                    for(int i=1; i<=9; i++){
                        //placing i
                        if(isSafe(board, i, row, col)){
                            board[row][col] = char('0'+i);
                            //rc
                            bool isSolutionPossAhead = solveSudokuUtil(board);
                            if(isSolutionPossAhead) return true;
                            else{
                                //backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    //agar saari values try kar li hain aur true return nhi hua hai to means is possible nhi hai
                    return false;
                }
            }
        }   
        //agar saari empty spaces bhar gai hai aur return false bhi nhi hua so return true;
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuUtil(board);
    }
};