#include<iostream>

using namespace std;
void print_arr(int arr[], int n){
    for(auto i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void insertion_sort_rec(int arr[], int n, int i){
    // base case
    if(i>n-1) return;
    
    // ek case ke liye solve kar diya
    int temp = arr[i];
    int j = i-1;
    while(j>=0){
        if(arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }else 
            break;
    }
    arr[j+1] = temp;
    // recursive call
    insertion_sort_rec(arr, n, i+1);
}


int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    int *arr= new int[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Before sort: ";
    print_arr(arr, n);

    int i = 1;
    insertion_sort_rec(arr, n, i);

    cout<<"After sort: ";
    print_arr(arr, n);

    return 0;
}