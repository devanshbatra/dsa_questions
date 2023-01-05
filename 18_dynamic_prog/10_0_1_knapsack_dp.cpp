#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//when we reside on an index we have two options:
// whether to include it or not.
// if we include it then add its value in the solution and solve for next index and also decrease the capacity for next solution.
// if we exclude it then do not add its value and call for next index and do not change capacity also.

//dp recursion + memoizaton
//step1) make a dp of appropriate size.
//step2) after base case check if the dp already contains the ans for the given subproblem.
//step3) if not then find the ans and then save the obtained ans.

//for dp, here 2d dp array would be used why?
// when we se the recursive function that there are two variables that are changing while going in subproblems
// so we would make a 2d dp array.

int solve(int capacity, int wt[], int val[], int n, int index, vector<vector<int>> & dp){
    //base case
    if(index==n-1){
        //only one item to fetch and given capacity. 
        //will definately choose it if capacity allows
        if(wt[index]<=capacity){
            return val[index];
        }else return 0;
    }

    
    if(dp[index][capacity]!=-1) return dp[index][capacity];
    
    int include=0;
    //agar capacity allow karti hai tabhi to add krenge iski value.
    if(wt[index]<=capacity)
        include = val[index] + solve(capacity-wt[index], wt, val, n, index+1, dp);
        
    
    int exclude = 0 + solve(capacity, wt, val, n, index+1, dp);
    
    
    return dp[index][capacity] = max(include, exclude);
    
    
}

//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n) 
{
    //making dp row ->index, col->capacity at that moment
    vector< vector<int>> dp( n, vector<int>(W+1, -1) ); //this is the way to initialize a 2d array.
    return solve(W, wt, val, n, 0, dp);
}


//B) tabulation- bottom up approach
int solve(int capacity, int wt[], int val[], int n){
    
    //step1) make dp
    vector<vector<int>> dp(n, vector<int>(capacity+1));
    
    //step2) see base case
    //poori row jiski value n-1 hai uska weight agar cap se kam hai to we should initialize it according to
    //base case
    
    int i = 0;
    for(int j=wt[0]; j<=capacity; j++){
        if(wt[i]<=j) dp[i][j] = val[i];
        else dp[i][j] = 0;
    }
    
    
    //3) start from the next of the base case 
    for(int i=1; i<n; i++){
        for(int w=0; w<=capacity; w++ ){
            int include=0;
            if(wt[i]<=w)
                include = val[i] + dp[i-1][w-wt[i]];
                
            
            int exclude = 0 + dp[i-1][w];
            
            
            dp[i][w] = max(include, exclude);
        }
    }
    
    return dp[n-1][capacity];
    
}

//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n) 
{
    return solve(W, wt, val, n);
}


//c) space optimization
// we can optimize the space from the 2d dp array to a 1d array.
// we can see in the above solution that our curr ans was just depending on the previous row in the dp
// se we just need two rows 1 for curr and one for prev.
// base case ke hisaab se prev row mein data fill kardo.
// aur phir bas jab saare wt ho jaaye tab prev ko curr mein update kar do.
int solve(int capacity, int wt[], int val[], int n){
    
    
    
    vector<int> prevIndex(capacity+1, 0);
    for(int w=wt[0]; w<=capacity; w++){
        if(wt[0]<=capacity) prevIndex[w]= val[0];
        else prevIndex[w] = 0;
    }
    
    vector<int> currIndex(capacity+1, 0);
    //3) start from the next of the base case 
    for(int i=1; i<n; i++){
        for(int w=0; w<=capacity; w++ ){
            int include=0;
            if(wt[i]<=w)
                include = val[i] + prevIndex[w-wt[i]];
                
            
            int exclude = 0 + prevIndex[w];
            
            
            currIndex[w] = max(include, exclude);
            
        }
        prevIndex = currIndex;
    }
    
    return prevIndex[capacity];
    
}

//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n) 
{
    return solve(W, wt, val, n);
}


//One case is left where we can make it to one array, which is to be done next time you visit this question.