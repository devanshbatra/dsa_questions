// revising binary search questions using recursion
#include <iostream>
#include <string>
using namespace std;

int firstOcc(int arr[], int s, int e, int key){
    static int ans=-1;
    //base case
    if(s>e) return ans;

    // processing
    int mid = e+(s-e)/2;

    // recursive call
    if(arr[mid]==key){
        ans = mid;
        return firstOcc(arr, s, mid-1, key);
    }else if(arr[mid]>key) 
        return firstOcc(arr, s, mid-1, key);
    else 
        return firstOcc(arr, mid+1, e, key);

}
int lastOcc(int arr[], int s, int e, int key){
    static int ans2=-1;
    //base case
    if(s>e) return ans2;

    // processing
    int mid = e+(s-e)/2;

    // recursive call
    if(arr[mid]==key){
        ans2 = mid;
        return lastOcc(arr, mid+1, e, key);
    }else if(arr[mid]>key) 
        return lastOcc(arr, s, mid-1, key);
    else 
        return lastOcc(arr, mid+1, e, key);
}

// 10 10 10 10 10 10 10 10

int main(){
    int arr[18]= {10, 10, 10, 10, 10, 10, 10, 10};
    int size = 8;
    int s=0, e=size-1, key = 4;

    cout<<"The first occurance is: "<<firstOcc(arr, s, e, key)<<endl;
    cout<<"The last occurance is: "<<lastOcc(arr, s, e, key)<<endl;
    


    return 0;
}