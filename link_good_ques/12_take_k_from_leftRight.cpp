// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/
// This question is a combination of sliding window and binary search.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//we have to take out characters from both the sides.
//now let's say "_ _ _ ->_<- _ _ _ _ _ _ _." this is the string and I take all characters uptil arrow-ptr
//from left side and no character i.e. (0) from right side.

//now check from index (0 to arrow-ptr), about the freq of a, b, c and see if they satisfy the condition
//[freq[a]>=k && freq[b]>=k && freq[c]>=k].
//if yes then well and good see for a smaller soln(i.e. move arrow-ptr to arr-ptr-1).
//if no- NOW WE WILL DO A DIFFERENT KIND OF SLIDING WINDOW.
// here the window will move in reverse where we will delete the arrow's character and
// add the last character of the string in the window.
// like so we will move the window like we are moving in a circular string anticlock-wise.

//now we would have to check the min ans. by moving the arrow-cnt from n to 0. (overall).
//at every arrow position we will do sliding window.

//Binary search introduced-now it will be of high complexity if we do by moving arrow from n to 0 in a linear manner.
// so we have optimized it with binary search.

//utility function to check the frequency condition.
bool satisfy(vector<int>& freq, int k){
    if(freq[0]>=k && freq[1]>=k && freq[2]>=k) return true;
    else return false;
}
//sliding window function.
bool isValid(string s, int k, int ptr){
    vector<int> freq(3, 0);

    //prepare the first window
    for(int i=0; i<ptr; i++){
        freq[s[i]-'a']++;
    }
    if(satisfy(freq, k)) return true;

    //slide the window.
    int size = s.length();
    int left = ptr-1;
    int right = size-1;

    while(left>=0){
        freq[s[left]-'a']--;
        freq[s[right]-'a']++;
        if(satisfy(freq, k)) return true;
        left--;
        right--;
    }

    // if after sliding the whole window also true is not returned, so return false.
    return false;

}

int takeCharacters(string s, int k) {
    
    int start = 0;
    int end = s.length();
    int ans = INT_MAX;
    while(start<=end){
        int mid = start+(end-start)/2;

        if(isValid(s, k, mid)){
            ans = min(ans, mid);
            //move to left for smaller ans
            end = mid-1;
        }else{
            //ans not found so move to bigger index
            start = mid+1;
        }

    }

    if(ans==INT_MAX) ans = -1; //that means no validity found uptill now.

    return ans;

}