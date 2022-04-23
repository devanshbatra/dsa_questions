
#include <iostream>
#include <vector>
using namespace std;

bool isPossSoln(vector<int> arr, int mid, int m){
    int childDone = 1, sum=0, size = arr.size();
    for(int i=0; i<size; i++){
        if(sum+arr[i] <= mid ){
            sum+=arr[i];
        }else{
            childDone++;
            if(childDone>m || arr[i]>mid) return false;
            sum = arr[i];//updating sum
        }
    }
    return true;
}

int allBooks(vector<int> arr, int s, int e, int m, int ans){
    //base case
    if(s>=e) return ans;

    int mid = s + (e-s)/2;

    // recursive call
    if(isPossSoln(arr, mid, m)) {
        ans = mid;
        return allBooks(arr, s, mid-1, m, ans);
    }else
        return allBooks(arr, mid+1, e, m, ans);
}


int main(){

    vector<int> arr{5, 17, 100, 11};
    int n = arr.size();
    int pageSum = 0;
    int m = 4;
    for(auto i: arr){
        pageSum+=i;
    }
    int s=0, e=pageSum;
    int ans = -1;
    cout<<allBooks(arr, s, e, m, ans);

    return 0;
}
    
