#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

//after doing this problem, try this: https://leetcode.com/problems/minimum-time-to-repair-cars/description/

bool isPossibleSol(vector<int> a, int n, int m, int mid){
    int blSum=0, painterCount = 1;
    for(int i=0; i<n; i++){
        if(blSum + a[i] <= mid ){
            blSum+=a[i];
        }else{
            painterCount++;
            if(painterCount>m || a[i]>mid){
                return false;
            }
            blSum = a[i];
        }
    }
    return true;
}


bool isPossibleSol_another(vector<int> a, int n, int m, int mid){
    int i=1, prev = a[0];
    while(i<n){
        if(a[i]-prev < mid){
            i++;
        }else{
            m--;
            prev = a[i];
            i++;
            if(m==1) return true;
        }
    }
    return false;
    
} 

int binarySearchAlgo(vector<int> a, int n, int max, int m){
    int l=0, h=max;
    int mid = l + (h-l)/2, ans=-1;
    while(l<=h){
        cout<<"Mid: "<<mid<<endl;
        if(isPossibleSol_another(a, n, m, mid)){
            // go for a larger value
            cout<<"Possible for mid: "<<mid<<endl;
            ans = mid;
            l=mid+1;
        }else{
            // go for a smaller value
            h=mid-1;
        }
        mid = l + (h-l)/2;
    }
    return ans;
}   



int main()
{
    cout << "Enter the number of stalls: " << endl;
    int n;
    cin >> n;
    cout << "Enter the position of stalls: " << endl;
    vector<int> stalls;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        stalls.push_back(el);
    }
    int m;
    cout << "Enter the number of cows: ";
    cin >> m;

    
    sort(stalls.begin(), stalls.end());
    int max = stalls[n-1];
    cout<<binarySearchAlgo(stalls, n, max, m);
    // cout<<isPossibleSol_another(stalls, n, m, 2);
    return 0;
}