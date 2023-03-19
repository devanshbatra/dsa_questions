
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;
//let's think of the brute force approach
//if we start comparing the strings word by word, using index i and j
//if s[i]==t[j], go ahead no problem with it. 0 operations.
//but if (s[i]!=t[j]).
//then we have three options
//1) replace
//2) insert
//3) delete

//Now don't actually do these operations. HERE'S THE REAL CATCH.
//you just have to fake these operations by playing with the indexes and increasing the count of the operations.

//base cases:
//if target string is over: then we shall delete all the leading characters left with original string.
//if original string is over and we are still left with target, that means you may need to insert the 
//remaining character of target.

//A) topdown
int solve( string s, int n1, string t, int n2,  int i, int j, vector<vector<int>>& dp){ //i-> orig and j->target.
    //base case
    if(j==n2) return n1-i;
    if(i==n1) return n2-j; //if original string is over and we are still left with target, that means you may need to insert the 
    //remaining character of target.

    if(dp[i][j]!=-1) return dp[i][j];

    //rc
    if( s[i] == t[j] ){
        return dp[i][j] = 0 + solve(s, n1, t, n2, i+1, j+1, dp);
    }
    else{
        //three options
        int replace  = 1+solve(s, n1, t, n2, i+1, j+1, dp);
        int insert = 1 + solve(s, n1, t, n2, i, j+1, dp);
        int deletion = 1 + solve(s, n1, t, n2, i+1, j, dp);

        return dp[i][j] = min(replace, min(insert, deletion));
    }

}



int minDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();

    if(n1==0) return n2;
    if(n2==0) return n1;

    vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));

    return solve(word1, n1, word2, n2, 0, 0, dp);
}

//B) bottom up
int solve( string s, int n1, string t, int n2){ //i-> orig and j->target.

    //bottom up
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    //analyze base case and initialize dp
    for(int i=0; i<=n1; i++){
        dp[i][n2] = n1-i;
    }
    for(int j=0; j<=n2; j++){
        dp[n1][j] = n2-j;
    }

    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            
            if( s[i] == t[j] ){
                dp[i][j] = 0 + dp[i+1][j+1];
            }
            else{
                //three options
                int replace  = 1+ dp[i+1][j+1];
                int insert = 1 + dp[i][j+1];
                int deletion = 1 + dp[i+1][j];

                dp[i][j] = min(replace, min(insert, deletion));
            }
        }
    }

    return dp[0][0];

}



int minDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();

    if(n1==0) return n2;
    if(n2==0) return n1;

    return solve(word1, n1, word2, n2);
}

//C) space optimization: It has some crucial elements- explore yourself first.
int solve( string s, int n1, string t, int n2){ //i-> orig and j->target.

    //space optimization.

    vector<int> curr(n2+1, 0); //curr is initially at row n1-1
    vector<int> next(n2+1, 0); //next is at row n1

    //base cases analyzation would be changed for space optimization.
    for(int j=0; j<=n2; j++){
        next[j] = n2-j;
    }

    //for curr - ek he cell ko change karna pada.
    curr[n2] = n1-(n1-1);
    //curr ka n2 hamesha n1-i he rahega. isse humne matrix ke last column ko update kar dia. aur loop ke andar bhi update karna
    //padega.


    //start from the next of base case in reverse order
    for(int i=n1-1; i>=0; i--){
        curr[n2] = n1-i; //updated for optimization solution specially.
        for(int j=n2-1; j>=0; j--){
            


            if( s[i] == t[j] ){
                curr[j] = 0 + next[j+1];
            }
            else{
                //three options
                int replace  = 1 + next[j+1];
                int insert = 1 + curr[j+1];
                int deletion = 1 + next[j];

                curr[j] = min(replace, min(insert, deletion));
            }
        }
        next = curr;
    }

    return curr[0];

}



int minDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();

    if(n1==0) return n2;
    if(n2==0) return n1;

    return solve(word1, n1, word2, n2);
}

//space coomp: O(min(n1, n2))
//tc: O(m*n).