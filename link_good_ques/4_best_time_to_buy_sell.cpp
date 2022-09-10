#include<iostream>
#include<vector>
using namespace std;
//Best time to buy and sell stocks
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/



//here we can solve use brute force tle method by putting i at 0 starting j from 1 and then finding the max profit and then i++, j=i+1 again. TC would be O(n2).

//approach 2: we will take a minEle var and initialize from int_max
//also we will take a maxProfit counter and initialize from 0 (may be no profit is there in any transaction).
//now start traversing the array and whenever an element smaller than minEle is found update it and whenever any profit(prof = eleNow - minEle) greaater than maxProfit is found then update it.
//so by tracking two counters we would be able to solve this problem in O(n) time and O(1) space.
int maxProfit(vector<int>& prices) {
    int minEle = INT_MAX;
    int maxProf = 0;
    
    for(int i=0; i<prices.size(); i++){
        if(prices[i]<minEle) minEle = prices[i];
        if(prices[i]-minEle>maxProf) maxProf = prices[i]-minEle;
    }
    return maxProf;
}
