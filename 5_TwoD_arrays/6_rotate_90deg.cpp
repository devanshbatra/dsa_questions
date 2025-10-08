// to rotate a matrix by 90deg
// https://leetcode.com/problems/rotate-image/description/
/*
1 2 3       7 4 1
4 5 6  ==>  8 5 2
7 8 9       9 6 3
*/

/*
Approach:   
for this we need to first compute the transpose and then reverse every row.
*/
using namepace std;
#include <vector>
class Solution {
public:

    void reverseRow(vector<vector<int>>& matrix, int rowNumber, int cols){

        int s = 0, e = cols-1;

        while(s<e){
            swap(matrix[rowNumber][s++], matrix[rowNumber][e--]);
        }

    }

    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            for(int j = i+1; j<col; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int r = 0; r<row; r++) reverseRow(matrix, r, col);


    }
};