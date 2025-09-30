// https://codeforces.com/problemset/problem/1420/B
// You are given a positive integer n, and an array a of positive integers. 
// The task is to calculate the number of such pairs (i,j) that i<j and ai & aj≥ai⊕aj

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long findGood(vector<int>& nums, int n){

    sort(nums.begin(), nums.end());
    long long ans = 0;

    for(int i=n-1; i>=0; i--){
        
        int p = -1;
        int dig = nums[i];
        while(dig>0){
            dig = dig>>1;
            p++;
        }

        int j = i-1;
        while(j>=0 && nums[j]&(1<<p) ){
            //cout<<"i: "<<i<<" j: "<<j<<endl<<endl;
            j--;
        }
        //cout<<"out: i: "<<nums[i]<<" j: "<<nums[j]<<" P: "<<p<<endl<<endl;
        long long cnt = i-j;
        //cout<<"cnt: "<<cnt<<endl;
        ans+=((cnt*(cnt-1))/2); //matlab ki agar right most bit dono ka set h, toh & will always be greater than xor.
        i=j+1;
    }
    return ans;


}

int main(){

    int t;
    cin>>t;

    for(int x=0; x<t; x++){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int y=0; y<n; y++){
            cin>>nums[y];
        }
        cout<<findGood(nums, n)<<endl;
    }

    return 0;
}