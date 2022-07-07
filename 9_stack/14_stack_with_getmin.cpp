#include<iostream>
#include<stack>

using namespace std;

/*
Design a stack that supports getMin() in O(1) time and O(1) extra space.
https://www.codingninjas.com/codestudio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?leftPanelTab=0
approach 1 : (with tc: O(1) but sc: O(n)) we will maintain a stack named min which will be initialized with INT_MAX
            when we push we compare data with min.top() , if data is small then min.push(data)

            when we pop we will se if s.top() is equal to min.top(), if yes go with min.pop() for the next
            stored smaller element.

            all other stack operations will be same. 

            {babbar soln. is little bit different for this complexity: he update the min stack everytime
            updates with same min element if data> min.top()
            updates with data if data<min.top().
            and also pops from both everytime}

code:
class SpecialStack {
    // Define the data members.
    stack<int> min;
    stack<int> s;
    public:
    
    SpecialStack(){
        min.push(1000000000);
    }
    
    void push(int data) {
        // Implement the push() function.
        if(data<min.top()) min.push(data);
        s.push(data);
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty()) return -1;
        
        if(s.top()==min.top()){
            min.pop();
        }
        int temp = s.top();
        s.pop();
        return temp;
    }

    int top() {
        // Implement the top() function.
        if(s.empty()) return -1;
        return s.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(s.empty()) return true;
        else return false;
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()) return -1;
        
        return min.top();
    }  
};

this approach uses O(n) space complexity which is not allowed.
*/

/*
Approach 2: Taking O(1) extra space

here we will use only a variable named mini.
when ever any element is pushed which is greater than mini , then no problem push it. min remains same.
when an element smaller than mini comes than we push a value = 2*ele-mini. and set mini as 
element(which was smaller).

for pop when an element greater than mini is popped then no problem pop it normally.
but when an element smaller than mini is on the top (to be popped) , then it means it was modified with the 
formula now , new mini  = 2*mini-currTop. and pop the element and return popped element as mini.
*/

/*
Code for approach 2: 
#include<stack>
class SpecialStack {
    // Define the data members.
    int min;
    stack<int> s;
    public:
        
    void push(int data) {
        // Implement the push() function.
        if(s.empty()){
            s.push(data);
            min = data;
        }
        else if(data<min){ //min se bhi chotta aa gaya toh we need to reset min.
            //to store prevmin we combine prevmin with data.
            int value = 2*data - min;
            s.push(value);
            min = data;
        }
        else{//koi dikkat nahi hai, push normally
            s.push(data);
        }
    }

    int pop() {
        //underflow cond.
        if(s.empty()) return -1;
        int curr = s.top();
        if(curr<min){
            //now newmin will be calculated by- newmin = 2*min-curr.
            int prevmini = min;
            min = 2*min-curr;
            s.pop();
            return prevmini;//kyoki wo element he to tha ab tak ka minimum
        }else{
            s.pop();
            return curr;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()) return -1;
        
        int curr = s.top();
        if(curr<min){
            return min; //agar min se chota hai to value = 2*curr-min karke aaya hoga aur min mein curr put karte the
        }else{
            return curr;
        }
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(s.empty()) return true;
        else return false;
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()) return -1;
        
        return min;
    }  
};
*/