// https://leetcode.com/problems/wildcard-matching/description/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

//intuition:
//since a * can have 0 to any string, so here there is a chance of trying all possible ways.(just an intuition).

//approach:
//start comparing both the strings, starting from i=0 and j=0;
//if both character equal increase both.
//if p has ? then also increase both.
//but if p has * ->
//now we have two options, 1) either take * as an empty string, increase j=j+1, i remains same
//2) assume we replaced the ith character with *, i=i+1, but j remains same(* pe he rhega bcoz aage bhi le sakta hai * toh).
//  in option 2 if the * want to end with just the ith character then we have the option of taking empty string in the next 
// call. hame dono options ka OR lelena hai, taaki koi bhi true aaye to true return ho jaaye.

//else na to * hai, na same h, na he ? hai. return false.

//A) top down.
bool solve(string& s, int n1, string& p, int n2, int i, int j, vector<vector<int>> &dp){
    //base case
    if(i==n1 && j==n2) return true;
    if(i<n1 && j==n2 ) return false;

    if(i==n1 && j<n2){
        //ab this is the catch we have to check if bache hue j mein sirf * he toh nhi bacha, agar aisa h toh return true.
        for(int x=j; x<n2; x++){
            if(p[x]!='*') return false;
        }
        return true;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    //rc
    bool ans;
    if(s[i]==p[j] || p[j]=='?') ans = solve(s, n1, p, n2, i+1, j+1, dp);
    else if(p[j]=='*'){
        bool emptyS = solve(s, n1, p, n2, i, j+1, dp);
        bool notEmptyS = solve(s, n1, p, n2, i+1, j, dp);
        ans =  emptyS || notEmptyS;
    }
    else ans =  false;

    return dp[i][j] = ans;
}


bool isMatch(string s, string p) {
    int n1 = s.length();
    int n2 = p.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));



    return solve(s, n1, p, n2, 0, 0, dp);
}

//B) bottom up approach
bool solve(string& s, int n1, string& p, int n2){

    //bottom up approach
    //make dp
    vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
    
    //analyze base case
    dp[n1][n2] = true;

    for(int i=n2-1; i>=0 && p[i]=='*'; i--){
        dp[n1][i] = true;
    }

    //start from the next of base case
    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            bool ans;
            if(s[i]==p[j] || p[j]=='?') ans = dp[i+1][j+1];
            else if(p[j]=='*'){
                bool emptyS =  dp[i][j+1];
                bool notEmptyS = dp[i+1][j];
                ans =  emptyS || notEmptyS;
            }
            else ans =  false;

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}


bool isMatch(string s, string p) {
    int n1 = s.length();
    int n2 = p.length();



    return solve(s, n1, p, n2);
}


//c) space optimized approach
//space optimized approach.
bool solve(string& s, int n1, string& p, int n2){
    
    //bottom up approach
    //make dp
        
    vector<bool> curr(n2+1, false);
    vector<bool> next(n2+1, false);

    //analyze base case for space optimization.
    next[n2] = true;
    
    for(int i=n2-1; i>=0 && p[i]=='*'; i--){
        next[i] = true;
    }

    //start from the next of base case
    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            bool ans;
            if(s[i]==p[j] || p[j]=='?') ans = next[j+1];
            else if(p[j]=='*'){
                bool emptyS =  curr[j+1];
                bool notEmptyS = next[j];
                ans =  emptyS || notEmptyS;
            }
            else ans =  false;

            curr[j] = ans;
        }
        next = curr;
    }

    return next[0];

}


bool isMatch(string s, string p) {
    int n1 = s.length();
    int n2 = p.length();

    return solve(s, n1, p, n2);
}
//tc: O(n*m).
//sc: O(m).