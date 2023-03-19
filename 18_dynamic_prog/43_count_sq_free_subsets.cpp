// https://leetcode.com/problems/count-the-number-of-square-free-subsets/
#define mod 1000000007
#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

//This question is a mixture of """dp and bit-masking""".
    
//basic understanding: we are asked to find the subset which does not product to a number whose prime factors contain single prime
//twice.
//since we have nums[i]<=30 so, we just need to look for the prime decomposition of upto 30 only.
//here what we will do is take every number from nums start from starting of primes(0 to 30) and start modulus
//if modulus == 0 , means divisible, count++ and number/=prime. in this way we will get to know about the prime factors of this
//number.
//if (count>=2) reject this number abhi se he.
//else store the info of the prime factors in BIT MASK and push all the bitmasks for all possible numbers in an array.


//now what we have:
//we have and array of all the possible bit masks (10 bits). eg: 0100100110 means [29,23,19,17,13,11,7,5,3,2] it has 3,5,13 and 23 as
//its prime factors.

//now we have to get a subset such that koi bhi prime number 2 baar na aa jaaye.
//so if we OR two bit masks , then there should not be no two ones coming in front of each other.(ye AND SE PATA CHAL JAYEGA), 
//because 1&1 = 1 and aisa hua to means wrong combination

int solve(vector<int>& possible, int index, int mask, vector<vector<int>>& dp){
    //base case
    if(index==possible.size()) return 1; //ek subset poora hua
    
    if(dp[index][mask]!=-1) return dp[index][mask];
    
    //rc
    //this is the method of counting successful subsets.[make dry run for [8,11,17,2,25,29,21,20,4,22].
    
    
    //not take this
    int notTake = solve(possible, index+1, mask, dp);
    
    
    //take this if possible
    int take = 0;
    if((possible[index]&mask) == 0){ //ye single bitwise mein bracket ka chakkar rhta hai iski preceedence low hoti hai.
        take = solve(possible, index+1, (mask|possible[index]), dp );
    }
    
    return dp[index][mask] = (take+notTake)%mod;
    
    
}

int squareFreeSubsets(vector<int>& nums) {
    int n=nums.size();
    
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29};
    int p = 10;
    
    vector<int> possible;
    
    for(int j=0; j<n; j++){
        int mask = 0;
        bool good = true;
        
        int ele = nums[j];
        for(int i=0; i<p; i++){
            
            int count = 0;
            int prime = primes[i];
            while(ele%prime==0){
                count++;
                ele = ele/prime;
            }
            
            if(count==1){
                mask = mask | (1<<i); //important step
            }
            if(count>=2){
                good = false;
                break;
            }
            
        }
        
        if(good){
            // cout<<nums[j]<<endl;
            possible.push_back(mask);
        }
        
    }
    
    
    //now we have possible masks with us, Now do a include exclude recursive approach to find the subset having no two 1s at
    //same position.
    
    vector<vector<int>> dp(n, vector<int>(1024, -1));
    
    int ans = solve(possible, 0, 0, dp);//(possible array, index, mask)
    // cout<<"ans: "<<ans<<endl;
    return ans-1; //for the empty subset counted.
}
