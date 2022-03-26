// selection sort
// here we have rounds pf competition
// take an element, use aur uske aage ke array ka lowest element find karo aur usse replace kardo
// Now increase that element index

// space complexity - we are just declaring variables and not any dynamic arrays during algo so O(1)
// time comlpexity - n + n-1 + n-2 + .....+ 1
// n(n-1)/2 = O(n^2)

// Use case - when array size is small and we are somewhat less on memory
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

void selectionSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int minIndex = i;
        for(int j = i; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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
    selectionSort(arr, n);
    printArr(arr, n);
    return 0;
}