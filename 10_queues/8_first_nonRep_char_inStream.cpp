// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

/*here we need to print the first non - repeating character from the input stream as soon as characters come one
by one.
*/

/*
Approach: 

    we will make a queue and a hash map.
    queue will be used to see into the front (for the first non - repeating charaacter)
    while hash map will be used to store the number of occurances of the characters 

    steps :
    - store the incoming character in the queue and increase the map entry for it.
    - since we donot want repeating characters in out output so remove all the characters having more than one 
    occurance using a while loop.
    - now if the stack is empty insert # in output otherwise insert q.front() in the output.
*/





#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;

string FirstNonRepeating(string A){
    // Code here
    int n = A.size();
    string str;
    queue<char> q;
    map<char, int> store;
    
    for(auto i: A){
        store[i]++;
        q.push(i);
        
        while( !q.empty() && store[q.front()]>1){ //ye not empty wali condition pe dhyan dia karo har baar galat kr rhe ho
            q.pop();
        }
        
        if(q.empty()) str.push_back('#');
        else str.push_back(q.front());
        
    }
    return str;
}

int main(){

    string in = "abca";

    string out = FirstNonRepeating(in);

    cout<<out;

    return 0;
}