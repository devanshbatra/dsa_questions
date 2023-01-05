#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// https://practice.geeksforgeeks.org/contest/mega-job-a-thon-hiring-challenge-for-freshers/problems/#

//this problem is based on the 2 dimensional prefix sum.
//intuition: we will make rectangle of x*y and traverse it on the whole matrix.

//first we will make a 2d array and put 1 where ever we have a cordinate present.
//then we will transform this array into the 2 dimensional prefix sum.
//by applying a formula and after that every coordinate will store the sum of all the 
//ones from 0 to that coordinate (x, y).

//now we will traverse the rectangle of l*b in the 2d array and traverse.
//at each iteration we will calculate count.
//count = arr[x][y]-arr[x-k][y]-arr[x][y-k] + arr[x-k][y-k].
//will track the maximum count and return it.

//remember the graph is starting from 1.
int maximumpoints(vector<vector<int> > arr, int n, int x, int y) {
    int pref[1001][1001];
    memset(pref, 0, sizeof(pref));
    //putting 1 where we have coord
    for(int i=0; i<n; i++){
        int u = arr[i][0];
        int v = arr[i][1];
        
        pref[u][v]++;
    }
    
    //transforming into 2d prefix sum
    for(int i=1; i<=1000; i++){
        for(int j=1; j<=1000; j++){
            pref[i][j] = pref[i][j]+pref[i-1][j]+pref[i][j-1] - pref[i-1][j-1]; //- minus isliye kiya because [i-1][j-1] wala rectangle 2 baar repeat ho gaya tha.

        }
    }
    
    
    // for(int i=1; i<=10; i++){
    //     for(int j=1; j<=10; j++){
    //         cout<<pref[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    // int i=3, j=4;
    // cout<<pref[i][j]-pref[i-x][j]-pref[i][j-y]+pref[i-x][j-y]<<endl;
    int ans = 0;
    for(int i=x+1; i<=1000; i++){
        for(int j=y+1; j<=1000; j++){
            int count = pref[i][j]-pref[i-x-1][j]-pref[i][j-y-1]+pref[i-x-1][j-y-1];
            ans = max(ans, count);
        }
    }
    
    
    return ans;
    
}