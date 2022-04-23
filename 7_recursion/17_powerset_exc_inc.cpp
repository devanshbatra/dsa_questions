// to generate the power set of a given array
// here we will use recursion to use the include and exclude concept
// written in copy
// https://leetcode.com/problems/subsets/
// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=1
#include<iostream>
#include<vector>
using namespace std;

void power_set(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans){
    int n = nums.size();
    //base case
    if(index>n-1){
        ans.push_back(output);
        return;
    }
    
    //exclude
    power_set(nums, output, index+1, ans);
    
    //include
    output.push_back(nums[index]);
    power_set(nums, output, index+1, ans);
}
    

int main(){
    vector<int> nums{1,2,3};
    int index = 0;
    vector<int> output;
    vector<vector<int>> ans;

    power_set(nums, output, index, ans);

    cout<<"printing the vector : "<<endl;
    for(auto i: ans){
        cout<<"{";
        for(auto j: i){
            cout<<" "<<j<<" ";
        }cout<<"}"<<" ";
    }
        


    return 0;
}