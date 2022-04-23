
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossSoln(vector<int> arr,int mid, int k){
    int prev = arr[0];
    int n = arr.size();
    for(int i = 1; i<n; i++){
        if(arr[i]-prev>= mid){
            k--;
            prev = arr[i];
            if(k==1) return true;
        }
    }
    return false;
}

int aggCows(vector<int> arr, int s, int e, int k, int ans){
    int mid = s + (e-s)/2;
    // base case
    if(s>e) return ans;

    //recursive call
    if(isPossSoln(arr, mid, k)){
        ans = mid;
        //go for a larger distance
        return aggCows(arr, mid+1, e, k, ans);
    } else
        return aggCows(arr, s, mid-1, k, ans);
}

int main(){

    vector<int> arr{0, 3, 4, 7, 10, 9};
    int cows = 4;
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int s= 0, e = arr[n-1], ans = -1;

    cout<<aggCows(arr, s, e, cows, ans);





    return 0;
}
    
