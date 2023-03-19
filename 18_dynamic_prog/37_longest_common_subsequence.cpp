// https://leetcode.com/problems/longest-common-subsequence/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//simply put two pointers on both the string at start and start comparing them
//if same increase ans and move on.
//if not same then we have two options- either increase i or increase j.
//try both and return the one with which we get maximum ans.

//A) top down.

int solve(string& s1, string& s2, int n1, int n2, int i, int j, vector<vector<int>>& dp){
//base case
if(i>=n1 || j>=n2) return 0;

if(dp[i][j]!=-1) return dp[i][j];


//rc
if(s1[i]==s2[j]){
    return 1+ solve(s1, s2, n1, n2, i+1, j+1, dp);
}
else{
    //now we have two options- either move s1 forward or move s2 forward
    int s1Forward = solve(s1, s2, n1, n2, i+1, j, dp);
    int s2Forward = solve(s1, s2, n1, n2, i, j+1, dp);
    return dp[i][j] = max(s1Forward, s2Forward);
}
}

int longestCommonSubsequence(string text1, string text2) {
int n1 = text1.length();
int n2 = text2.length();

vector<vector<int>> dp(n1, vector<int>(n2, -1));

return solve(text1, text2, n1, n2, 0, 0, dp);
}

//T.c: O(n1*n2).
//sc: O(n1*n2).

//B) bottom up
int solve(string& s1, string& s2, int n1, int n2){

    //make dp
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    //analyze base case- covered

    //start from next of base case
    //in top down i and j went from 0 to n1, n2.
    //now from n-1 to 0

    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            if(s1[i]==s2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                //now we have two options- either move s1 forward or move s2 forward
                int s1Forward = dp[i+1][j];
                int s2Forward = dp[i][j+1];
                dp[i][j] = max(s1Forward, s2Forward);
            }
        }
    }

    return dp[0][0];

}

int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.length();
    int n2 = text2.length();


    return solve(text1, text2, n1, n2);
}

//C) space optimized.
int solve(string& s1, string& s2, int n1, int n2){

    //make dp
    vector<int> currRow(n2+1, 0);
    vector<int> nextRow(n2+1, 0);

    //analyze base case- covered

    //start from next of base case
    //in top down i and j went from 0 to n1, n2.
    //now from n-1 to 0

    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            if(s1[i]==s2[j]){
                currRow[j] = 1 + nextRow[j+1];
            }
            else{
                //now we have two options- either move s1 forward or move s2 forward
                int s1Forward = nextRow[j];
                int s2Forward = currRow[j+1];
                currRow[j] = max(s1Forward, s2Forward);
            }
        }
        nextRow = currRow;
    }

    return currRow[0];

}

int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.length();
    int n2 = text2.length();


    return solve(text1, text2, n1, n2);
}

//sc reduced to O(min(n1, n2)).