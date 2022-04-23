#include<iostream>

using namespace std;
void print_arr(int arr[], int n){
    for(auto i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void selection_sort_rec(int arr[], int n){

    // base case
    if(n==1 || n==0 )
        return ;
    
    // 1 case ke liye solve kar diya
    int i = 0;
    int minIndex = i;
    for(int j= 1; j<n; j++){
        if(arr[j]<arr[minIndex]) minIndex = j;
    }
    swap(arr[i], arr[minIndex]);

    // recursive call
    selection_sort_rec(arr+1, n-1);
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

    selection_sort_rec(arr, n);

    cout<<"After sort: ";
    print_arr(arr, n);

    return 0;
}