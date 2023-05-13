//bit manip good question.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// https://leetcode.com/problems/minimum-impossible-or/
//a|b = b|a pehli cheez, kisi bhi order mein ho fark nhi padta.
//intuition: if we have 2 i.e. 10 in our array.
//then 2 has 2nd place as set bit and for OR 1|1 = 1, 1|0=1, 0|1 = 1, 0|0 = 0.
//so with 2 we can make 3 easily, by using previously checked powers of 2.

//lets say we have 4 ie. 100, now 5, 6, 7 can be easily made with 4. as we have already checked 1 and 2
//and these can easily be made with 4,1,2.

//similarly 8 can make 9,10,11,12,13,14,15.

//1, 2_, 4___, 8_______, 16__________________, 32____________________, 64_________________.
//now whenever we miss a power of 2 that means that is the answer.
//simple :-)

int minImpossibleOR(vector<int>& nums) {
    unordered_map<int, int> m;
    for(int i=0; i<nums.size(); i++){
        m[nums[i]]++;
    }
    
    //start making powers of two
    int powerVal = 1;
    int ans = 0;
    while(true){
        if(m.count(powerVal)==0){
            ans = powerVal;
            break;
        }
        
        powerVal = powerVal*2;
    }
    
    return ans;
    
}