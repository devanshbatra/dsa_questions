#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> arr{41,78,12,64,5,5,32,7};

    sort(arr.begin(), arr.end());
    
    int i=0;
    for(;i<arr.size()-1;i++){
        if(arr[i]==arr[i+1]) cout<<"found duplicate : "<<arr[i];
    }

    return 0;
}