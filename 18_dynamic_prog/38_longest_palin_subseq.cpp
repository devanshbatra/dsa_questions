// https://leetcode.com/problems/longest-palindromic-subsequence/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//approach is same as lcs.
//ek pointe l lo shuru mein ek pointer r lo last mein.
//aur jaise palindrome find out krte hn waise he chalo
//agar s[l] aur s[r] same hai to l++ and r--
//else we have two cases
//either l++
//or r--.

// A) topdown
int solve(string& s, int l, int r, vector<vector<int>> & dp){
    //base case
    if(l==r) return 1; //for the beech wala element.
    if(l>r) return 0;

    if(dp[l][r]!=-1) return dp[l][r];

    //rc
    if(s[l]==s[r]) return 2+solve(s, l+1, r-1, dp);
    else{
        //if they are not same then we have two options same as lcs- 
        //move ahead with l or move ahead with r.
        int moveL = solve(s, l+1, r, dp);
        int moveR = solve(s, l, r-1, dp);

        return dp[l][r] = max(moveL, moveR);
    }
}

int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(s, 0, n-1, dp);
}

//B) Bottom up
int solve(string& s){
    //doing for bottom up
    //during top down: left was like : 0 to n-1 & right: n-1 to 0.
    //now in bottom up : left: n-1 to 0. and right: 0 to n-1(but right should not be less than left, so right: left+1)

    //make dp
    int n = s.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    //analyze base case
    for(int i=0; i<=n; i++){
        dp[i][i] = 1;
    }

    //start from next of base case
    for(int l=n-1; l>=0; l--){
        for(int r = l+1; r<n; r++){
            if(s[l]==s[r]) dp[l][r] = 2+dp[l+1][r-1];
            else{
                //if they are not same then we have two options same as lcs- 
                //move ahead with l or move ahead with r.
                int moveL = dp[l+1][r];
                int moveR = dp[l][r-1];

                dp[l][r] = max(moveL, moveR);
            }
        }
    }

    return dp[0][n-1];
}

int longestPalindromeSubseq(string s) {
    return solve(s);
}

// C) space optimized - isme ek base case dp[i][i] = 1. ki wajah se space optimize nhi ho payega


//APPROACH 2.
//if we take a string temp which stores the reverse of the original string
//now we just have to find the longest common subsequence between temp and original.
int solve2(string& s1, string& s2, int n1, int n2){

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

int longestPalindromeSubseq2(string s) {
    
    string temp = s;
    reverse(temp.begin(), temp.end());
    int n = s.length();

    return solve2(s, temp, n, n);
}
