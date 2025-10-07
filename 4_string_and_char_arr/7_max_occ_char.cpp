// https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1
//to find the most frequent character in a string.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printArr(vector<int> v){
    int n = v.size();
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

int main(){
    
    string s = "MmMMMMmeraaaa naam jokerrrrrrr";

    int n = s.length();
    
    vector<int> v(26, 0);

    for(int i=0; i<n; i++){
        v[tolower(s[i])-'a']+=1;
    }
    int maxIndex = 0;;
    int x = v.size();
    for(int i = 0 ; i<x; i++){
        if(v[i]>v[maxIndex]) maxIndex = i;
    }

    cout<<char(maxIndex+'a');
}