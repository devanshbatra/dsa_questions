/*
Celebrity problem: You will be given an array of arrays.
                   this matrix represents whether a person in a party is known by another person.
see here: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

approach 1(brute force): traverse each person and now for each person find if he is known by anyone or
 anyone know him. Time Complexity: O(n^2)

approach 2 (using stack) : push all the people into the stack
            start popping 2-2 people until only one remains in the stack
            out of these 2 people, if anyone knows other then he is not celeb, forgot it , push another one.
            at last we are left with only one man - this can be potential celebrity.
            verify with taking all other people - O(n).
*/




#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int celebrity(vector<vector<int> >& M, int n) 
{
    // code here 
    //load all celebs in a stack
    stack <int> s;
    for(int i=0; i<n; i++){
        s.push(i);
    }
    
    //pop 2-2 until one remains
    while(s.size()!=1){
        int a, b;
        a = s.top();
        s.pop();
        b = s.top();
        s.pop();
        
        if(M[a][b] == 1){// a is not a celeb
            s.push(b);
        }else{ // b is not a celeb
            s.push(a);
        }
        
    }
    
    //now stack has only one element
    //let's verify if its the celebrity or not
    int potCeleb = s.top();
    bool isCeleb = true;
    for(int i=0; i<n; i++){
        int pknowsi = M[potCeleb][i];
        int iknowsp = M[i][potCeleb];
        
        if(i==potCeleb) continue;
        else if(pknowsi==1) isCeleb = false;
        else if(iknowsp==0) isCeleb = false;

        
    }
    if(isCeleb) return potCeleb;
    else return -1;
}


int main(){


    vector< vector<int>> v = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };

    int n = v.size();

    cout<<celebrity(v, n);

    return 0;
}