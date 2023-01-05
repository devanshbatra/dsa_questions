// https://leetcode.com/problems/reducing-dishes/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//recursion logic: 
// firstly sort the satisfaction as lower ones with lower index and higher ones will get higher indexes.
// now at every index there are two option whether to include this dish or exclude this .
// take a variable count which track how many nodes have been already taken before so as to calculate like-time coeff at curr.
// get value from both the ans and return the max of them + this node ka value if included
// include rc: this node coeff + solve(i+1, count+1). 
// exclude rc: 0+ solve(i+1, count).


//dp logic: since there are two changing variables been used so it is 2d dp.

//A) recursion + memoization
int solve(vector<int>& satisfaction, int n, int index, int count, vector<vector<int>>& dp){
    //base case
    if(index==n) return 0;

    if(dp[index][count] != -1) return dp[index][count];

    //rc
    int include = (count*satisfaction[index]) + solve(satisfaction, n, index+1, count+1, dp);
    int exclude = 0 + solve(satisfaction, n, index+1, count, dp);

    return dp[index][count] = max(include, exclude);

}

int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); // n+1 because count 1 se n tak jaayega.
    //dp structure [index][count]
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, n, 0, 1, dp);
}
//tc: O(N^square).
// sc: O(N^square). for recursive call + O(N^sq) for dp

//B) tabulation.- bottom up approach.
int solve(vector<int>& satisfaction, int n){

    //1) make dp vector
    vector<vector<int>> dp(n+1, vector<int>(n+2, 0)); //[index][count]. //n+2 because 1 to n to hoga
    //  he(n+1 hogaya ) and further wo dp[index+1][count+1] ko chk kr rha h so ek extra rakhna padega
    //  0 initial ke saath.

    //2) analyze base case
    //kitna bhi count ho if index==n put it zero.
    for(int i=1; i<=n; i++){
        dp[n][i] = 0;
    }


    //3) start building soln from the next of base case.
    for(int index=n-1; index>=0; index--){
        for(int count=1; count<=n; count++){
            int include = (count*satisfaction[index]) + dp[index+1][count+1];
            int exclude = 0 + dp[index+1][count];
            dp[index][count] = max(include, exclude);
        }
    }

    return dp[0][1];

}

int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, n);
}
//tc: O(N^square).
// sc: O(N^sq) for dp

//C) space optimized approach
// we can see that our dp[index][count] just depends on two things dp[i+1][count] and dp[i+1][count+1]
// so we can just use two rows of size n+2.
int solve(vector<int>& satisfaction, int n){

    vector<int> curr(n+2);
    vector<int> prev(n+2, 0);


    for(int index=n-1; index>=0; index--){
        for(int count=1; count<=n; count++){
            int include = (count*satisfaction[index]) + prev[count+1];
            int exclude = 0 + prev[count];
            curr[count] = max(include, exclude);
        }
        prev = curr;
    }

    return prev[1];


}

int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, n);
}
//tc: same, sc: O(N).

//SPACE OPTIMIZATION 2: making it in just one array, instead of two.(same as the LAST CASE OF KNAPSACK)
// curr: X X X X X X X        prev: X X X X X X X
//           ^                        ^ ^
// CURR[count] depends on prev[count] AND prev[count+1] and we are moving from left to right.
// so, we can just make it into one array curr.
// and curr[count] will depend on curr[count](previously) and curr[count+1] and we would update curr[count] only.
// and since we are moving from left to right so there will be no problem of old value and new value like was 
// there in knapsack as hamara wala aage ke array pe depend kar raha hai.
int solve(vector<int>& satisfaction, int n){

    vector<int> curr(n+2, 0);


    for(int index=n-1; index>=0; index--){
        for(int count=1; count<=n; count++){
            int include = (count*satisfaction[index]) + curr[count+1];
            int exclude = 0 + curr[count];
            curr[count] = max(include, exclude);
        }
    }

    return curr[1];


}

int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, n);
}


//SPACE OPTIMIZATION 3: USING GREEDY.
// we can do that thing in just O(1) space.
// given here.
// https://leetcode.com/problems/reducing-dishes/solutions/564524/c-0-ms-beats-100-all-solutions-in-both-time-and-space-with-proper-explaination/?orderBy=most_votes