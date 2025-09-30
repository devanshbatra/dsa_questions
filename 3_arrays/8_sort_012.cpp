// sorting an array containing only 0 1 and 2
// https://leetcode.com/problems/sort-colors/
// Can be done in less than o(nlogn) which is required in normal sorting.
//can also be done with hash map or (counting approach) but hash map solutions are not accepted everywhere and counting approach requires two for loops
// Using TWO POINTER APPROACH
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printVec(vector<int> &a){
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void swap(int &a, int &b){
    int temp;
    temp = a;
    a=b;
    b=temp;
}

void sort012(vector<int> &arr){
     int i=0,j=0,n=arr.size();
     int k=n-1;
    while(i<=k){
        if(arr[i]==0){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
        else if(arr[i]==2){
            swap(arr[i],arr[k]);
            k--;
        }
        else{
            i++;
        }
    }
}






int main(){
    cout<<"enter the size";
    int n;
    cin>>n;
    cout<<"Enter the array elements: ";
    vector<int> a;
    for(int i=0; i<n; i++){
        int el;
        cin>>el;
        a.push_back(el);
    }
    printVec(a);
    sort012(a);
    printVec(a);
    return 0;
}