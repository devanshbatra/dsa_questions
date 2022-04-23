#include<iostream>

using namespace std;
void print_arr(int arr[], int n){
    for(auto i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}


// using inner and outer recursion
void bubble_rec_inner(int arr[], int n, int i, int j){
    //base case
    if(j>=n-i) return ;

    //processing
    if(arr[j]<arr[j-1]){
        swap(arr[j], arr[j-1]);
    }

    // recursive call
    bubble_rec_inner(arr, n, i, j+1);
}

void bubble_rec_outer(int arr[], int n, int i){
    // base
    if(i==n-1) return;

    // processing
    int j = 1;
    bubble_rec_inner(arr, n, i, j);

    // recursive call
    bubble_rec_outer(arr, n, i+1);

}


// using a simple method
void bubble_simple(int arr[], int n){
    //base case
    if(n<2) return;

    // 1 case ke liye solve kar liya
    for(int i=1; i<n; i++){
        if(arr[i]<arr[i-1]) swap(arr[i], arr[i-1]);
    }

    // recursive call
    bubble_simple(arr, n-1);
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

    // int i=0;
    // bubble_rec_outer(arr, n, i);

    // cout<<"After sort: ";
    // print_arr(arr, n);

    bubble_simple(arr, n);
    cout<<"After sort: ";
    print_arr(arr, n);
    


    return 0;
}