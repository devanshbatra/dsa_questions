#include <iostream>
#include <stack>
using namespace std;



void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }cout<<endl;
}


int costToBal(string str){
    stack<char> s;
    int count = 0;
    for(auto i: str){
        if(i=='{') s.push(i);
        else{
            if(s.empty()){
                count++;
                s.push('{');
            }else{ //as s.top() will now be opening only
                s.pop();
            }
        }
    }

    if(s.empty()) return 0;
    else{
        int size = s.size();
        if(size%2==0) count+=(size/2);
        else return -1;//not able to convert to valid string
    }

    return count;

}



int main(){

    string str = "{";

    cout<<"The minimum cost to balance this string is: "<<costToBal(str);

    return 0;
}