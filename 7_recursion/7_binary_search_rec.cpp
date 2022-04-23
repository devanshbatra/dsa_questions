// perform a binary search using recursion
#include <iostream>
#include <string>
using namespace std;

bool binSearch(int arr[], int s, int e, int key){
    // base case
    if(s>e) return false;

    //processing
    int mid = e + (s-e)/2;

    //recursive call
    if(arr[mid] == key) return true;
    else if(arr[mid]>key)
        return binSearch(arr, s, mid-1, key);
    else 
        return binSearch(arr, mid+1, e, key);

}

int main(){
    int arr[6]= {1, 5, 8, 12, 13, 23};
    int size = 6;
    int s=0, e=size-1, key = 13;
    
    bool isFound = binSearch(arr, s, e, key);

    if(isFound) cout<<"Yes, present."<<endl;
    else cout<<"Not present"<<endl;


    return 0;
}