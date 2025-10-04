// find all the uniwue elements in the array. That don't have duplicates.
#include<iostream>

using namespace std;

// my method
void findUnique(int arr[], int n){
    for(int i=0; i<n; i++){
        int key=arr[i], flag=0;
        for(int j = 0; j<n; j++){
            if(arr[j]==key && i!=j){
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"element "<<arr[i]<<" at index "<<i<<" is unique"<<endl;

    }
} //O(n square)


// alternate method - when only ONE unique element is present
// when we xor two same elements we get 0
// 5^5  = 0
// and xor with 0 gives the same number
// so if we xor all the elements, then we will be able to get the one unique element
void unique_other_method(int arr[], int n){
    int ans=0;
    for(int i =0; i<n; i++){
        ans = ans ^ arr[i];
    }
    cout<<ans<<" is unique"<<endl;
}


int main(){
    int arr[10] = {12, 12, 32, 0, 0, 6, 6, 2, 4, 4};
    int size=10;
    findUnique(arr, size);

    int arr2[5] = {2,3,2,4,4};
    int size2 = 5;
    unique_other_method(arr2, size2);
    return 0;
}