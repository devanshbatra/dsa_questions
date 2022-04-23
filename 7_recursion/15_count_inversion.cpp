#include<iostream>

using namespace std;

void print_arr(int arr[], int n){
    for(auto i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int merge(int arr[], int s, int e){
    int mid = s + (e-s)/2;
    int sum = 0;
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
        if(lArr[i]<=rArr[j]) arr[mainIndex++] = lArr[i++];
        else {
            arr[mainIndex++] = rArr[j++];
            sum+=mid-i;
        }
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

    return sum;

}


void merge_sort(int arr[], int s, int e, int *sum){
    // cout<<"xame here";
    // base case 
    if(s>=e) return;

    int mid = s + (e-s)/2;
    // recursive calls 
    merge_sort(arr, s, mid, sum);
    merge_sort(arr, mid+1, e, sum);
    //processing
    (*sum)+=merge(arr, s, e);
    // cout<<(*sum);
}

int main(){
    int arr[20] = {2,4,1,3,5};
    int n = 5;
    int s = 0, e = n-1;
    cout<<"before sort: ";
    print_arr(arr, n);

    int sum = 0;
    int *sumPtr = &sum;
    merge_sort(arr, s, e, sumPtr);

    cout<<"After sort: ";
    print_arr(arr, n);

    cout<<"the number of inversions is "<<sum<<endl;

    
    return 0;
}