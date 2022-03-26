// bubble sort
// in this also we have multiple rounds
// har round mein shuru se har consecutive elements ko compare krke swap karte karte aage badho
// har round ke saath sbse bada element apni position pr lagta jayega
// har round ke andar wale iteration bas n-i tak he chalani padegi(just an optimization waise bhi chl he jaayega)
// so total n-1 rounds chlenge
// "Use case" -  "i"th round mein "i"th element ko uske right place pe pahaucha dete hai

// time complpexity :O(n^2)
// space comlpexity: O(1)

#include<iostream>

using namespace std;

void swap(int &a, int & b){
    int temp = a;
    a=b;
    b=temp;
}

void printArr(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

// Optimization : 
/*
Agar kisi round mein pata chle ki koi swaps he nhi hue to mtlb array sort he ho gaya hai'
so, ab break the loop and save extra iterations.
So is case mein best case time complexity O(n) ho gayi
*/

void bubbleSort_optimized(int arr[], int n){
    int isSwapped= 0;
    for(int i = 0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwapped = 1;
            }
        }
        if(isSwapped == 0) break;
    }
}

int main(){
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printArr(arr, n);
    bubbleSort_optimized(arr, n);
    printArr(arr, n);
    return 0;
}