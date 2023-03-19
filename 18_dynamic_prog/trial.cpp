#include <iostream>
#include <vector>
using namespace std;
    
    
void solve(vector<int>& arr, int n){
    
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            int pos = arr[i]*(-1);
            if(i==0 && arr[i+1]<pos ){
                arr[i] = pos;
                arr[i+1] = arr[i+1]*(-1);
            }else if(i==n-1 && arr[i-1]<pos ){
                arr[i] = pos;
                arr[i-1] = arr[i-1]*(-1);
            }else if(i!=0 && i!=n-1){
    
                int left = arr[i-1];
                int right = arr[i+1];
                
                if(pos>=left && pos>=right){
                    arr[i] = pos;
                    if(left>right) right = right*(-1);
                    else if(left<right) left = left*(-1);
                }
    
                else if(pos>left && pos<=right){
                    arr[i] = pos;
                    left = left*(-1);
                }
                else if(pos>right && pos<=left){
                    arr[i] = pos;
                    right = right*(-1);
                }   
    
            }
        }
    }
    
    int ans=0;
    for(int i=0; i<n; i++){
        ans+=arr[i];
    }
    cout<<ans<<endl;
    
}
    
    
int main(){
    
    int t;
    cin>>t;
    
    for(int x=0; x<t; x++){
        
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
    
        solve(arr, n);
    
    }
    return 0;
}