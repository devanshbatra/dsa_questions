//we have to find First negative integer in every window of size k - good question
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
#include <iostream>
#include <queue>
#include <vector>

//Naive Approach : take two nested loops take subarrays in outer loops and find first negative in each subarray
//in inner loop. O(N^2).

//queue approach: We create a Dequeue, Di of capacity k,
// that stores only useful elements of the current window of k elements.

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
                                                 
                                   
        //SLIDING WINDOW              
        //we will do this by making a window using a queue and then slide it over the array
        queue<long long int> q;
        vector<long long> ans;
        //making the window
        for(int i=0; i<K; i++){
            if(A[i]<0) q.push(i);//storing index of neg. element in queue
        }
        //store ans for first window.
        if(q.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(A[q.front()]);
        }
        

        
        //slide the window
        for(int i=K; i<N; i++){
            //removal
            if( !q.empty() && i-q.front() >=K ){ //dhyan diya karo yahan par !d.empty() wali condition bhool gaye the isliye ans nhi aa rha tha.
                q.pop();
            }
            
            //addition in queue if negative
            if(A[i]<0) q.push(i);
            

            
            //store ans
            if(q.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(A[q.front()]);
            }
        }
        
        
        return ans;                         
 }


int main(){

    long long int v[5] = {-8, 2, 3, -6, 10};
    int n= 5;
    int k = 2;

    vector<long long> ans = printFirstNegativeInteger(v, n, k);

    return 0;
}

//time complexity - O(n)
// auxiliary space complexity - O(K). - auxiliary means extra or additional





//Most optimized approach without using queue and using constant space but same time complexity
// Optimized Approach:: It is also possible to accomplish this with constant space. The idea is to
//  have a variable firstNegativeIndex to keep track of the first negative element in the k sized
//   window. At every iteration, we skip the elements which no longer fall under the current k size
//    window (firstNegativeIndex <= i – k) as well as the non-negative elements(zero or positive). 



//Now also solve 
//sort first k elements in a queue. 
//  https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/#