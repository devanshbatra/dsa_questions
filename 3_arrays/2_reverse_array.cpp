// i knew the method by using two arrary but optimized solution is by using just one array
// Optimized solution: 
#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}

void printArr(int a[], int size){
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void reverse(int n[], int size){
    int start = 0, end = size-1;
    while(start<end){
        swap(&n[start], &n[end]);
        start++;
        end--;
    }

}

int main(){
    int size=10;
    int n[10] = {23, 65, 12, 76, 45, 23, 9, 78, 23, 90};
    cout<<"Before reverse: ";
    printArr(n, size);
    reverse(n, size);
    cout<<"After reverse: ";
    printArr(n, size);
    return 0;
}


