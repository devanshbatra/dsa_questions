//We are given with an array with distinct elements and we have to find the minimum swaps required to sort the 
//array in ascending order.
// https://practice.geeksforgeeks.org/problems/minimum-swaps/1

//approach:
//hint: 
//ulta chalo.

//what we will do is :
    //store the vector in the form of vector of pair with pair as <ele: index>
    //now we will sort that vector<pair<int,int>> acc to first element of the pair
    //now we will see if sorted[i].second == i hai ya nhi. Agar nhi h toh sabko unki original position pe pohocha denge.
    //swap kar kar ke. Once swapped, again check for ith position jab tak i ki position par original initial wala element na
	//aa jaaye.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int,int>> v;
	    
	    for(int i=0; i<n; i++){
	        v.push_back(make_pair(nums[i], i));
	    }
	    
	    sort(v.begin(), v.end());//by default first digit ke according he sort hoga.
	    
	    int ans=0;
	    
	    for(int i=0; i<n; i++){
	        if(i==v[i].second) continue;
	        else{
	            
	            swap(v[i], v[v[i].second]);
	            ans++;
	            i--; //apni sateek jagah par ek baar mein nhi aa jayega isliye dobara check karenge.
	            //check dry run of 10,19,6,3,5,7
	        }
	        
	    }
	    
        return ans;
	}

    //time complexity: O(nlogn)(sorting) + O(n) (baki operation) = O(nlogn).
    //space complexity: O(N).