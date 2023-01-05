
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//GOOD QUESTION.

// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's
//  and return its area.
// https://leetcode.com/problems/maximal-square/description/
// in this question we will basically track the continuity of 1 along horizontal , vertical and 
// diagonal lines.
//we will start our processing from the first node that is (0, 0).
// at each node we will find answers from left, bottom and diagonal.
// now at this node we will see if (currNode==0) return 0; //no continuity of 1. 1's cont. breaked.
// BUT IF(currNode==1) that means some ans will be returned 
// now we will see which side whether down , up or diagonal has least 1's in continuity.
// as square will be formed by joining all of down up and diagonal 1's so jo sabse chota hoga,
// uske barabar+1(as wo node khud bhi to include hoga) ka he square banega.
// Now to track the maximum square we will make a variable maxi which will track the maximum ans.

//A) recursive+memoization - top down approach.
int solve(vector<vector<char>> & matrix, int x, int y, int &maxi, int rows, int cols, vector<vector<int>>& dp){

//base case
//agar range se he bahar chala jaata hai to waha to koi square nhi he banega so return 0
if(x>=rows || y>=cols) return 0;

if(dp[x][y]!=-1) return dp[x][y];

//rc
//find the ans from right bottom and diagonal.
//bottom
int bottom = solve(matrix, x+1, y, maxi, rows, cols, dp);
int diagonal = solve(matrix, x+1, y+1, maxi, rows, cols, dp);
int right = solve(matrix, x, y+1, maxi, rows, cols, dp);
int ans = 0;
if(matrix[x][y]=='0') return 0;
else{
    //means 1 hai iss node main.
    ans = 1+min(bottom, min(diagonal, right));
    // cout<<"for x,y: "<<x<<", "<<y<<"| matrix[x][y]: "<<matrix[x][y]<<" ans: "<<ans<<endl;
}

//update maxi
maxi = max(maxi, ans);

return dp[x][y] =  ans;

}


int maximalSquare(vector<vector<char>>& matrix) {
int rows = matrix.size();
int cols = matrix[0].size();
int maxi = 0; //INT_MIN Isliye nahi liya bcoz agar single 0 he hua element toh phir INT_min he return kar rha tha

vector<vector<int>> dp(rows, vector<int>(cols, -1));

solve(matrix, 0, 0, maxi, rows, cols, dp);
return maxi*maxi; //square to find area.
}



//B) bottom up approach: tabulation.
int solve(vector<vector<char>> & matrix, int rows, int cols){

    //bottom up approach
    //step 1) make dp of adequate size covering the base case too.
    vector<vector<int>> dp(rows+1, vector<int>(cols+1));

    //step 2) analyse base case
    dp[rows][cols] = 0;


    //step 3 start from the next of base case towards the top
    //also track maxi.
    int maxi = INT_MIN;
    for(int i=rows-1; i>=0; i--){
        for(int j = cols-1; j>=0; j--){
            int bottom = dp[i+1][j];
            int diagonal = dp[i+1][j+1];
            int right = dp[i][j+1];

            if(matrix[i][j]=='0') dp[i][j] = 0;
            else{
                dp[i][j] = 1+min(bottom, min(diagonal, right));
                // cout<<"for i, j: "<<i<<", "<<j<<"| matrix[i][j]: "<<matrix[i][j]<<" ans: "<<dp[i][j]<<endl;
            }

            //update the maxi
            maxi = max(maxi, dp[i][j]);

        }
    }

    return maxi;

}


int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();


    int maxi = solve(matrix, rows, cols);
    return maxi*maxi;
}
//tc and sc: O(m*n).

//C) space optimization.
//we can see that we were using a whole 2d array but we needed just the current row and the prev row
//making two rows only can save us from extra space.

int solve(vector<vector<char>> & matrix, int rows, int cols){

    //space optimized approach.

    vector<int> currRow(cols+1, 0);
    vector<int> prevRow(cols+1, 0);

    
    int maxi = INT_MIN;
    for(int i=rows-1; i>=0; i--){
        for(int j = cols-1; j>=0; j--){
            int bottom = prevRow[j];
            int diagonal = prevRow[j+1];
            int right = currRow[j+1];

            if(matrix[i][j]=='0') currRow[j] = 0;
            else{
                currRow[j] = 1+min(bottom, min(diagonal, right));
                // cout<<"for i, j: "<<i<<", "<<j<<"| matrix[i][j]: "<<matrix[i][j]<<" ans: "<<dp[i][j]<<endl;
            }

            //update the maxi
            maxi = max(maxi, currRow[j]);

        }
        //update the curr and prev rows
        prevRow = currRow;
    }

    return maxi;
}


int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();


    int maxi = solve(matrix, rows, cols);
    return maxi*maxi;
}

//tc: O(m*n) , sc: O(n).

//THIS QUESTION CAN EVEN FURTHER be optimized by using the original array as the dp array.
