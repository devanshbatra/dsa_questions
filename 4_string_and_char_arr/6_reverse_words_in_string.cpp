
// https://leetcode.com/problems/reverse-words-in-a-string/description/
// Given an input string s, reverse the order of the words.
/*
Input: s = "the sky is blue"
Output: "blue is sky the"
*/

#include <iostream>
#include <string>
using namespace std;

//1. Using extra space. Space complexity: O(n)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        int i = n-1;
        string ans = "";
        while(i>=0){
            while(i>=0 && s[i]==' ') i--;
            
            if(i>=0 && ans.length()) ans = ans+" ";

            int j = i;
            while(i>=0 && s[i]!=' ') i--;
            // cout<<"i: "<<i<<", j: "<<j<<" substr: "<<s.substr(i+1, j-i)<<endl;
            ans = ans + s.substr(i+1, j-i);
        }

        return ans;

    }
};


//2. Doing in-place. Without utilising extra space. Possible only if string is mutable. SC: O(1).
class Solution {
public:

    void reverseString(string& s, int i, int j){
        while(i<j){
            swap(s[i++], s[j--]);
        }
    }

    string reverseWords(string s) {
        int i = 0;

        while(i<s.length()){ //using s.length() as string is changing size.
            int j = i;
            while(i<s.length() && s[i]==' ') i++;
            // cout<<"i: "<<i<<", j: "<<j<<endl;
            if(j!=i){
                s.replace(j, i-j, " ");
                // cout<<">"<<s<<"<"<<endl;
                i-=(i-j-1);
            }

            while(i<s.length() && s[i]!=' ') i++;
        }

        if(s[0]==' ') s.erase(0, 1);
        if(s[s.length()-1]==' ') s.erase(s.length()-1, 1);

        //reversing whole string.
        reverseString(s, 0, s.length()-1);
        
        //reversing individual words
        int n = s.length();
        i=0;
        while(i<n){
            int j = i;
            while(i<n && s[i]!=' ') i++;

            reverseString(s, j, i-1);
            if(j==i) i++;

        }

        return s;

    }
};

