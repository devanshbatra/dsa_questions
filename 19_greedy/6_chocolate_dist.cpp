// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

//simply use sliding window.
long long findMinDiff(vector<long long> a, long long n, long long m){
//code
sort(a.begin(), a.end());
int s = 0;
int e = m-1;
long long mini = INT_MAX;

while(e<n){
    mini = min(a[e]-a[s], mini);
    s++;
    e++;
}
return mini;

} 