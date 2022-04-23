// perform a linear search using recursion
#include <iostream>
#include <string>
using namespace std;

bool linearSearch(int arr[], int size, int key){
    // base case
    if(size==0) return false;

    // processing
    if(arr[0]==key) return true;

    //recursive call
    return linearSearch(arr+1, size-1, key);

}

int main(){
    int arr[5]= {1, 5, 8, 12, 13};
    int key =1, size=5;

    bool found = linearSearch(arr, size, key);

    if(found) cout<<"yes present."<<endl;
    else cout<<"not present"<<endl;

    return 0;
}