// You are given an array Arr of size N. You have to find the K-th largest 
//sum of contiguous subarray within the array elements.
// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//approach 1: brute force , We will create a loop i that will traverse the elements and an inner loop that will
                //traverse from i to n-1
                //this way we will create the sub arrays and store the sum in another vector.
                //tc: O(N^2).

                //once we get the sum array we will sort it and find the kth element from the end. 
                //total tc: (n^2log(n^2)) === n^2(logn).
                //sc: O(N^2)
                 




int main(){

    vector<int> arr = {3,2,1};
    int n = arr.size();
    int k = 2;
    //approach 1: brute force
    vector<int> sumArr;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum+=arr[j];
            sumArr.push_back(sum);  //andar bcoz saare lene hai
        }
    }

    sort(sumArr.begin(), sumArr.end());
    for(auto i: sumArr){
        cout<<i<<" ";
    }cout<<endl;
    cout<<sumArr[sumArr.size()-k];
    //approach 1 ends.


    //approach 2: we will use the concept of min heap to find the kth largest element.
        //          we will be forming the subarrays and finding the sum in two nested loops only
        //          but instead of storing the sums in array we will use a min heap and store only 
        //          upto k terms in that. after k terms are filled, now, what we will do is that
        //          we will apply the same logic to store the largest k elements in that heap.
        //here time complexity: O(n^2log(n)).
        //but space complexity is reduced: O(k).
        
        priority_queue<int, vector<int>, greater<int>> minheap;
        
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
                sum+=arr[j];
                
                if(minheap.size()<k){
                    minheap.push(sum);
                }else{
                    if(sum>minheap.top()){
                        minheap.pop();
                        minheap.push(sum);
                    }
                }
                
            }
        }
        
        cout<< minheap.top(); //ans
        //approach 2 ends.

        //approach 3: it would be concerned in reducing the time complexity using dynamic programming and
        //memoization.  


    return 0;
}