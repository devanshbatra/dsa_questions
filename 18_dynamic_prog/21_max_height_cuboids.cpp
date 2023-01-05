// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//approach:
// we can take anyone of the three values as our height , width, length.
// since we want max height so we will sort every triplet. and the max one will be our height.
// now other two remaining sides will be our base.(problem has drawn down into two parameters).
// now sort the whole vector of vector according to the first parameter. If first parameter is same sort acc
// to the second parameter and if it is also same then sort according to the third parameter.
// now our width(let's say is sorted). and we have random values in length and height.
// now we can easily apply longest increasing subsequence in the sides lenght and height 1st and 2nd index as 0 is already
// sorted.


//agar hum sort according to height he kar dete then there would be confusion width and lengh
// which one to take (as rotation is also allowed).


//A) recursion + memoization

//simple lis code just some conditions changed, also prev ko n lene ka try bhi kiya h(waise tabulation mein 
// ye nhi chal paayega. as wahan loop mein chalega, so n se ek dam 0 hona mushkil h.)
int solve(vector<vector<int>>& cuboids, int n, int curr, int prev, vector<vector<int>>& dp){
    //base case
    if(curr>=n) return 0;

    if(dp[curr][prev]!= -1) return dp[curr][prev];

    //rc
    int include = 0;
    //include
    if(prev==n ||  (  cuboids[curr][1]>=cuboids[prev][1] && cuboids[curr][2]>=cuboids[prev][2]) ){
        include = cuboids[curr][2] + solve(cuboids, n, curr+1, curr, dp);
    }

    //exclude
    int exclude = 0+solve(cuboids, n, curr+1, prev, dp);

    return dp[curr][prev] = max(include, exclude);

}


static bool comparator(vector<int>& a, vector<int>& b){
    if(a[0]!=b[0]) return a[0]<b[0];
    else if (a[1]!=b[1]){
        return a[1]<b[1];
    }
    else return a[2]<b[2];
}

int maxHeight(vector<vector<int>>& cuboids) {
    int n = cuboids.size();
    //sorting individual triplets
    for(int i=0; i<n; i++){
        sort(cuboids[i].begin(), cuboids[i].end());
    }
    //sorting whole vector according to the smallest side.
    sort(cuboids.begin(), cuboids.end(), comparator);

    for(auto a: cuboids){
        for(auto i: a) cout<<i<<" ";
        cout<<endl;
    }

    //applying LIS to the middle side.
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve(cuboids, n, 0, n, dp);

    
}

//tc: O(N^square). 
//sc: O(N^square).

//B) tabulation
int solve(vector<vector<int>>& cuboids, int n){
    //initialize dp of adequate size
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    //analyze base case
    for(int i=0; i<=n; i++){
        dp[n][i] = 0;
    }

    //start from the next of base case
    for(int curr=n-1; curr>=0; curr--){
        for(int prev=-1; prev<n; prev++){
            int include = 0;
            //include
            if(prev==-1 ||  (  cuboids[curr][1]>=cuboids[prev][1] && cuboids[curr][2]>=cuboids[prev][2]) ){
                include = cuboids[curr][2] + dp[curr+1][curr+1];
            }

            //exclude
            int exclude = 0+dp[curr+1][prev+1];

            dp[curr][prev+1] = max(include, exclude);
        }
    }

    return dp[0][0];



}


static bool comparator(vector<int>& a, vector<int>& b){
    if(a[0]!=b[0]) return a[0]<b[0];
    else if (a[1]!=b[1]){
        return a[1]<b[1];
    }
    else return a[2]<b[2];
}

int maxHeight(vector<vector<int>>& cuboids) {
    int n = cuboids.size();
    //sorting individual triplets
    for(int i=0; i<n; i++){
        sort(cuboids[i].begin(), cuboids[i].end());
    }
    //sorting whole vector according to the smallest side.
    sort(cuboids.begin(), cuboids.end(), comparator);

    for(auto a: cuboids){
        for(auto i: a) cout<<i<<" ";
        cout<<endl;
    }

    //applying LIS to the middle side.
    return solve(cuboids, n);

    
}

//C) space optimization 1
int solve(vector<vector<int>>& cuboids, int n){

    vector<int> nextRow(n+1, 0);
    vector<int> currRow(n+1);

    //start from the next of base case
    for(int curr=n-1; curr>=0; curr--){
        for(int prev=-1; prev<n; prev++){
            int include = 0;
            //include
            if(prev==-1 ||  (  cuboids[curr][1]>=cuboids[prev][1] && cuboids[curr][2]>=cuboids[prev][2]) ){
                include = cuboids[curr][2] + nextRow[curr+1];
            }

            //exclude
            int exclude = 0+nextRow[prev+1];

            currRow[prev+1] = max(include, exclude);
        }
        nextRow = currRow;
    }

    return currRow[0];



}


static bool comparator(vector<int>& a, vector<int>& b){
    if(a[0]!=b[0]) return a[0]<b[0];
    else if (a[1]!=b[1]){
        return a[1]<b[1];
    }
    else return a[2]<b[2];
}

int maxHeight(vector<vector<int>>& cuboids) {
    int n = cuboids.size();
    //sorting individual triplets
    for(int i=0; i<n; i++){
        sort(cuboids[i].begin(), cuboids[i].end());
    }
    //sorting whole vector according to the smallest side.
    sort(cuboids.begin(), cuboids.end(), comparator);

    for(auto a: cuboids){
        for(auto i: a) cout<<i<<" ";
        cout<<endl;
    }

    //applying LIS to the middle side.
    return solve(cuboids, n);

    
}

//D) space optimization 2 - just one row.
int solve(vector<vector<int>>& cuboids, int n){

    vector<int> currRow(n+1, 0);

    //start from the next of base case
    for(int curr=n-1; curr>=0; curr--){
        for(int prev=-1; prev<n; prev++){
            int include = 0;
            //include
            if(prev==-1 ||  (  cuboids[curr][1]>=cuboids[prev][1] && cuboids[curr][2]>=cuboids[prev][2]) ){
                include = cuboids[curr][2] + currRow[curr+1];
            }

            //exclude
            int exclude = 0+currRow[prev+1];

            currRow[prev+1] = max(include, exclude);
        }
    }

    return currRow[0];



}


static bool comparator(vector<int>& a, vector<int>& b){
    if(a[0]!=b[0]) return a[0]<b[0];
    else if (a[1]!=b[1]){
        return a[1]<b[1];
    }
    else return a[2]<b[2];
}

int maxHeight(vector<vector<int>>& cuboids) {
    int n = cuboids.size();
    //sorting individual triplets
    for(int i=0; i<n; i++){
        sort(cuboids[i].begin(), cuboids[i].end());
    }
    //sorting whole vector according to the smallest side.
    sort(cuboids.begin(), cuboids.end(), comparator);

    for(auto a: cuboids){
        for(auto i: a) cout<<i<<" ";
        cout<<endl;
    }

    //applying LIS to the middle side.
    return solve(cuboids, n);

    
}