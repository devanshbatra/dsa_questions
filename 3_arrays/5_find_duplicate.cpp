// find all the duplicate elements in the array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/submissions/637848607/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//brute force method
void findDuplicate(int arr[], int n){
    for(int i=0; i<n; i++){
        int key=arr[i], flag=0;
        for(int j = 0; j<n; j++){
            if(arr[j]==key && i!=j){
                flag=1;
                break;
            }
        }
        if(flag==1) cout<<"element "<<arr[i]<<" at index "<<i<<" have a duplicate"<<endl;

    }
}

// optimized with sorting
vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]) ans.push_back(nums[i]);
        }
        return ans;
    }



// if the problem is like this: 
// You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.
// here
// we have number from 1...X.n-1 and an extra X
// if we xor the whole array with 1....n-1 we would get X
void findOneDuplicate(vector<int> &a){
    int ans=0;
    for(int i=0; i<a.size(); i++){
        ans = ans ^ a[i];
    }
    for(int i=1; i<=a.size()-1; i++){
        ans = ans ^ i;
    }
    cout<<"The duplicate is : "<<ans<<endl;
}



int main(){
    int arr[10] = {12, 12, 32, 0, 0, 6, 6, 2, 4, 4};
    int size=10;
    findDuplicate(arr, size);

    vector<int> a;
    cout<<"Enter the size: "<<endl;
    int n;
    cin>>n;
    cout<<"enter n elements with just one duplicate: "<<endl;
    for(int i=0; i<n; i++){
        int el;
        cin>>el;
        a.push_back(el);
    }

    for(int i=0;i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    findOneDuplicate(a);
    return 0;
}