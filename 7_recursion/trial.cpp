#include<iostream>
#include<string>
#include<vector>
using namespace std;


void partition(int arr[], int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i=s+1; i<e; i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    //ab cnt jitne element pivot se chote hai.
    int pivotindex = s+cnt;
    swap(arr[pivotindex], arr[s]);

    int i= s, j=e;
    while(i<pivotindex && j>pivotindex){

        while(arr[i]<=arr[pivotindex]){
            i++;
        }
        while(arr[j]>arr[pivotindex]){
            j--;
        }

        if(i<pivotindex&& j>pivotindex){
            swap(arr[i++], arr[j++]);
        }


    }


}

void quicksort(int arr[], int s, int e){

    if(s>=e) return;

    int mid = s+ (e-s)/2;
    partition(arr, s, e);

    //rc
    quicksort(arr, s, mid);
    quicksort(arr, mid+1, e);


}



int main(){
    
    int arr[7] = {3, 1, 9, 2, 8, 0, 7};

    quicksort(arr, 0, 6);

    for(auto i: arr){
        cout<<i<<" ";
    }


    return 0;
}