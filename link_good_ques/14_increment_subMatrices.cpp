// https://leetcode.com/problems/increment-submatrices-by-one/
// Imagine each row as a separate array. Instead of updating the whole submatrix together,
// we can use prefix sum to update each row separately.
    
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//in this question if we use the brute force then we are getting 25*10^8. complexity which is roughly 10^9.so limits exeeded.
//so we will use the concepts of end limiters here.
//let's say we solve this problem row by row.
//now for a single row- we will first create a limiter row- 0 0 0 0 0 0 0.
//given col1 and col2.
//mark limiter[col1]+=1 and limiter[col2+1] -=1. why so?
//se when we do normally we would be traversing the whole queries wali row*col times.
//but here without traversing we just have put flags- 1 at starting and -1 at next to ending.

//while forming our solution - 0 0 1 0 0 -1 0 0. suppose this is our scenario then we would take a counter and put acc = 0(initially).
//will then traverse the row and-
//acc+=limiter[col]
//ans[col] = acc

//agar overlapping bhi h toh bhi resolve ho jaayega, make a dry run u will get to know

//tc: O(q*n + n^2). which goes roughly - 10^6-10^7.

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<vector<int>> limiter(n, vector<int>(n, 0));
    
    //processing limiter
    int q = queries.size();
    for(int i=0; i<q; i++){
        int r1 = queries[i][0];
        int r2 = queries[i][2];
        int c1 = queries[i][1];
        int c2 = queries[i][3];
        
        for(int i=r1; i<=r2; i++){
            limiter[i][c1] += 1;
            
            if(c2+1<n)
                limiter[i][c2+1]-=1;
        }
        
    }
    
    //forming ans
    for(int r=0; r<n; r++){
        int counter=0;
        for(int c=0; c<n; c++){
            counter+=limiter[r][c];
            ans[r][c] = counter;
        }
    }
    
    return ans;
    
}