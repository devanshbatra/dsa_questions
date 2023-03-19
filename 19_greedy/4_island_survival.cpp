// https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-survive-on-island4922/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumDays(int S, int N, int M){
    if(N<M) return -1;
    
    //we need to buy s*m food.
    //and we can buy n food in one day.
    //so total days of buy is simply (s*m)/n;
    int ans;
    int totalFood = S*M;
    if(totalFood%N==0) ans = totalFood/N;
    else ans = (totalFood/N)+1;
    
    //for sundays
    //agar survival mein sundays aa rhe hn && sunday ko bhi buy karna pd rha h
    if(S>=7 && ans>(S-(S/7))) return -1;
    
    return ans;
    
}