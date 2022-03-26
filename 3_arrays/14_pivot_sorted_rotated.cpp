// find pivot in sorted - rotated array
#include <iostream>
#include <vector>

using namespace std;
    int findPivot(vector<int>& arr, int n, int l, int h){
        if(l<=h){
            int mid=h+(l-h)/2;
            int left = arr[mid-1], right = arr[mid+1];
            if(arr[mid]>arr[0]){ //means on first part
                l=mid+1;
                findPivot(arr, n,l,h);
            }else{
                if(arr[mid]<left){
                    return mid;
                }else{
                    h=mid-1;
                    findPivot(arr, n, l, h);
                }
            }
        }else return -1;
    }

    int findPivotSimple(vector<int>& arr, int n, int l, int h){

    }
    
    int main() {
        cout<<"enter the size";
        int n;
        cin>>n;
        cout<<"Enter the array elements in sorted/rotated order : ";
        vector<int> a;
        for(int i=0; i<n; i++){
            int el;
            cin>>el;
            a.push_back(el);
        }
        int l=0, h=n-1;
        int index = findPivot(a, n, l, h);

        // simple method
        int mid = l + (h-l)/2;
        while(l<h){
            if(a[mid]>=a[0]){
                l=mid+1;
            }else{
                h=mid;
            }
            mid = l+(h-l)/2;
        }
        cout<<"pivot by your func: "<<a[index]<<endl;
        cout<<"pivot by simp func: "<<a[l];

        return 0;
        
    }
