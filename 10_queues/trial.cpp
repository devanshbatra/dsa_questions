#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void solve(vector<int>& arr, int n){

    int l = 0; 
    int h = 0;
    int maxSub = 1;

    int anslow = l;
    int anshigh = h;

    while(h<n-1){
        if(arr[h+1]>=arr[h]){
            h++;
        }
        else{
            if(h-l+1 > maxSub){
                maxSub = h-l+1;
                anslow = l+1;
                anshigh = h+1;
            }

            h++;
            l = h;
        }
    }

    //for last iteration
    if(h-l+1 > maxSub){
        maxSub = h-l+1;
        anslow = l+1;
        anshigh = h+1;
    }

    cout<<anslow<<" "<<anshigh<<endl;


}


int main(){

    int t;
    cin>>t;

    for(int x=0; x<t; x++){
        int n;
        cin>>n;
        vector<int> original;
        vector<int> sorted;

        for(int i=0; i<n; i++){
            int ele;
            cin>>ele;
            original.push_back(ele);
        }
        for(int i=0; i<n; i++){
            int ele; 
            cin>>ele;
            sorted.push_back(ele);
        }

        solve(sorted, n);

    }
    
}