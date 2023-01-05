// 1039. Minimum Score Triangulation of Polygon
//  https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//read this for more better explanation
// https://leetcode.com/problems/minimum-score-triangulation-of-polygon/solutions/286753/C++-with-picture/

//Recursion logic:
//we know that in the vertices, [s, 5, 4, 3, 7, e], start and end are always adjacent in the polygon.
// so we take SE as our base and choose the third side from a number of options available.
// so our recursive calls would be like:
// solve(s, e) = s*e*choosen + solve(s, choosen) + solve(choosen, e);
// when ever we are just left with two nodes then it is not possible to form a triangle any more so it would be our 
// base case.

//dp logic: 
// time complexity of normal recursion would be exponential.
// what we can clearly see that every time in recursion call two variables are changing every time.
// so this is a 2d dp question.


//A) recursion + memo
int solve(vector<int>& values, int s, int e, vector<vector<int>>& dp){

    //base case
    if(s+1==e) return 0;//only two remaining.

    if(dp[s][e]!=-1) return dp[s][e];

    //rc
    //traverse for all the possible third vertex apart from the s and e.
    int mini = INT_MAX;
    for(int k = s+1; k<e; k++){
        int ans = values[s]*values[e]*values[k] + solve(values, s, k, dp) + solve(values, k, e, dp);
        //update mini
        mini = min(mini, ans);
    }

    return dp[s][e] = mini;

}



int minScoreTriangulation(vector<int>& values) {

    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(values, 0, n-1, dp);
}

//time complexity: exponential. O(N^cube).//bcs ek s ka loop maanlo ek e ka loop aur(for producing their various
// combinations) aur phir ek ho jaayega k ka loop.
//space complexity: O(N^2).



//B)tabulation logic:
// in top down approach we were starting s from 0 and increasing while we were using e from n-1 and decreasing.
// since it is bottom up approach so ham s ko start krenge last point se and e ko start karenge next of base case se
// base case was when s == e+1;
// for(int s=n-1; s>=0; s--){
//     for(int e = s(ye to single point ho gaya), s+1(ye toh 2 adj point ho gye, jo ki base case tha), e = s+2(ye h nxt of base case) )
// }
int solve(vector<int>& values, int n){

    vector<vector<int>> dp(n, vector<int>(n));



    for(int i = n-1; i>=0; i--){
        for(int j = i+2; j<n; j++){
            int mini = INT_MAX;
            for(int k = i+1; k<j; k++){
                int ans = values[i]*values[j]*values[k] + dp[i][k] + dp[k][j];
                //update mini
                mini = min(mini, ans);
            }
            dp[i][j] = mini;//update the dp. bas waise he sochna hai jaise ki recursive calls mein ho raha hoga.
        }
    }
    
    return dp[0][n-1]; //top down mein initially ye he toh pass kia tha
    
}



int minScoreTriangulation(vector<int>& values) {

    int n = values.size();
    return solve(values, n);
}

//here also ncube time complexity.
// but recursive call stack space saved.


//c) space optimization : if we see here dp[i][j]  dependes on dp[i][k] and dp[k][j].
// k will traverse from i+1 to n-1, then row bhi traverse ho rhi h and column bhi traverse ho rha hai.
// so basically 2d space to lagega he.
