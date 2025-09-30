// find pivot in sorted - rotated array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include <iostream>
#include <vector>

using namespace std;
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
        int mid = l + (h-l)/2;
        int ans = -1;
        // simple method - best method 100% accurate - recursion se ye possible nhi ho paya 
        if(a[l]<=a[h])  ans = a[l];
        while(l<=h){
            if(a[mid]>a[0]){
                l=mid+1;
            }else{
                if(a[mid]<a[mid-1]){
                    ans = a[mid];
                    break;
                }else{
                    h=mid-1;
                }
            }
            mid = h + (l-h)/2;
        }
        // cout<<"pivot by your func: "<<a[index]<<endl;
        cout<<"pivot by simp func: "<<ans;

        return 0;
        
    }
