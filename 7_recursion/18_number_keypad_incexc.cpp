// number keypad problem - a good problem with recursion and a touch of backtracking
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string digits, string output, vector<string>& ans, int index, string store[]){
        int n = digits.size();
        //base case
        if(index>n-1){
            ans.push_back(output);
            return;
        }

        //include the digits (ek ko include karoge toh doosre apne aap exclude ho jayenge so not
        // to write for exclusion)
        
        //now we can not include one by one as we dont know that how many alphabets are there in 
        //total for that particular index. so applying a for loop
        int number = digits[index]-'0';
        string chars = store[number];
        int charsLength = chars.size();
        for(int i=0; i<charsLength; i++){
            output.push_back(chars[i]);
            solve(digits, output, ans, index+1, store);
            //backtracking we remove a so that it does appear in other combinations
            output.pop_back();
        }


    }

int main(){
    string digits = "23";
    int index = 0;
    string output="";
    vector<string> ans;
    string store[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
    
    solve(digits, output, ans, index, store);

    //in case the digits string is empty
    // if(digits.size()==0) return ans; //ye bhi judega original code mein

    cout<<"printing the vector : "<<endl;
    for(auto i: ans){
        cout<<i<<" "<<endl;
    }
    return 0;
}