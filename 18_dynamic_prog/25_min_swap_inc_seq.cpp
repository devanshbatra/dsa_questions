// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//is question mein hume har element aur uske peeche wale(na ki aage wale). ko check krte hue chalna hoga.
//reason- isse kya hoga ki agar aage wale pe dependency nhi rhegi. warna ambiquity rhegi ki index ko swap kre
// ya index+1 ko.

//ab hum array ki beginning mein ek smallest number let's say -1 insert kar denge.
//reason- isse kya hoga ki 0th wala index bhi agar swap hona hoga to possible ho payega.

//har point pe ham dekhenge ki swap ho sakta h ya nhi.
//MAIN CATCH - if just peeche wale index pe swap kia tha then hum swapped values ko he use karenge.

//since two parameters are changing so it is 2d dp


//A) recursion + memoization.
int solve(vector<int>& nums1, vector<int>& nums2, int n, int index, bool swapped, vector<vector<int>> & dp){
    //base case
    if(index==n) return 0;

    if(dp[index][swapped]!=-1) return dp[index][swapped];

    //rc
    int ans = INT_MAX;
    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    if(swapped) swap(prev1, prev2);

    //check no swap
    if(nums1[index]>prev1 && nums2[index]>prev2){
        ans = min(ans, solve(nums1, nums2, n, index+1, 0, dp));
    }

    //check swap
    if(nums1[index]>prev2 && nums2[index]>prev1){
        ans = min(ans, 1+solve(nums1, nums2, n, index+1, 1, dp));
    }

    return dp[index][swapped] = ans;

}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return solve(nums1, nums2, n, 1, false, dp);
}

//TIME COMP: O(n). as swapped wala parameter toh bas 2 bar he chalega.
//space comp: O(N) + O(N).


//B) tabluation
int solve(vector<int>& nums1, vector<int>& nums2, int n){


    //make dp
    vector<vector<int>> dp(n+1, vector<int>(2, 0));


    //analyze base case
    //covered as we have initiated every thing with 0.


    //start from next of base case
    for(int index= n-1; index>=1; index--){
        for(int swapped=0; swapped<=1; swapped++){
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];

            if(swapped) swap(prev1, prev2);

            //check no swap
            if(nums1[index]>prev1 && nums2[index]>prev2){
                ans = min(ans, dp[index+1][0]);
            }

            //check swap
            if(nums1[index]>prev2 && nums2[index]>prev1){ //here is also the catch. swap tabhi hoga agar swap karne se fayda ho
                ans = min(ans, 1+dp[index+1][1]);
            }

            dp[index][swapped] = ans;
        }
    }


    return dp[1][0]; //returned at one index. as 0th to -1 he tha na.

}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    int n = nums1.size();

    return solve(nums1, nums2, n);
}

//time Comp: O(N).
//space comp: O(N).

//C)space optimization
int solve(vector<int>& nums1, vector<int>& nums2, int n){


    //space optimization 
    //we see that the current row depends on just next 1 row
    vector<int> currRow(2, 0);
    vector<int> nextRow(2, 0);


    //analyze base case
    //covered as we have initiated every thing with 0.


    //start from next of base case
    for(int index= n-1; index>=1; index--){
        for(int swapped=0; swapped<=1; swapped++){
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];

            if(swapped) swap(prev1, prev2);

            //check no swap
            if(nums1[index]>prev1 && nums2[index]>prev2){
                ans = min(ans, nextRow[0]);
            }

            //check swap
            if(nums1[index]>prev2 && nums2[index]>prev1){ //here is also the catch. swap tabhi hoga agar swap karne se fayda ho
                ans = min(ans, 1+nextRow[1]);
            }

            currRow[swapped] = ans;
        }
        nextRow = currRow;
    }


    return currRow[0]; 

}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    int n = nums1.size();

    return solve(nums1, nums2, n);
}

//Timecomp: O(N).
//space comp: O(1).