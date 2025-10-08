// Transpose of an nXn matrix(inplace)
// https://www.geeksforgeeks.org/problems/transpose-of-matrix-1587115621/1



//approach:
//Just need to swap elements across the diagonal
#include <iostream>
#include <vector>

class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        
        int row = mat.size();
        int col = mat[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        return mat;
    }
};