// https://leetcode.com/problems/maximal-rectangle/description/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

//in this question we will find the largest area of the histogram(stack) for every row and find the max area.
//for that we may need a heights array.
//https://leetcode.com/problems/largest-rectangle-in-histogram/description/

//same code from largest area in histogram.
vector<int> nextSmallerEle(vector<int>& heights){
    int n= heights.size();
    stack<int> s; //stores index
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        int curr = heights[i];
        
        while(s.top()!=-1 && curr<=heights[s.top()]) s.pop();

        if(s.top()==-1) ans[i] = n;
        else ans[i] = s.top();

        s.push(i);

    }

    return ans;
}


vector<int> prevSmallerEle(vector<int>& heights){
    int n= heights.size();
    stack<int> s; //stores index
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        int curr = heights[i];
        
        while(s.top()!=-1 && curr<=heights[s.top()] ) s.pop();

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}


int largestRectangleArea(vector<int>& heights) {
    vector<int> nextSmaller;
    vector<int> prevSmaller;
    nextSmaller = nextSmallerEle(heights);
    prevSmaller = prevSmallerEle(heights);


    //max rectangle on a column = nextSmaller-prevSmaller-1
    int ans = INT_MIN;
    int n = heights.size();
    for(int i=0; i<n; i++){
        int length = heights[i];
        int width = nextSmaller[i]-prevSmaller[i]-1;
        ans = max(ans, length*width);
    }

    return ans;
}



int maximalRectangle(vector<vector<char>>& matrix) {
    //making heights array.
    //ye denote karega ki har row mein kitne height ka histogram ban raha hai.
    int r = matrix.size();
    int c = matrix[0].size();

    vector<vector<int>> heights(r, vector<int>(c, 0));

    vector<int> sum(c, 0);

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrix[i][j]=='1') sum[j]+=1;
            else sum[j] = 0;

            heights[i][j] = sum[j];
        }
    }

    //now checking area of histograms for every row
    int maxArea = INT_MIN;
    for(int i=0; i<r; i++){
        int area = largestRectangleArea(heights[i]);
        maxArea = max(maxArea, area);
    }


    return maxArea;
}