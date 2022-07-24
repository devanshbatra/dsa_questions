// https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTab=0

//we have to interleave two halves
/*
This can be easily done using queue but gfg has a ques which has a condition to use stack as an auxiliary ds.

*/

//queue solution
/*
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    queue<int> q1;
    int n = q.size()/2;
    for(int i=0;i<n;i++){
        q1.push(q.front());
        q.pop();
    }
    
    for(int i=0; i<n; i++){
        q.push(q1.front());
        q.push(q.front());
        q.pop();
        q1.pop();
    }
    
  
*/

//stack solution
/*
void interLeaveQueue(queue < int > & q) {
    // compulsurily using stack
    stack<int> s;
    //basically we need to store the items in stack in reverse order to make it work
    //like a queue
    //steps
    //move first half to the stack
    int n = q.size()/2;
    for(int i=0; i<n; i++){
        s.push(q.front());
        q.pop();
    }
    
    //push back all the elements of the stack to the queue.
    for(int i=0; i<n; i++){
        q.push(s.top());
        s.pop();
    }
    
    //now the 2nd half has become first half, make it second half again
    for(int i=0; i<n; i++){
        q.push(q.front());
        q.pop();
    }
    
    //again push first half in the stack , this time it will be in reverse order
    for(int i=0; i<n; i++){
        s.push(q.front());
        q.pop();
    }
    
    //now do the same thing the we used to do using queue
    for(int i=0; i<n; i++){
        q.push(s.top());
        q.push(q.front());
        s.pop();
        q.pop();
    }
    
}

Time complexity: O(n/2) ===> O(n)
Space complexity: O(n/2) ===> O(n)
*/