// https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=1
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// to find first and last occurance of the array
#include<iostream>
#include<vector>
#include<string>

using namespace std;


// given by babbar- without recursion (abhi padhaya nhi)
// int firstOccAlgo(vector<int> &arr,int n, int k, int l, int h){
//     int ans=-1;//to return -1 if not found
//     while(l<=h){
//         int mid = h + (l-h)/2;
//         if(arr[mid]== k){
//             // simply store ans and goto left subarray
//             ans = mid;
//             h = mid-1;
            
//         }else if(arr[mid]>k){
//             h=mid-1;
//         }else{
//             l=mid+1;
//         }
//     }
// }




// more optimized by me
int firstOccAlgo(vector<int> &arr,int n, int k, int l, int h){
    if(l<=h){
        int mid = h + (l-h)/2;
        if(arr[mid]== k){
            //2 cases
            if(arr[mid-1]==k && mid!=0 ){
                h=mid-1;
            	firstOccAlgo(arr,n,k, l, h);
            }else return mid;
        }else if(arr[mid]>k){
            h=mid-1;
            firstOccAlgo(arr,n,k, l, h);
        }else{
            l=mid+1;
            firstOccAlgo(arr,n, k, l, h);
        }
    }else{
        return -1;
    }
}
int lastOccAlgo(vector<int> &arr, int n, int k, int l, int h){
    if(l<=h){
        int mid = h + (l-h)/2;
        if(arr[mid]== k){
            //2 cases
            if(arr[mid+1]==k && mid!=n-1 ){
                l=mid+1;
            	lastOccAlgo(arr,n,k, l, h);
            }else return mid;
        }else if(arr[mid]>k){
            h=mid-1;
            lastOccAlgo(arr,n,k, l, h);
        }else{
            l=mid+1;
            lastOccAlgo(arr,n, k, l, h);
        }
    }else{
        return -1;
    }
}


int main(){ 
    cout<<"enter the size";
    int n;
    cin>>n;
    cout<<"Enter the array elements in increasing order : ";
    vector<int> a;
    for(int i=0; i<n; i++){
        int el;
        cin>>el;
        a.push_back(el);
    }
    cout<<"Enter the element to be searched: ";
    int key;
    cin>>key;

    int l=0, h=n-1;

    int first = firstOccAlgo(a,n, key, l, h);
    int last = lastOccAlgo(a,n, key, l, h);

    cout<<"first: "<<first<<" last: "<<last<<endl;

    return 0;
}