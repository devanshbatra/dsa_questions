// swap the alternate elements
// arr = {1, 2, 3, 4, 5, 6}
// swapped arr = {2, 1, 4, 3, 6, 5}
#include<iostream>

using namespace std;

void printArr(int a[], int size){
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void swap(int* a, int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

// it uses extra variables
// void makeSwapAlt(int arr[], int size){
//     int a=0, b=1;
//     if(size>1){
//         while(b<=size){
//             swap(&arr[a], &arr[b]);
//             a+=2;
//             b+=2;
//         }
//     } 
// }

// without extra variables 
void makeSwapAlt(int arr[], int size){
    for(int i=0; i<size; i+=2){
        if(i+1<=size){
            swap(arr[i], arr[i+1]);
        }
    }
}

int main(){
    int arr[7] = {12, 34, 32, 0, 54, 6, 7};
    int size=7;
    cout<<"Array before swapping: ";
    printArr(arr, size);
    makeSwapAlt(arr, size);
    cout<<"Array after swapping: ";
    printArr(arr, size);
    return 0;
}