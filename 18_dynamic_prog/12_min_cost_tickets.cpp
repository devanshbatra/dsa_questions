// https://leetcode.com/problems/minimum-cost-for-tickets/description/

//recursion mein kewal ek day ke liye socho aur ans nikalo
//approach: ek day ke index ko lo aur uspe all three passes apply karke ans nikalo.
// ans = min(ans, cost[currPass]+solve(index+upto which the current pass will work)).
// har pass ke liye ans nikalke minimum ans ko return kar do.
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// 1) recursion+memoization
int solve(vector<int>& days, int ndays, vector<int>& costs, int index, vector<int> & dp){
    //base case
    if(index>=ndays){
        return 0;
    }
    if(dp[index]!=-1) return dp[index];
    //rc
    int ans = INT_MAX; 
    //for the given index check for all the 3 passes
    //1day pass
    ans = min(ans, costs[0]+solve(days, ndays, costs, index+1, dp));
    //7day pass
    int temp = index;
    int limit = days[index]+7-1;
    while( temp<ndays && days[temp]<=limit) temp++;
    ans = min(ans, costs[1]+solve(days, ndays, costs, temp, dp));
    //30 day pass
    temp = index;
    limit = days[index]+30-1;
    while(temp<ndays && days[temp]<=limit) temp++;
    ans = min(ans, costs[2]+solve(days, ndays, costs, temp, dp));
    return dp[index] = ans;
}


int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(days.size(), -1);
    return solve(days, days.size(), costs, 0, dp);
}

//tc: O(ndays), sc: O(ndays)- for recursive call stack + O(ndays) for 
// AND SINCE MAXIMUM Ndays could be 365 so here the time and sc: O(1).

//2) tabulation:

int solve(vector<int>& days, int ndays, vector<int>& costs){
    // bottom up approach
    vector<int> dp(ndays+1, INT_MAX);
    //1) analyze base case
    dp[ndays]=0;
    //2) start from the next of base case.
    // in top down approach we have gone from left to right but here we will along side start builing solution from right to left

    for(int i = ndays-1; i>=0; i--){
        //1day pass
        dp[i] = min(dp[i], costs[0]+dp[i+1]);
        //7day pass
        int temp = i;
        int limit = days[i]+7-1;
        while(temp<ndays && days[temp]<=limit) temp++;
        dp[i] = min(dp[i], costs[1]+dp[temp]);
        //30 day pass
        temp = i;
        limit  = days[i]+30-1;
        while(temp<ndays && days[temp]<=limit) temp++;
        dp[i] = min(dp[i], costs[2]+dp[temp]);
    }
    return dp[0];
}
int mincostTickets(vector<int>& days, vector<int>& costs) {
    return solve(days, days.size(), costs);
}

//tc: O(ndays).
//sc: O(ndays).
// AND SINCE MAXIMUM Ndays could be 365 so here the time and sc: O(1).

//SPACE OPTIMIZATION:    very IMPORTANT CONCEPT OF QUEUE IS USED IN SPACE OPTIMIZATION.
// for the space optimization we will use queue.
// we will maintain 2 queues for both 7 days pass and 30 days pass.
// when on any index we will first clear all the elements which are of more than 7 or 30 gap , from the front of the queue.
// then we will find the ans = min(ans, cost[1 or 2] + dp[q.front().index]).

//structure of queue: queue<pair<int, int>> - <day, cost till that day>


int solve(vector<int>& days, int ndays, vector<int>& costs){

    queue<pair<int, int>> pass7; //day, cost till that day
    queue<pair<int, int>> pass30;

    int ans = 0;

    for(auto day: days){

        //step1: remove the expired days from the passes.
        while(!pass7.empty() && pass7.front().first+7-1 < day) pass7.pop(); //because ham shuru se he shuruat kar rahe hain.
        while(!pass30.empty() && pass30.front().first+30-1 < day ) pass30.pop();

        //step2: push current day's cost
        pass7.push(make_pair(day, ans+costs[1]));
        pass30.push(make_pair(day, ans+costs[2]));

        //step3: update the ans, we donot know ans day se aayega ya pass7 ya pass30 se aayega.
        // ans = min(1daypass, min(7daypass, 30daypass)).
        ans = min(ans+costs[0], min(pass7.front().second, pass30.front().second));

    }
    return ans;
}


int mincostTickets(vector<int>& days, vector<int>& costs) {
    return solve(days, days.size(), costs);
}

//space complexity: O(1) as max 7 ya 30 size ki he queue ban sakti hai.