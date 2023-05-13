#include<iostream>
#include <queue>
#include <limits.h>

using namespace std;

// https://www.codingninjas.com/codestudio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTab=0
// also available on gfg.
    
/*
approach 1 would be to find max and min of each window complexity will be O(n*k)

approach 2: we will use a deque, like we have done in the ques where we had to find the first neg. number 
            in the window of size k.
            similarly here we will maintain two deques - one for storing max elements in decreasing order
            so that q.front() could give the value of the maximum element and same for minimum.
            First we will set up the window for first k elements
            then we will make a loop from k to n-1 to slide that window.

            time complexity : O(n)
            space complexity: O(k)
*/

void printq(deque<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop_front();
    }cout<<endl;
}

int findMaxSum(int arr[], int n, int k){

    deque<int> q1; //q1 will store elements of a window in decreasing order(will not contain unrelevant elements.) and will tell about the greatest element in the window .
    deque<int> q2; //q2 will store elements of a window in increasing order(will not contain unrelevant elements.) and will tell about the smallest element in the window.

    //making first window
    int sum=0;
    //addition of elements of first window.
    for(int i=0; i<k; i++){
        //removal(pop_back of all elements smaller than arr[i])
        while(!q1.empty()&& arr[i]>arr[q1.back()]){
            q1.pop_back();
        }
        q1.push_back(i);


        while(!q2.empty()&& arr[i]<arr[q2.back()]){
            q2.pop_back();
        }
        q2.push_back(i);
    }

    sum+=arr[q1.front()]+arr[q2.front()];   

    // printq(q1); 
    

    //now sliding the window
    for(int i=k; i<n; i++){
        //removal
        while(!q1.empty() && i-q1.front()>=k){
            q1.pop_front();
        }
        while(!q2.empty() && i-q2.front()>=k){
            q2.pop_front();
        }

        //addition
        while(!q1.empty()&& arr[i]>arr[q1.back()]){
            q1.pop_back();
        }
        q1.push_back(i);


        while(!q2.empty()&& arr[i]<arr[q2.back()]){
            q2.pop_back();
        }
        q2.push_back(i);

        // cout<<arr[q2.front()]<<endl;

        // update sum
        sum+=arr[q1.front()]+arr[q2.front()];


    }


    return sum;
}

int main(){

    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int ans = findMaxSum(arr, 7, k);
    cout<<ans;

    return 0;
}


