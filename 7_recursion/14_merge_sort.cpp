#include<iostream>

using namespace std;
void print_arr(int arr[], int n){
    for(auto i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void merge(int arr[], int s, int e){
    int mid = s + (e-s)/2;
    //forming two arrays
    int len1 = mid-s+1;
    int len2 = e - mid;
    int* lArr = new int[len1];
    int* rArr = new int[len2];

    // copying values
    int k = s;
    for(int i=0; i<len1; i++){
        lArr[i] = arr[k++];
    }

    k = mid+1;
    for(int i=0; i<len2; i++){
        rArr[i] = arr[k++];
    }

    //merge the sorted arrays
    int i = 0, j=0, mainIndex=s;
    while(i<len1 && j<len2 ){
        if(lArr[i]<rArr[j]) arr[mainIndex++] = lArr[i++];
        else arr[mainIndex++] = rArr[j++];
    }

    while(i<len1){
        arr[mainIndex++] = lArr[i++];
    }
    while(j<len2){
        arr[mainIndex++] = rArr[j++];
    }

    // free the dynamic memory
    delete [] lArr;
    delete [] rArr;

}

void merge_sort(int arr[], int s, int e){
    //base case
    if(s>=e) return;

    //recursive calls
    int mid = s + (e-s)/2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid+1, e);

    //processing to merge the arrays 
    merge(arr, s, e);
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

    int s = 0, e = n-1;
    merge_sort(arr, s, e);

    cout<<"After sort: ";
    print_arr(arr, n);

    return 0;
}