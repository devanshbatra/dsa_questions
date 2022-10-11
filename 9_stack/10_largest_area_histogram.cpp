#include<iostream>
#include<vector>
#include<stack>
//given a height array, that represents the heights of pillars of histogram
//to calculate the maximum area
/*
Try this ques here:
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

/*
Bruteforce approach: traverse each element of the heights array, now at each element first move right to see when
you encounter an element smaller than current element note its index. then move left to find the same .
now find area covered by the formula right-left-1 for each element.
this would require O(n^2) complexity.

WHAT IF , we get the nextSmaller and prevSmaller elements for each element readymade , find how?


*/

using namespace std;


vector<int> nextSmallerEle(vector<int> arr, int n){
    vector<int> ans(n);//its important to initialize the array as we would insert the element by specifying indexes.
    stack<int> s;
    s.push(-1);
    for(int i=n-1; i>=0; i--){
        int ele = arr[i];
        while(s.top()!=-1 && arr[s.top()]>=ele){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
//O(n)

vector<int> prevSmallerEle(vector<int> arr, int n){
    vector<int> ans(n); //its important to initialize the array as we would insert the element by specifying indexes.
    stack<int> s;
    s.push(-1);
    for(int i=0; i<n; i++){
        int ele = arr[i];
        while(s.top()!=-1 && arr[s.top()]>=ele){ //s.top()!=-1 && - this condition included as we cannot calculate the arr[-1]
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
// O(n)
// This called array preprocessing, that is we made two auxiliary arrays before hand solving the problem.


int largestRectangleArea(vector<int>& heights) {
    vector <int> next;//next smaller index
    vector <int> prev;//prev smaller index
    
    int n = heights.size();
    next = nextSmallerEle(heights, n);
    prev = prevSmallerEle(heights, n);
    
    //ab width of any interval will be nextSmallerIndex - prevSmallerIndex - 1.
    int maxArea = -100;
    for(int i=0; i<n; i++){
        // but nextSmallerIndex would contain -1 for unreachables convert them to n.
        //prev wale mein smaller element unreachable par agar -1 aata bhi hai to sahi hai whi uska delimeter hoga
        if(next[i]==-1) next[i] = n;
        
        int len = heights[i];
        int breadth = next[i]-prev[i]-1;
        
        int newarea = len*breadth;
        if(newarea>maxArea) maxArea= newarea;
        
    }
    
    return maxArea;
    
}
        

int main(){

    
    vector<int> heights = {2,1,5,6,2,3};

    cout<<"The largest area is: "<<largestRectangleArea(heights);



    return 0;
}

// The final TC of the algorithm is O(n).x
// also we have used singular stack everywhere (i.e. no nested data structures used ) so SC = O(n).


//Now try this problem : https://leetcode.com/problems/trapping-rain-water/