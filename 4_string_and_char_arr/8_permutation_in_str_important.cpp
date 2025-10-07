// permutation in strings
// https://leetcode.com/problems/permutation-in-string/
// uses sliding window concept and storing character count in arr of 26 wala concept
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private: 
    
    // void printArr(vector<int> a){
    //     for(int i=0; i<26; i++){
    //         cout<<a[i]<<" ";
    //     }cout<<endl;
    // }

    
    bool checkEqual(vector<int> a, vector<int> b){
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    
public:
    bool checkInclusion(string str1, string str2) {
        
        if(str1.length()>str2.length()) return false;
        
        // s1 count array
        vector<int> count1(26, 0);
        int w = str1.length();
        for(int i = 0; i<w; i++){
            count1[str1[i]-'a']++;
        }
        
        // printArr(count1);

        //     now traverse s2 by window of size s1.length()
        int n = str2.length();
        vector<int> count2(26, 0);
        int i=0;
//         checking for first window
        for(i=0; i<w; i++){
            count2[str2[i]-'a']+=1;
        }
        // cout<<"Checking 1st time count2: ";
        // printArr(count2);
        if(checkEqual(count1, count2)) return true;
        
        while(i<n){
            int newIndex = str2[i]-'a';
            int oldIndex = str2[i-w]-'a';
            count2[newIndex]++;
            count2[oldIndex]--;
            // printArr(count2);
            i++;
            if(checkEqual(count1, count2)) return true;
        }
        
        
        return false;
        }
};