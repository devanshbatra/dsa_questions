#include <iostream>
#include <vector>
using namespace std;
// Painters partition problem - https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

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
    int blSum=0, i=0;
    while(m>0 && i<n ){
        blSum=0;
        while(i<n){
            if(blSum+a[i] <= mid ){
                blSum+=a[i];
                i++;
            }else{
                m--;
                break;
            }
        }
    }
    if(i==n) return true;
    else return false;
} 

int binarySearchAlgo(vector<int> a, int n, int sum, int m){
    int l=0, h=sum;
    int mid = l + (h-l)/2, ans=-1;
    while(l<=h){
        if(isPossibleSol_another(a, n, m, mid)){
            // go for smaller - left
            ans = mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
        mid = l + (h - l) / 2;
    }
    return ans;
}



int main()
{
    cout << "Enter the number of boards: " << endl;
    int n;
    cin >> n;
    cout << "Enter the board lengths: " << endl;
    vector<int> boards;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        boards.push_back(el);
    }
    int m;
    cout << "Enter the number of painters: ";
    cin >> m;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += boards[i];
    }

    cout<<binarySearchAlgo(boards, n, sum, m);
    return 0;
}