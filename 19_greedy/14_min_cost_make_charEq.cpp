// https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/description/

//very good greedy problem, try to do first then see the wrong submission (first one in leetcode).


#include <iostream>
#include <string>
using namespace std;
class Solution {
public:

    long long minimumCost(string s) {
        int n = s.length();

        if(n==1) return 0;

        long long cost = 0;

        for(int i=1; i<n; i++){

            if(s[i]!=s[i-1]){
                if(i< n-i){
                    cost+= i;
                }
                else{
                    cost+=(n-i);
                }
            }

        }

        return cost;


    }
};
