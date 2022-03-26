#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// add two arrays: 
// start add from last until i>=0 and j>=m where i and j were n amd m initially
// then follow the three cases: 
/*
case 1: array a is of greater length than b

case 2: array b is of greater length than a

case 3: both are of equal length and a carry remains even after both i and j are exhausted, like 999+999
*/

void print(vector<int>);

int main(){
    vector<int> a, b, ans;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    b.push_back(9);
    b.push_back(9);
    b.push_back(1);

    int i = a.size()-1, j = b.size()-1, carry=0, sum;
    while(i>=0 && j>=0){
        sum = a[i]+b[j]+carry;
        carry = sum/10;
        ans.push_back(sum%10);
        i--;
        j--;
    }

    // case 1: 
    while(i>=0){
        sum = a[i]+carry;
        carry = sum/10;
        ans.push_back(sum%10);
        i--;
    }

    // case 2: 
    while(j>=0){
        sum = b[j]+carry;
        carry = sum/10;
        ans.push_back(sum%10);
        j--;
    }

    // case 3: 
    if(carry!=0) ans.push_back(carry);

    // since ans will be ulta so reverse it
    reverse(ans.begin(), ans.end());

    print(ans);


}

void print(vector<int> a){
    int n = a.size();
    for(int i = 0; i< n; i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}