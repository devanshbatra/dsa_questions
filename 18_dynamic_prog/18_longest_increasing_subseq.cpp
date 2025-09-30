// https://leetcode.com/problems/longest-increasing-subsequence/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//recursion logic: har node pe sochenge ki isko include kare ya na kare.
// include karte time ek condition rahegi bas ki wo prev se strictly greater hona chahiye.
// aur end mein include aur exclude ke max ko return kar denge.
// isme prev initially -1 rahega so dp array mein choda indexing mein change hoga.

//after doing this do: 
// https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/

//recursion + memoization.
int solve(vector<int>& nums, int n, int index, int prev, vector<vector<int>> & dp){
    //base case
    if(index==n) return 0;
    if(dp[index][prev+1]!=-1) return dp[index][prev+1];
    //rc
    //include
    //if prev forming strict increase
    int include = 0;
    if( prev==-1 || nums[index]>nums[prev]){
        include = 1+solve(nums, n, index+1, index, dp);
    }
    //warna include 0 he rahega, aur exclude wala lag jaayega

    //not take.
    int notInclude = 0 + solve(nums, n, index+1, prev, dp);

    return dp[index][prev+1] = max(include, notInclude); //we would have to change the prev here as hum -1 ko bhi leke chal rhe hai. so -1 se n-1 tak jaa rhe hai. prev+1 laga do.
}


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1)); //[index][prev] //prev -1 to n-1 jaayega so, n+1 elements lie hain.
    return solve(nums, n, 0, -1, dp);
}
//tc: O(n^square). space: O(N^square).


//B)bottom up approach
int solve(vector<int>& nums, int n){


    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));//[index][prevIndex].

    //analyze base case
    //for each index=n make dp = 0;
    for(int i=0; i<=n; i++){
        dp[n][i] = 0;
    }

    //start from the next of base case
    for(int index = n-1; index>=0; index--){
        for(int prev = -1; prev<n; prev++){

            //ISME KYOKI PREV -1 BHI HO SAKTA HAI ISLIYE SAB JAGAH SECOND INDEX KO +1 KAR DENGE AS WE ARE MAPPING
            // PREV=-1 WITH ITS INDEX 0, 
            
            int include = 0;
            if( prev==-1 || nums[index]>nums[prev]){
                include = 1+dp[index+1][index+1];
            }
            //warna include 0 he rahega, aur exclude wala lag jaayega

            //not take.
            int notInclude = 0 + dp[index+1][prev+1];

            dp[index][prev+1] = max(include, notInclude);
        }
    }

    return dp[0][0];
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    return solve(nums, n);
}

//c) space optimization : we can just make use of two rows at a time.
int solve(vector<int>& nums, int n){

    //we just need two rows curr and prev
    vector<int> currRow(n+1);
    vector<int> nextRow(n+1, 0);

    for(int index = n-1; index>=0; index--){
        for(int prev = -1; prev<n; prev++){
            
            int include = 0;
            if( prev==-1 || nums[index]>nums[prev]){
                include = 1+nextRow[index+1];
            }
            //warna include 0 he rahega, aur exclude wala lag jaayega

            //not take.
            int notInclude = 0 + nextRow[prev+1];

            currRow[prev+1] = max(include, notInclude);
        }
        nextRow = currRow;
    }
    
    return nextRow[0];

}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    return solve(nums, n);
} 

//tc: O(n square)
//sc: O(n).

//D) space optimized 2.
// we can also do it using just one row and replacing the curr value with the old value.
// and since we are moving from -1 to n(left to right ) and using the righter part of array so no old value new value problem would 
// arise.

int solve(vector<int>& nums, int n){

    //we just need two rows curr and prev
    vector<int> currRow(n+1, 0);

    for(int index = n-1; index>=0; index--){
        for(int prev = -1; prev<n; prev++){
            
            int include = 0;
            if( prev==-1 || nums[index]>nums[prev]){
                include = 1+currRow[index+1];
            }
            //warna include 0 he rahega, aur exclude wala lag jaayega

            //not take.
            int notInclude = 0 + currRow[prev+1];

            currRow[prev+1] = max(include, notInclude);
        }
    }
    
    return currRow[0];

}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    return solve(nums, n);
}


//IMPORTANT
//most optimal solution. DP with binary search (waise iss method mein dp use ho nhi rhi hai.)
// see this approch first: 5, 8, 3, 7, 9, 1.
// we take [5] then 8 greater than 5.
// [5,8] then 3 not greater so put in another array.
// [3][5, 8] now 7 - not greater than 8 but greater than 3.
// [3, 7][5, 8] now 9- greater than 8
// [3, 7][5, 8, 9] now 1 - neither greater than 9 and nor 7, so new array.
// [1][3, 7][5, 8, 9]. now the longest subsequence formed is 3 sized.

// BUT there is a problem in above approach we are dealing with multiple vectors which consumes a lot space.
// if we deal with only one array like:
// 5, 8, 3, 7, 9, 1.
// 5 came so [5].
// 8 came so [5, 8].
// 3 came and not greater than 8 now find the place of 3 in this array find the next greater element of 3.
// and replace 3 with it.
// it becomes [3, 8].
// 7 comes so array becomes [3, 7].
// 9 comes array becomes [3, 7, 9].
// 1 comes array becomes [1, 7, 9].
// Here the ans comes the length of this array. i.e. 3.
// now here the order of the subsequence may not be preserved but we have no interest in that.
// THIS TECHNIQUE IS CALL DP USING binary search.
// as binary search would be used to find the next greater element.

//binary search funct utility.
void getNextGreaterElement(int s, int e, vector<int>& arr, int &ans, int key){
    if(s>e) return;

    int mid = s+(e-s)/2;
    if(arr[mid]>=key){
        //go to left
        ans = mid;
        getNextGreaterElement(s, mid-1, arr, ans, key);
    }else{
        //go to right
        getNextGreaterElement(mid+1, e, arr, ans, key);
    }

}

void solve(vector<int>& nums, int n, int index, vector<int>&seq){
    //base case
    if(index==n) return;

    //rc
    //include directly
    if(seq.size()==0 || nums[index]>seq[seq.size()-1]){
        seq.push_back(nums[index]);
    }
    else{
        int nextIndex;
        getNextGreaterElement(0, seq.size()-1, seq, nextIndex, nums[index]);
        seq[nextIndex] = nums[index];
    }
    solve(nums, n, index+1, seq);
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> seq;
    solve(nums, nums.size(), 0, seq);
    return seq.size();
}

//Time complexity: O(n) for traversing the nums * O(log(n)) for binary search at each traversal.
// tc: O(nlogn).
// sc: O(n) worst case.+ O(n) recursive call stack(wo toh hat bhi sakta hai by doing it iteratively.)