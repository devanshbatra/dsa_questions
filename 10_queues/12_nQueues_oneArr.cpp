#include <iostream>
//we have to implement n queues efficiently in an array.
// https://www.codingninjas.com/codestudio/problems/n-queue-using-array_1170053?leftPanelTab=1
using namespace std;
class NQueue{
public:
    int n,s;
    int * arr;
    int * front;
    int * rear;
    int * next;
    int freespot;
    // Initialize your data structure.
    NQueue(int n, int s){
        // Write your code here.
        this->n = n;
        this->s = s;
        arr = new int[s];
        front = new int[n];
        rear = new int[n];
        next = new int[s];
        freespot = 0;
        
        //initializing front and rear
        for(int i=0; i<n; i++){
            front[i] = rear[i] = -1;
        }
        
        //initializing next
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;
        

    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        //check overflow
        if(freespot==-1) return false;
        
        //find index
        int index = freespot;
        
        //insert into array
        arr[index] = x;
        
        //update freespot
        freespot = next[index];
        
        if(front[m-1]==-1) front[m-1] = index; //warna front to wahi rhega hamesha push mein
        else//LINK NEW ELEMENT TO THE PREVIOUS ELEMENT 
        {   //PEHLE TO NEXT ARRAY KA ROLE YAAD KARO - AB KONSA ELEMENT POP KARNA HAI( YE BATATA HAI NEXT ELEMENT )
            //update next - next ab ye batayega ki ab is element ke baad next pop kise karna hai
            //stack mein next[index] mein top daal dete the.
            //but yahan par next pop ham uss element ko karenge jo baad mein aayega iske 
            //iss element ke baad kya aayega ye to pata nhi 
            // so we shall update ki ye index kiske baad aaya h? - rear ke baad aaya hai.
            //so we write next[rear[m]] = index;
            //jo pehle rear tha uska next = index;
            next[rear[m-1]] = index;
            
        }
        
        //ab jo hamara index pe element aaya hai, wo abhi ke liye last element hai
        //aur queue main ham front se pop krte krte left to right jaate hai.
        //so last index ke baad koi element nahi bachta pop krne ko,so :-
        next[index] = -1;
        //update rear
        rear[m-1] = index;
        
        return true;
        
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        
        //checking underflow'
        if(front[m-1]==-1){
            return -1;
        }
        
        //we have to pop from front so,
        int index = front[m-1];
        
        //next element of this queue will be stored in next[], so point front to this
//         if(front[m-1] == rear[m-1]) rear[m-1] = -1;
        front[m-1] = next[index];
        
        //update next - changed functionaly (now points to freespot).
        next[index]= freespot;
        
        //now this index will become a freespot
        freespot = index;
        
        return arr[index];
    }
};


int main(){

    NQueue q(3, 10);
    bool l;
    l= q.enqueue(23, 1);
    l= q.enqueue(2, 1);
    l= q.enqueue(4, 2);
    l= q.enqueue(12, 1);

    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;

    return 0;
}