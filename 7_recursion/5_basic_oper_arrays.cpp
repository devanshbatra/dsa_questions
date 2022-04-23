// basic operations on arrays
#include <iostream>
#include <string>
using namespace std;

bool checkSort(int arr[], int size){

    //base cases
    if(size<2) return true;

    if(arr[0]>arr[1]) return false;

    // recursive call
    checkSort(arr+1, size-1);
}


int giveSum(int arr[], int size){

    //base case
    if(size==0) return 0;
    if(size==1) return arr[0];

    // recursive call
    return arr[0]+giveSum(arr+1, size-1);
}


int main(){
    int arr[5]= {1, 5, 8, 12, 13};
    //tell wether this array is sorted using recursion
    bool isSorted = checkSort(arr, 5);

    if(isSorted) cout<<"yes, sorted"<<endl;
    else cout<<"not sorted"<<endl;

    // now give the sum of the array using recursion.
    cout<<"The sum is : "<<giveSum(arr, 5);

    return 0;
}