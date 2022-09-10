// array intersection
// https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149?leftPanelTab=1
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//brute force
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
//     cout<<start<<endl;
    vector<int> ans;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // optimization 1
            if(arr2[j]>arr1[i]){
                break;
            }
            if(arr1[i]==arr2[j]) {
                ans.push_back(arr1[i]);
                arr2[j] = -1; //cannot map with -1 as only positive numbers are allowed
                break;
            };
            
        }
    }
    return ans;
}

// optimized 2
// This is TWO POINTER APPROACH
vector<int> findArrayIntersection2(vector<int> &arr1, int n, vector<int> &arr2, int m)
{

    
    vector<int> ans;
    int i=0,j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]) i++;
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        if(arr1[i]>arr2[j]) j++;
    }
    return ans;
}

int main(){
    return 0;
}