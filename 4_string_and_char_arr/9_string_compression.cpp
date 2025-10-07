// String compression
// https://leetcode.com/problems/string-compression/submissions/


#include <iostream>
#include <vector>
#include <string>
using namespace std;    
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i=0, ansIndex = 0;
        while(i<n){
            
            //same element dhoond lo
            int j = i+1;
            while(j<n && chars[j]==chars[i] ){
                j++;
            }
            
            //ab ya to poori traverse ho gayi 
            //ya new element mila
            
            //old char ko store kar do
            chars[ansIndex++] = chars[i];
            
            //count store karlo
            int count = j-i;
            if(count>1){
                string st = to_string(count);
                for(char ch: st)
                    chars[ansIndex++] = ch;
            }
            
            //for new element i ki starting j se kardo
            i=j;
            
            
        }
        return ansIndex;
    }
};