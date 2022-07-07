#include<iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://practice.geeksforgeeks.org/problems/max-rectangle/1#
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix. 

Approach : Here we will use the concept of finding the maximum area in a histogram and compute the area
            through row .
            pehle first row ka, fir second + first row ka, fir first+second+third row ka.
            for interpretation see screen shot.
*/



    vector<int> nextSmallerElement(int * v, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            int ele = v[i];
            
            while(s.top()!=-1 && v[s.top()]>=ele){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(int *v, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int ele = v[i];
            
            while(s.top()!=-1 && v[s.top()]>=ele){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int maxAreaHistogram(int* heights, int n){
        vector<int> next;
        vector<int> prev;
        
        next = nextSmallerElement(heights, n);
        prev = prevSmallerElement(heights, n);
        
        int maxarea = INT_MIN;
        
        for(int i=0; i<n; i++){
            if(next[i]==-1) next[i] = n;
            
            int width = next[i]-prev[i]-1;
            int newarea = heights[i] * width;
            
            maxarea = max(maxarea, newarea);
            
        }
        return maxarea;
    }



int maxArea(int M[4][4], int n, int m) {
        
        //compute area for the first row
        int area = maxAreaHistogram(M[0], m);
        
        //Now compute area from 1st row onwards by adding the previous rows also
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                
                //now update : by adding the previous rows value
                //remember to avoid the column having 0 and make that field 0.
                if(M[i][j]!=0)
                    M[i][j] = M[i][j]+M[i-1][j];
                else
                    M[i][j] = 0;
                
            }
            
            //now calculate area of histogram for this particular row.
            int newarea = maxAreaHistogram(M[i], m);
            
            area = max(area, newarea);
            
        }
        return area;
        
        
    }


int main(){

    int M[4][4] = {{0, 1, 1, 0},
         {1, 1, 1, 1},
         {1, 1, 1, 1},
         {1, 1, 0, 0}};

    cout<<"The maximum area rectangle is: "<<maxArea(M, 4, 4);

    return 0;
}

//time complexity is: O(m*n) as we are running two loops as the area in histogram was completed in just
//O(n) so , the final complexity is O(m*n).
//SC: ussed stack in histo wala, we have used the number of columns present O(m)