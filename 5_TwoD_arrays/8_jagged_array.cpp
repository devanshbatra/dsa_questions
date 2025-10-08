// Jagged array implementation for c++. (search "gfg jagged array" on google)
// jagged array is the array in which every row has different number of elements
#include <iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;

    int *storage = new int[n]; 
    cout<<"Enter the number of elements for each row: ";
    for(int i=0; i<n; i++){
        cin>>storage[i];
    }

    // creating the main array of int stars
    int **arr = new int*[n];    

    // creating individual arrays
    for(int i= 0; i<n; i++){
        int col = storage[i];
        int *arr = new int[col];
    }

// taking inputs
    cout<<"enter the elements: ";
    for(int i=0; i<n; i++){
        cout<<"ok enter "<<i<<"th row with "<<storage[i]<<" elements: "<<endl;
        int col = storage[i];
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

// printing outputs
    for(int i=0; i<n; i++){
        for(int j=0; j<storage[i]; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}