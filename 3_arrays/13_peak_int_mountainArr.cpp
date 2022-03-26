// find peak in mountain array
#include <iostream>
#include <vector>

using namespace std;
    int findPeak(vector<int>& arr, int n, int l, int h){
        if(l<=h){
            int mid = h+ (l-h)/2;
            if(arr[mid]!=0 && arr[mid]!=n-1 ){
            //3 cases
                int left = arr[mid-1], right = arr[mid+1];
                if(arr[mid]>left && arr[mid]>right ){
                    return mid;
                }else if(arr[mid]<right){
                    l=mid+1;
                    findPeak(arr, n, l, h);
                }else if(arr[mid]>right){
                    h=mid-1;
                    findPeak(arr, n, l, h);
                }
                
            }
        }
    }
    
    int main() {
        cout<<"enter the size";
        int n;
        cin>>n;
        cout<<"Enter the array elements in mountain order : ";
        vector<int> a;
        for(int i=0; i<n; i++){
            int el;
            cin>>el;
            a.push_back(el);
        }
        int l=0, h=n-1;
        int index = findPeak(a, n, l, h);
        cout<<index;
        return 0;
        
    }

    // more simple solution is implemented here: 
    // https://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/