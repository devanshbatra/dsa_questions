#include <iostream>
#include <stack>
#include <string>

using namespace std;

// to check if the given parenthesis is valid or not using stack.

bool isValid(string s)
{
    int n = s.size();
    stack<int> store;
    for (int i = 0; i < n; i++)
    {

        // opening
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            store.push(s[i]);
        }
        else
        { // closing
            if (store.empty())
                return false;
            if ((store.top() == '{' && s[i] == '}') || (store.top() == '(' && s[i] == ')') || (store.top() == '[' && s[i] == ']'))
                store.pop();
            else
                return false;
        }
    }

    if (store.empty())
        return true;
    else
        return false;
}

int main(){

    string st = "({}){[[]])}";
    if(isValid(st)){
        cout<<"Yes it is valid"<<endl;
    }else{
        cout<<"NO it is not valid"<<endl;
    }

    return 0;
}

/*
Time complexity: O(n) , we traversed every element of the string.
SC: O(n), we are using a stack
*/