// painters partition problem solved using recursion approach
// https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557
#include <iostream>
#include <vector>
using namespace std;

bool isPossSoln(vector<int> arr,int n, int mid, int k){
    int sum=0, painterCount=0;
    for(int i=0; i<n; i++){
        if(sum+arr[i]<=mid){
            sum+=arr[i];
        }else{
            painterCount++;
            if(painterCount>=k || arr[i]>mid){
                return false;
            }
            sum = arr[i];
        }
    }
    return true;
}


int partition_painter(vector <int> arr,int n, int s, int e, int k, int ans){
    int mid = s + (e-s)/2;
    // base case
    if(s>e) return ans;

    // recursive call
    if(isPossSoln(arr, n, mid, k)){ //if it is possible then we have to optimize it by minimizing
        ans = mid;
        return partition_painter(arr, n, s, mid-1, k, ans);
    }else{
        return partition_painter(arr, n, mid+1, e, k, ans);
    }
}


int main(){

    vector<int> arr{48, 90};
    int n = arr.size();
    int totalArea = 0;
    int painters = 2;
    for(auto i: arr){
        totalArea+=i;
    }
    int s = 0, e = totalArea-1, ans = -1;

    cout<<partition_painter(arr, n, s, e, painters, ans)<<endl;



    return 0;
}
    
