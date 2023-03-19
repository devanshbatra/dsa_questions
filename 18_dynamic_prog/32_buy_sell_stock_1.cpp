// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//here we can solve use brute force tle method by putting i at 0 starting j from 1 and then finding the max profit and then i++, j=i+1 again. TC would be O(n2).
    
//approach 2: we will take a minEle var and initialize from int_max - I call it TWO COUNTER approach.
//consider an index i, we decide to sell i or not. (it is understood that we have bought the minimum of all until i).
//also we will take a maxProfit counter and initialize from 0 (may be no profit is there in any transaction).
//now start traversing the array and whenever an element smaller than minEle is found update it and whenever any profit(prof = eleNow - minEle) greaater than maxProfit is found then update it.
//so by tracking two counters we would be able to solve this problem in O(n) time and O(1) space.   

int maxProfit(vector<int>& prices) {
    int mini = INT_MAX;
    int maxProfit = 0;
    int n = prices.size();

    for(int i=0; i<n; i++){
        //update mini
        mini = min(mini, prices[i]);

        //update max Profit - (curr-min).
        int currProf = prices[i] - mini;
        maxProfit = max(currProf, maxProfit);
    }

    return maxProfit;
}