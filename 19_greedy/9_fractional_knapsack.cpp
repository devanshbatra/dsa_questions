// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//Function to get the maximum total value in the knapsack.
    
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};

static bool comparator(Item a, Item b){
    double ratio1 = double(a.value)/double(a.weight);
    double ratio2 = double(b.value)/double(b.weight);
    return ratio1>ratio2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    
    vector<Item> store;
    for(int i=0; i<n; i++){
        store.push_back(arr[i]);
    }
    
    sort(store.begin(), store.end(), comparator);
    
    double ans = 0;
    
    int i=0;
    
    while(i<n && W >= store[i].weight){
        W-=store[i].weight;
        ans+=store[i].value;
        i++;
    }
    
    if(i==n) return ans; //agar pehle he khatam ho gaya puri capacity ki zarorat he na pdi.
    
    if(W>0){
        ans+= store[i].value * double(W)/double(store[i].weight);
    }
    
    return ans;
    
}