#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
int main(){

    vector<int> arr{6,1,4,6,3,2,7,4};
    int n = arr.size();
    int k = 3;
    int l=  2;
    int first, second;
    if(k>l){
        first = k;
        second = l;
    }else{
        first = l;
        second = k;
    }

    //first window
    int sum = 0;
    int maxSum = INT_MIN;
    int st;
    int en;
    for(int i=0; i<first; i++){
        sum+=arr[i];
    }
    
    if(sum>maxSum){
        maxSum = sum;
        st = 0;
        en = first-1;
    }

    //sliding
    int s = 0;
    int e = first-1;
    while(e<n-1){
        sum-=arr[s];
        s++;
        e++;
        sum+=arr[e];

        if(sum>maxSum){
            maxSum = sum;
            st = s;
            en = e;
        }
    }
    int totalSum = maxSum;
    for(int i=st; i<=en; i++){
        arr[i] = 0;
    }

    //second window
    maxSum = INT_MIN;
    sum = 0;
    st = -1;
    en = -1;
    for(int i=0; i<second; i++){
        sum+=arr[i];
    }
    if(sum>maxSum){
        maxSum = sum;
        st = 0;
        en = second-1;
    }
    //sliding
    s = 0;
    e = second-1;
    while(e<n-1){
        sum-=arr[s];
        s++;
        e++;
        sum+=arr[e];

        if(sum>maxSum){
            maxSum = sum;
            st = s;
            en = e;
        }
    }

    totalSum+=maxSum;
    return totalSum;
    cout<<totalSum; //return it.

    return 0;



}











int solution(vector<int> &arr, int k, int l) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n=arr.size();
    if(k+l>n) return -1;
    int first, second;
    if(k>l){
        first = k;
        second = l;
    }else{
        first = l;
        second = k;
    }

    //first window
    int sum = 0;
    int maxSum = INT_MIN;
    int st;
    int en;
    for(int i=0; i<first; i++){
        sum+=arr[i];
    }
    
    if(sum>maxSum){
        maxSum = sum;
        st = 0;
        en = first-1;
    }

    //sliding
    int s = 0;
    int e = first-1;
    while(e<n-1){
        sum-=arr[s];
        s++;
        e++;
        sum+=arr[e];

        if(sum>maxSum){
            maxSum = sum;
            st = s;
            en = e;
        }
    }
    int totalSum = maxSum;
    for(int i=st; i<=en; i++){
        arr[i] = 0;
    }

    //second window
    maxSum = INT_MIN;
    sum = 0;
    st = -1;
    en = -1;
    for(int i=0; i<second; i++){
        sum+=arr[i];
    }
    if(sum>maxSum){
        maxSum = sum;
        st = 0;
        en = second-1;
    }
    //sliding
    s = 0;
    e = second-1;
    while(e<n-1){
        sum-=arr[s];
        s++;
        e++;
        sum+=arr[e];

        if(sum>maxSum){
            maxSum = sum;
            st = s;
            en = e;
        }
    }

    totalSum+=maxSum;
    return totalSum;
}

