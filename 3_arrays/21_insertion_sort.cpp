// learn by the example of sorting the cards
// jo jo number aata jaa rha hai usse pichle saaro se compare karte hue arrange krdo

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

void insertion_sort(int arr[], int n){
    for(int i = 1; i<n; i++){ //pehla card toh pata he kahan daalu so initializing i with 1
        int temp = arr[i], j = i-1;
        while(j>=0){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
                j--;
            }else{
                break;
            }
        }
        arr[j+1] = temp;
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
    insertion_sort(arr, n);
    printArr(arr, n);
    return 0;
}

// Use case: It is an adaptable algorithm - things start getting sorted from the very start.
// It is stable
// also used with small sized arrays

// Time complexity
// O(n^2)
// Best case: already sorted, har bar base ek he comparison karana padega
// so n-1 comparisons he honge so, O(n)

// worst case: O(n^2)

// space complexity: O(1)