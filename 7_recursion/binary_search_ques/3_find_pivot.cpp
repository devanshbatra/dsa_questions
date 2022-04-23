
#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr, int s, int e){
    static int ans = -1;
//   base condition
    if(s>=e) return ans;
    
//   processing 
    int mid = s + (e-s)/2;
    
//   recursive call
    cout<<"start, end, mid: "<<s<<", "<<e<<", "<<mid<<endl;
    if(arr[mid]>=arr[0]) return findPivot(arr, mid+1, e);
    else {
        ans= arr[mid];
        return findPivot(arr, s, mid);
    }
    
}

int main(){

    vector<int> arr{3,4,5,1,2};
    int n = arr.size();
    int s=0, e = n-1;
    cout<<findPivot(arr, s, e);

    return 0;
}
    
